#pragma once //防止头文件重复包含
#include <iostream>
using namespace std;

//身份类的抽象 ---抽象类中，不要写构造函数和析构函数，否则报错
class Identity
{
public:

	virtual void openMenu() = 0; //纯虚函数

	string m_Name; //用户名
	string m_Pwd; //密码

};
