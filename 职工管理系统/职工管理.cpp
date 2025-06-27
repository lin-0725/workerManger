#include<iostream>
using namespace std;
#include "workerManger.h"

#include"worker.h"
#include "employee.h"
#include "manager.h"
#include "Boss.h"


//���Դ���
void test01() {
    Worker* worker1 = new Employee(1,"����",1);
    worker1->showInfo();
	Worker* worker2 = new Manager(2, "����", 2);
	worker2->showInfo();
	Worker* worker3 = new Boss(3, "����", 3);
	worker3->showInfo();
}
//�ļ����ж��ٸ���
void test02() {
	workerManger wm;
	cout<<"�ļ��е�ǰ��"<<wm.get_EmpNum()<<"��"<<endl;
}

int main() {
	//test01();
	//test02();
	workerManger wm;
	int choice;
	while (true) {
		wm.Show_Menu();
		cout << "����������ѡ��" << endl;
		cin >> choice;
		switch (choice) {
		case 1:      //����ְ��
			wm.Add_Emp();
			break;
		case 2:      //��ʾְ��
			wm.show_Emp();
			break;
		case 3:      //ɾ��ְ��
			wm.Del_Emp();
			break;
		case 4:      //�޸�ְ��
			wm.Mod_Emp();
			break;
		case 5:      //����ְ��
			wm.Find_Emp();
			break;
		case 6:      //ְ������ 
			wm.Sort_Emp();
			break;
		case 7:      //��������ĵ�
			wm.Clean_File();
			break;
		case 0:      //�˳�ϵͳ
			wm.exitSystem();
			break;
		}
		

	}

	return 0;
}