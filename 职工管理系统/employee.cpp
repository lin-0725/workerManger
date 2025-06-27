#include<iostream>
using namespace std;
#include"employee.h"

Employee::Employee(int id, string name, int DeptId) {
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = DeptId;
}

void Employee::showInfo(){
	cout << "职工编号: " << this->m_Id
		<< "\t职工姓名: " << this->m_Name
		<< "\t岗位：" << this->getDeptNmae()
		<< "\t经理职责：完成经理交给的任务" << endl;
}
string Employee::getDeptNmae(){
	return "员工";
}