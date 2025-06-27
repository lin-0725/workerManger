#include<iostream>
using namespace std;
#include"boss.h"

Boss::Boss(int id, string name, int DeptId) {
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = DeptId;
}

void Boss::showInfo() {
	cout << "职工编号: " << this->m_Id
		<< "\t职工姓名: " << this->m_Name
		<< "\t岗位：" << this->getDeptNmae()
		<< "\t经理职责：管理公司所有事务，并积累财富，消费！" << endl;
}
string Boss::getDeptNmae() {
	return string("总裁");
}