#pragma once
#include<iostream> 
using namespace std;

#include "worker.h"
#include<fstream>
#define FILENAME "Employee.txt"

class workerManger {
public:
	//构造函数
	workerManger();

	//显示菜单
	void Show_Menu();

	//添加职工
	void Add_Emp();

	//修改职工
	void Mod_Emp();

	//保存文件
	void save();

	//清空文件
	void Clean_File();

	//判断文件是否为空
	bool m_FileIsEmpty;

	//统计文件中人数
	int get_EmpNum();
	//初始化员工
	void init_Emp();

	//显示员工
	void show_Emp();

	//判断职工是否存在
	int IsExist(int id);

	//删除职工
	void Del_Emp();

	//查找职工
	void Find_Emp();

	//按照职工编号排序
	void Sort_Emp();

	//退出系统
	void exitSystem();
	
	//记录职工人数
	int m_EmpNum;

	//职工数组指针
	Worker** m_EmpArray;

	//析构函数
	~workerManger();
};