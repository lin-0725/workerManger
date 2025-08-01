#pragma once
#include<iostream>
using namespace std;

//职工的抽象类
class Worker {
public:

	//显示个人信息
	virtual void showInfo() = 0;
	//获取岗位名称
	virtual string getDeptNmae() = 0;
	//职工编号
	int m_Id;
	//职工姓名
	string m_Name;
	//部门编号
	int m_DeptId;
};
