#include<iostream>
using namespace std;
#include"boss.h"

Boss::Boss(int id, string name, int DeptId) {
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = DeptId;
}

void Boss::showInfo() {
	cout << "ְ�����: " << this->m_Id
		<< "\tְ������: " << this->m_Name
		<< "\t��λ��" << this->getDeptNmae()
		<< "\t����ְ�𣺹���˾�������񣬲����۲Ƹ������ѣ�" << endl;
}
string Boss::getDeptNmae() {
	return string("�ܲ�");
}