#pragma once
#include <iostream>
using namespace std;
#include "Identity.h"
#include "orderFile.h"
#include <vector>

class Teacher:public Identity
{
public:
	//Ĭ�Ϲ��� ��Ĭ�Ϲ��첻����ɾȥ������ᱨ��
	Teacher();

	//�вι��죨ְ����ţ����������룩
	Teacher(int empId, string name, string pwd);

	//�˵�����
	virtual void openMenu();

	//�鿴����ԤԼ
	void showAllOrder();

	//���ԤԼ
	void vaildOrder();

	int m_EmpId; //��ʦ���
};