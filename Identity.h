#pragma once //��ֹͷ�ļ��ظ�����
#include <iostream>
using namespace std;

//�����ĳ��� ---�������У���Ҫд���캯�����������������򱨴�
class Identity
{
public:

	virtual void openMenu() = 0; //���麯��

	string m_Name; //�û���
	string m_Pwd; //����

};
