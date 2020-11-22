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


//����Ա��
class Manager :public Identity
{
public:
	//Ĭ�Ϲ���
	Manager();

	//�вι���
	Manager(string name, string pwd);
	
	//�˵�����
	virtual void openMenu();

	//����˺�
	void addPerson();

	//�鿴�˺�
	void showPerson();

	//�鿴������Ϣ
	void showComputer();

	//���ԤԼ��¼
	void cleanFlie();

	//��ʼ������
	void initVector();

	//ѧ������
	vector<Student> vStu;

	//��ʦ����
	vector<Teacher> vTea;

	//����ظ�����;(����id����������) ����ֵ����ture �������ظ���false����û���ظ���
	bool checkRepeat(int id, int type);

	//��������
	vector<ComputerRoom> vCom;
};

