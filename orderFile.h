#pragma once
#include <iostream>
using namespace std;
#include <map>
#include "globalFile.h"	
#include <fstream>

class OrderFile
{
public:
	OrderFile(); //!!!�Զ����ɵ����������ǵ�ɾ�������򱨴�����

	//����ԤԼ��¼
	void updataOrder();

	//��¼������ key---��¼��������value---�����¼�ļ�ֵ����Ϣ
	map<int, map<string, string>> m_orderData;

	//ԤԼ��¼����
	int m_Size;

};