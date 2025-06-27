#include<iostream>
using namespace std;
#include "workerManger.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

//构造函数
workerManger::workerManger(){

	//1、文件不存在
	ifstream ifs;
	ifs.open(FILENAME, ios::out);  //读文件

	if (!ifs.is_open()) {
		cout << "文件不存在！" << endl;

		//初始化人数为0
		this->m_EmpArray = 0;
		//初始化指针为空
		this->m_EmpArray = NULL;
		//初始化文件是否为空标志为true
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//2、文件存在，但数据为空
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		cout << "文件存在，数据为空！" << endl;

		//初始化人数为0
		this->m_EmpArray = 0;
		//初始化指针为空
		this->m_EmpArray = NULL;
		//初始化文件是否为空标志为true
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//3、文件存在，并且记录数据
	int num = this->get_EmpNum();

	//cout << "职工人数为：" << num << endl;
	this->m_EmpNum = num;

	//开辟空间
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	//将文件中的数据存到数组中
	this->init_Emp();

	//测试代码
	//for (int i = 0;i < this->m_EmpNum;i++) {
	//	cout << "职工编号：" << this->m_EmpArray[i]->m_Id
	//		<< " 职工姓名：" << this->m_EmpArray[i]->m_Nmae
	//		<< " 职工部门：" << this->m_EmpArray[i]->getDeptNmae() << endl;
	//}
}

//统计人数
int workerManger::get_EmpNum() {
	ifstream ifs;
	int num = 0;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int did;

	while (ifs >> id && ifs >> name && ifs >> did) {
		num++;
	}
	return num;
}

//初始化文件中的员工到数组中
void workerManger::init_Emp() {
	ifstream ifs;
	int id;
	string name;
	int did;
	int i= 0;
	ifs.open(FILENAME, ios::in);
	while (ifs >> id && ifs >> name && ifs >> did) {
		Worker* worker = NULL;
		if (did == 1) {
			worker = new Employee(id, name, did);
		}
		else if (did == 2) {
			worker = new Manager(id, name, did);
		}
		else{
			worker = new Boss(id, name, did);
		}
		//放入到数组中
		this->m_EmpArray[i] = worker;
		i++;
	}
	ifs.close();
}

//显示菜单
void workerManger::Show_Menu() {
	cout << "*****************************************" << endl;
	cout << "******** 欢迎使用职工管理系统！ *********" << endl;
	cout << "********     0.退出管理系统     *********" << endl;
	cout << "********     1.增加职工信息     *********" << endl;
	cout << "********     2.显示职工信息     *********" << endl;
	cout << "********     3.删除离职职工     *********" << endl;
	cout << "********     4.修改职工信息     *********" << endl;
	cout << "********     5.查找职工信息     *********" << endl;
	cout << "********     6.按照编号排序     *********" << endl;
	cout << "********     7.清空所有文档     *********" << endl;
	cout << "*****************************************" << endl;
	cout << endl;
}

//退出系统
void workerManger::exitSystem() {
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}

//添加职工
void workerManger::Add_Emp() {
	cout << "请输入添加职工数量：" << endl;
	int addNum = 0;  //保存用户输入的数量
	cin >> addNum;

	if (addNum > 0) {
		//添加

		//计算添加新空间大小
		int newSize = this->m_EmpNum + addNum;
		Worker ** newSpace= new Worker* [newSize];

		//将原来空间下数据，拷贝到新空间下
		if (this->m_EmpArray != NULL) {
			for (int i = 0; i < this->m_EmpNum; i++) {
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		//批量添加新数据
		for (int i = 0; i < addNum; i++) {
			int id;  //职工编号
			string name;  //职工姓名
			int dSelect; //部门

			cout << "请输入第" << i + 1 << "个新职工编号：" << endl;
			cin >> id;
			while (this->IsExist(id) != -1) {
				cout << "员工编号已经存在，请换一个编号：" << endl;
				cin >> id;
			}
			

			cout << "请输入第" << i + 1 << "个新职工姓名：" << endl;
			cin >> name;

			cout << "请选择该职工岗位：" << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> dSelect;
			Worker* worker = NULL;
			while (dSelect != 1 && dSelect != 2 && dSelect != 3) {
				cout << "您的输入有误，请重新输入：";
				cin >> dSelect;
			}
			switch (dSelect) {
			case 1:
				worker = new Employee(id, name, dSelect);
				break;
			case 2:
				worker = new Manager(id, name, dSelect);
				break;
			case 3:
				worker = new Boss(id, name, dSelect);
				break;
			}
			//将创建的职工指针保存到数组中
			newSpace[this->m_EmpNum + i] = worker;
		}

		//释放原有空间
		delete[] this->m_EmpArray;

		//更新空间的指向
		this->m_EmpArray = newSpace;

		//更新新的职工人数
		this->m_EmpNum = newSize;
		//提示添加成功
		cout<<"成功添加"<<addNum<<"名新员工！"<<endl;
		this->save();
	}
	else {
		cout << "数据输入有误！" << endl;
	}
	//按任意键后清屏 回到上级目录
	system("pause");
	system("cls");
}

//保存到文件中
void workerManger::save() {
	ofstream ofs;
	ofs.open(FILENAME, ios::out); //用输出方式打开文件 --写文件
	//将每个人的数据写入文件
	for (int i = 0; i < this->m_EmpNum; i++) {
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId << " "<<endl;
	}
	//关闭文件
	ofs.close();
}


//显示职工
void workerManger::show_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "文件不存在或记录为空！" << endl;
	}
	else {
		for (int i = 0;i < m_EmpNum;i++) {
			//利用多态调用程序接口
			this->m_EmpArray[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}

//判断职工是否存在
int workerManger::IsExist(int id) {
	int index = -1;
	for (int i = 0; i < this->m_EmpNum; i++) {
		if (this->m_EmpArray[i]->m_Id == id) {
			//找到职工
			index = i;
			break;
		}
	}
	return index;
}

//删除离职职工  本质：数组中的数据覆盖
void workerManger::Del_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "文件不存在或记录为空！" << endl;
	}
	else {
		int id;
		cout << "请输入你要删除的职工编号：" << endl;
		cin >> id;
		if (this->IsExist(id) == -1) {
			cout << "没有查找到您要删除的职工编号,删除失败！" << endl;
		}
		else {
			for (int i = this->IsExist(id); i < this->m_EmpNum - 1; i++) {
				//数据覆盖
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;

			this->save();
			cout << "删除成功" << endl;
		}
	}

	system("pause");
	system("cls");
}


//修改职工
void workerManger::Mod_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "文件不存在或记录为空！" << endl;
	}
	else {
		cout << "请输入修改的职工编号" << endl;
		int id;
		cin >> id;
		if (this->IsExist(id) != -1) {
			//查找到职工
			delete this->m_EmpArray[IsExist(id)];
			int newId = 0;
			string newName;
			int did;
			cout << "查找到：" << id << "号职工，请输入新职工编号：" << endl;
			cin >> newId;
			cout << "请输入新姓名：" << endl;
			cin >> newName;
			cout << "请输入新岗位:" << endl;
			cout << "1、普通员工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> did;
			while (did != 1 && did != 2 && did != 3) {
				cout << "您输入的新岗位有误！请重新输入：" << endl;
				cin >> did;
			}
			Worker* worker = NULL;
			switch (did) {
			case 1:
				worker = new Employee(newId, newName, did);
				break;
			case 2:
				worker = new Manager(newId, newName, did);
				break;
			case 3:
				worker = new Boss(newId, newName, did);
				break;
			default:
				cout << "您输入的岗位编号有误！" << endl;
				break;
			}
			//更新数据到数组中
			this->m_EmpArray[IsExist(id)] = worker;

			cout << "修改成功" << endl;

			//保存到文件中
			this->save();
		}
		else {
			cout << "修改失败，查无此人！" << endl;
		}
	}
	system("pause");
	system("cls");
}


//查找职工
void workerManger::Find_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "文件不存在或者记录为空！" << endl;
	}
	else {
		cout << "请输入查找方式" << endl;
		cout << "1、按职工编号查找" << endl;
		cout << "2、按姓名查找" << endl;
		int select = 0;
		cin >> select;
		while (select != 1 && select != 2) {
			cout << "您的输入有误，请重新输入：" << endl;
			cin >> select;
		}
		if (select == 1) {
			//按照职工编号查
			int id;
			cout << "请输入您要查找的职工编号:" << endl;
			cin >> id;
			int ret = IsExist(id);
			if (ret != -1) {
				cout << "查找成功！该员工信息如下：" << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else {
				cout << "查无此人！" << endl;
			}
		}
		if (select == 2) {
			//按照职工姓名查
			cout << "请输入您要查找的职工姓名：" << endl;
			string name;
			bool flag = true;
			cin >> name;
			for (int i = 0; i < this->m_EmpNum; i++) {
				if (this->m_EmpArray[i]->m_Name == name) {
					cout << "查找成功,职工编号为：" << this->m_EmpArray[i]->m_Id<<"职工信息如下：" <<endl;
					this->m_EmpArray[i]->showInfo();
					flag = false;
				}
			}
			if (flag) {
				cout << "查无此人！" << endl;
			}
		}
	}
	system("pause");
	system("cls");
}


