#include<iostream>
using namespace std;
#include"employee.h"

Employee::Employee(int id, string name, int DeptId) {
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = DeptId;
}

void Employee::showInfo(){
	cout << "ְ�����: " << this->m_Id
		<< "\tְ������: " << this->m_Name
		<< "\t��λ��" << this->getDeptNmae()
		<< "\t����ְ����ɾ�����������" << endl;
}
string Employee::getDeptNmae(){
	return "Ա��";
}