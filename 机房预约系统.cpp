#include <iostream>
using namespace std;
#include <fstream>
#include <string>
#include "globalFile.h"
#include "Identity.h"
#include "student.h"
#include "teacher.h"
#include "manager.h"

void LoginIn(string filename, int type); //参数一：操作文件名称；参数二：操作身份类型
void managerMenu(Identity*& manager);
void studentMenu(Identity*& student);
void teacherMenu(Identity*& teacher);

int main()
{
	int select;
	while (1)
	{ 
		cout << "****************** 欢迎来到刘朋滨的机房预约系统 ********************" << endl;
		cout << endl << "请输入您的身份" << endl;
		cout << "\t\t---------------------------------\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|        1.学生代表             |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|        2.老    师             |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|        3.管 理 员             |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|        0.退    出             |\n";
		cout << "\t\t---------------------------------\n";
		cout << "输入您的选择：";
		cin >> select; // 接受用户的选择

		switch (select)
		{
			case 1:
				LoginIn(STUDENT_FILE, 1);
				break;
			case 2:
				LoginIn(TEACHER_FILE, 2);
				break;
			case 3:
				LoginIn(ADMIN_FILE, 3);
				break;
			case 0:
				cout << "欢迎下次使用" << endl;
				system("pause");
				exit(0);
				//return 0;
				break;
			default:
				cout << "输入有误，请重新选项" << endl;
				system("pause");
				system("cls");
				break;
		}
	
	}

	system("pause");
			
	return 0;
}

//登录功能
void LoginIn(string filename, int type)
{
	Identity* person = NULL;  //利用多态的原理，用父类的指针创建子类对象

	ifstream ifs;
	ifs.open(filename, ios::in);

	//文件不存在情况
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		ifs.close();
		return;	
	}
	
	//准备接受用户信息 
	int id = 0;
	string name;
	string pwd;

	if (type == 1) //学生登录
	{
		cout << "请输入你的学号" <<endl;
		cin >> id;
	}
	else if (type == 2) //教师登录
	{
		cout << "请输入你的职工号" << endl;
		cin >> id;
	}
	
	cout << "请输入用户名：" << endl;
	cin >> name;
	cout << "请输入密码：" << endl;
	cin >> pwd;

	if (type == 1)
	{
		//学生登录验证
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >>fName && ifs >> fPwd)   //碰到空格就读下一个，把一行的信息拆成三个读取
		{
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "学生验证登录成功！" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				//进入学生身份的子菜单
				studentMenu(person);
				return;
			}
		}
	}
	else if (type == 2)
	{
		//教师登录验证
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)   //碰到空格就读下一个，把一行的信息拆成三个读取
		{
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "教师验证登录成功！" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				//进入教师身份的子菜单
				teacherMenu(person);
				return;
			}
		}
	}
	else if (type == 3)
	{
		//管理员登录验证
		string fName;
		string fPwd;
		while (ifs >> fName && ifs >> fPwd)   //碰到空格就读下一个，把一行的信息拆成三个读取
		{
			if (fName == name && fPwd == pwd)
			{
				cout << "管理员验证登录成功！" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				//进入管理员身份的子菜单
				managerMenu(person);
				return;
			}
		}
	}
	cout << "验证登录失败!" << endl;

	system("pause");
	system("cls");
	return;
}

//管理员菜单
void managerMenu(Identity*& manager)
{
	while (1)
	{
		//管理员菜单
		manager->openMenu(); //多态

		Manager* man = (Manager*)manager; //父类指针强转为子类指针
		int select = 0;	

		cin >> select;
		if (select == 1)
		{
			cout << "添加账号" << endl;
			man->addPerson();
		}
		else if (select == 2)
		{
			cout << "查看账号" << endl;
			man->showPerson();
		}
		else if (select == 3)
		{
			cout << "查看机房" << endl;
			man->showComputer();
		}
		else if (select == 4)
		{
			cout << "清空预约" << endl;
			man->cleanFlie();
		}
		else
		{
			delete manager;  //之前就是用new的方式创建在堆区
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//学生菜单
void studentMenu(Identity*& student)
{
	while (true)
	{
		student->openMenu();
		Student* stu = (Student*)student;
		int select = 0;
		cin >> select;

		if (select == 1) //申请预约
			stu->applyOrder();
		else if (select == 2)
			stu->showMyOrder();
		else if (select == 3)
			stu->showAllOrder();
		else if (select == 4)
			stu->cancelOrder();
		else
		{
			delete student;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//教师菜单
void teacherMenu(Identity*& teacher)
{
	while (true)
	{
		teacher->openMenu();
		Teacher* tea = (Teacher*)teacher;
		int select = 0;
		cin >> select;
		
		if (select == 1)
			//查看所有预约
			tea->showAllOrder();
		else if (select == 2)
			//审核预约
			tea->vaildOrder();
		else
		{
			delete teacher;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}