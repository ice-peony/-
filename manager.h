#pragma once
#include <iostream>
using namespace std;
#include "Identity.h"
#include "globalFile.h"
#include <fstream>
#include <vector>
#include "student.h"
#include "teacher.h"
#include <algorithm>
#include "computerRoom.h"


//管理员类
class Manager :public Identity
{
public:
	//默认构造
	Manager();

	//有参构造
	Manager(string name, string pwd);
	
	//菜单界面
	virtual void openMenu();

	//添加账号
	void addPerson();

	//查看账号
	void showPerson();

	//查看机房信息
	void showComputer();

	//清空预约记录
	void cleanFlie();

	//初始化容器
	void initVector();

	//学生容器
	vector<Student> vStu;

	//老师容器
	vector<Teacher> vTea;

	//检测重复参数;(传入id，传入类型) 返回值：（ture 代表有重复，false代表没有重复）
	bool checkRepeat(int id, int type);

	//机房容器
	vector<ComputerRoom> vCom;
};

