#include<iostream>
using namespace std;
#include"manager.h"


Manager::Manager(int id, string name, int did) {
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = did;
}
//��ʾ������Ϣ
void Manager::showInfo() {
	cout << "ְ�����: " << this->m_Id
		<< "\tְ������: " << this->m_Name
		<< "\t��λ��" << this->getDeptNmae()
		<< "\tְ��ְ������ϰ彻�������񣬲��·������Ա��" << endl;
}
//��ȡ��λ����
string Manager::getDeptNmae() {
	return "����";
}