//职工排序
void workerManger::Sort_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "文件不存在或者记录为空！" << endl;
		system("pause");
		system("cls");
		return;
	}
	else {
		cout << "请选择排序方式：" << endl;
		cout << "1、按职工号进行升序" << endl;
		cout << "2、按职工号进行降序" << endl;

		int select = 0;
		//冒泡排序
		while (true) {
			cin >> select;
			if (select != 1 && select != 2) {
				cout << "您的输入有误，请重新输入：" << endl;
				cin >> select;
			}
			else {
				break;
			}

		}
		if (select == 1) {
			for (int i = 0; i < this->m_EmpNum; i++) {
				for (int j = i + 1; j < this->m_EmpNum; j++) {
					if (this->m_EmpArray[i]->m_Id > this->m_EmpArray[j]->m_Id) {
						Worker* worker = NULL;
						worker = this->m_EmpArray[i];
						this->m_EmpArray[i] = this->m_EmpArray[j];
						this->m_EmpArray[j] = worker;
					}
				}
			}
		}
		if (select == 2) {
			for (int i = 0; i < this->m_EmpNum; i++) {
				for (int j = i + 1; j < this->m_EmpNum; j++) {
					if (this->m_EmpArray[i]->m_Id < this->m_EmpArray[j]->m_Id) {
						Worker* worker = NULL;
						worker = this->m_EmpArray[i];
						this->m_EmpArray[i] = this->m_EmpArray[j];
						this->m_EmpArray[j] = worker;
					}
				}
			}
		}
	}
	cout << "排序成功！排序后的结果为：" << endl;
	//保存到文件中
	this->save();
	//显示
	this->show_Emp();
}

//清空文件
void workerManger::Clean_File() {
	cout << "确定清空？" << endl;
	cout << "1、确定" << endl;
	cout << "2、返回" << endl;
	int select = 0;
	cin >> select;
	if (select == 1) {
		//清空文件
		ofstream ofs(FILENAME, ios::trunc);//删除文件后重新创建
		ofs.close();
		if (this->m_EmpArray != NULL) {
			//删除堆区的每个职工对象
			for (int i = 0; i < this->m_EmpNum; i++) {
				delete this->m_EmpArray[i];
				this->m_EmpArray[i] = NULL;
			}
			//删除堆区数组
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_EmpNum = 0;
			this->m_FileIsEmpty = true;
		}
		cout << "清空成功！" << endl;
	}
	else {
		cout << "返回成功" << endl;
	}
	system("pause");
	system("cls");
}


//析构函数
workerManger::~workerManger() {
	if (this->m_EmpArray != NULL) {
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}


