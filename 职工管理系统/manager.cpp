#include<iostream>
using namespace std;
#include"manager.h"


Manager::Manager(int id, string name, int did) {
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = did;
}
//显示个人信息
void Manager::showInfo() {
	cout << "职工编号: " << this->m_Id
		<< "\t职工姓名: " << this->m_Name
		<< "\t岗位：" << this->getDeptNmae()
		<< "\t职工职责：完成老板交给的任务，并下发任务给员工" << endl;
}
//获取岗位名称
string Manager::getDeptNmae() {
	return "经理";
}