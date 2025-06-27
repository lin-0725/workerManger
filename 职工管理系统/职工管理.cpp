#include<iostream>
using namespace std;
#include "workerManger.h"

#include"worker.h"
#include "employee.h"
#include "manager.h"
#include "Boss.h"


//测试代码
void test01() {
    Worker* worker1 = new Employee(1,"张三",1);
    worker1->showInfo();
	Worker* worker2 = new Manager(2, "李四", 2);
	worker2->showInfo();
	Worker* worker3 = new Boss(3, "王五", 3);
	worker3->showInfo();
}
//文件中有多少个人
void test02() {
	workerManger wm;
	cout<<"文件中当前有"<<wm.get_EmpNum()<<"人"<<endl;
}

int main() {
	//test01();
	//test02();
	workerManger wm;
	int choice;
	while (true) {
		wm.Show_Menu();
		cout << "请输入您的选择：" << endl;
		cin >> choice;
		switch (choice) {
		case 1:      //增加职工
			wm.Add_Emp();
			break;
		case 2:      //显示职工
			wm.show_Emp();
			break;
		case 3:      //删除职工
			wm.Del_Emp();
			break;
		case 4:      //修改职工
			wm.Mod_Emp();
			break;
		case 5:      //查找职工
			wm.Find_Emp();
			break;
		case 6:      //职工排序 
			wm.Sort_Emp();
			break;
		case 7:      //清空所有文档
			wm.Clean_File();
			break;
		case 0:      //退出系统
			wm.exitSystem();
			break;
		}
		

	}

	return 0;
}