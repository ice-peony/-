#include <iostream>
using namespace std;
#include <fstream>
#include <string>
#include "globalFile.h"
#include "Identity.h"
#include "student.h"
#include "teacher.h"
#include "manager.h"

void LoginIn(string filename, int type); //����һ�������ļ����ƣ��������������������
void managerMenu(Identity*& manager);
void studentMenu(Identity*& student);
void teacherMenu(Identity*& teacher);

int main()
{
	int select;
	while (1)
	{ 
		cout << "****************** ��ӭ����������Ļ���ԤԼϵͳ ********************" << endl;
		cout << endl << "�������������" << endl;
		cout << "\t\t---------------------------------\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|        1.ѧ������             |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|        2.��    ʦ             |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|        3.�� �� Ա             |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|        0.��    ��             |\n";
		cout << "\t\t---------------------------------\n";
		cout << "��������ѡ��";
		cin >> select; // �����û���ѡ��

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
				cout << "��ӭ�´�ʹ��" << endl;
				system("pause");
				exit(0);
				//return 0;
				break;
			default:
				cout << "��������������ѡ��" << endl;
				system("pause");
				system("cls");
				break;
		}
	
	}

	system("pause");
			
	return 0;
}

//��¼����
void LoginIn(string filename, int type)
{
	Identity* person = NULL;  //���ö�̬��ԭ���ø����ָ�봴���������

	ifstream ifs;
	ifs.open(filename, ios::in);

	//�ļ����������
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		ifs.close();
		return;	
	}
	
	//׼�������û���Ϣ 
	int id = 0;
	string name;
	string pwd;

	if (type == 1) //ѧ����¼
	{
		cout << "���������ѧ��" <<endl;
		cin >> id;
	}
	else if (type == 2) //��ʦ��¼
	{
		cout << "���������ְ����" << endl;
		cin >> id;
	}
	
	cout << "�������û�����" << endl;
	cin >> name;
	cout << "���������룺" << endl;
	cin >> pwd;

	if (type == 1)
	{
		//ѧ����¼��֤
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >>fName && ifs >> fPwd)   //�����ո�Ͷ���һ������һ�е���Ϣ���������ȡ
		{
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "ѧ����֤��¼�ɹ���" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				//����ѧ����ݵ��Ӳ˵�
				studentMenu(person);
				return;
			}
		}
	}
	else if (type == 2)
	{
		//��ʦ��¼��֤
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)   //�����ո�Ͷ���һ������һ�е���Ϣ���������ȡ
		{
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "��ʦ��֤��¼�ɹ���" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				//�����ʦ��ݵ��Ӳ˵�
				teacherMenu(person);
				return;
			}
		}
	}
	else if (type == 3)
	{
		//����Ա��¼��֤
		string fName;
		string fPwd;
		while (ifs >> fName && ifs >> fPwd)   //�����ո�Ͷ���һ������һ�е���Ϣ���������ȡ
		{
			if (fName == name && fPwd == pwd)
			{
				cout << "����Ա��֤��¼�ɹ���" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				//�������Ա��ݵ��Ӳ˵�
				managerMenu(person);
				return;
			}
		}
	}
	cout << "��֤��¼ʧ��!" << endl;

	system("pause");
	system("cls");
	return;
}

//����Ա�˵�
void managerMenu(Identity*& manager)
{
	while (1)
	{
		//����Ա�˵�
		manager->openMenu(); //��̬

		Manager* man = (Manager*)manager; //����ָ��ǿתΪ����ָ��
		int select = 0;	

		cin >> select;
		if (select == 1)
		{
			cout << "����˺�" << endl;
			man->addPerson();
		}
		else if (select == 2)
		{
			cout << "�鿴�˺�" << endl;
			man->showPerson();
		}
		else if (select == 3)
		{
			cout << "�鿴����" << endl;
			man->showComputer();
		}
		else if (select == 4)
		{
			cout << "���ԤԼ" << endl;
			man->cleanFlie();
		}
		else
		{
			delete manager;  //֮ǰ������new�ķ�ʽ�����ڶ���
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//ѧ���˵�
void studentMenu(Identity*& student)
{
	while (true)
	{
		student->openMenu();
		Student* stu = (Student*)student;
		int select = 0;
		cin >> select;

		if (select == 1) //����ԤԼ
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
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//��ʦ�˵�
void teacherMenu(Identity*& teacher)
{
	while (true)
	{
		teacher->openMenu();
		Teacher* tea = (Teacher*)teacher;
		int select = 0;
		cin >> select;
		
		if (select == 1)
			//�鿴����ԤԼ
			tea->showAllOrder();
		else if (select == 2)
			//���ԤԼ
			tea->vaildOrder();
		else
		{
			delete teacher;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}