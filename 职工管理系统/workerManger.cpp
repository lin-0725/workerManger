#include<iostream>
using namespace std;
#include "workerManger.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

//���캯��
workerManger::workerManger(){

	//1���ļ�������
	ifstream ifs;
	ifs.open(FILENAME, ios::out);  //���ļ�

	if (!ifs.is_open()) {
		cout << "�ļ������ڣ�" << endl;

		//��ʼ������Ϊ0
		this->m_EmpArray = 0;
		//��ʼ��ָ��Ϊ��
		this->m_EmpArray = NULL;
		//��ʼ���ļ��Ƿ�Ϊ�ձ�־Ϊtrue
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//2���ļ����ڣ�������Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		cout << "�ļ����ڣ�����Ϊ�գ�" << endl;

		//��ʼ������Ϊ0
		this->m_EmpArray = 0;
		//��ʼ��ָ��Ϊ��
		this->m_EmpArray = NULL;
		//��ʼ���ļ��Ƿ�Ϊ�ձ�־Ϊtrue
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//3���ļ����ڣ����Ҽ�¼����
	int num = this->get_EmpNum();

	//cout << "ְ������Ϊ��" << num << endl;
	this->m_EmpNum = num;

	//���ٿռ�
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	//���ļ��е����ݴ浽������
	this->init_Emp();

	//���Դ���
	//for (int i = 0;i < this->m_EmpNum;i++) {
	//	cout << "ְ����ţ�" << this->m_EmpArray[i]->m_Id
	//		<< " ְ��������" << this->m_EmpArray[i]->m_Nmae
	//		<< " ְ�����ţ�" << this->m_EmpArray[i]->getDeptNmae() << endl;
	//}
}

//ͳ������
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

//��ʼ���ļ��е�Ա����������
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
		//���뵽������
		this->m_EmpArray[i] = worker;
		i++;
	}
	ifs.close();
}

//��ʾ�˵�
void workerManger::Show_Menu() {
	cout << "*****************************************" << endl;
	cout << "******** ��ӭʹ��ְ������ϵͳ�� *********" << endl;
	cout << "********     0.�˳�����ϵͳ     *********" << endl;
	cout << "********     1.����ְ����Ϣ     *********" << endl;
	cout << "********     2.��ʾְ����Ϣ     *********" << endl;
	cout << "********     3.ɾ����ְְ��     *********" << endl;
	cout << "********     4.�޸�ְ����Ϣ     *********" << endl;
	cout << "********     5.����ְ����Ϣ     *********" << endl;
	cout << "********     6.���ձ������     *********" << endl;
	cout << "********     7.��������ĵ�     *********" << endl;
	cout << "*****************************************" << endl;
	cout << endl;
}

//�˳�ϵͳ
void workerManger::exitSystem() {
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}

//���ְ��
void workerManger::Add_Emp() {
	cout << "���������ְ��������" << endl;
	int addNum = 0;  //�����û����������
	cin >> addNum;

	if (addNum > 0) {
		//���

		//��������¿ռ��С
		int newSize = this->m_EmpNum + addNum;
		Worker ** newSpace= new Worker* [newSize];

		//��ԭ���ռ������ݣ��������¿ռ���
		if (this->m_EmpArray != NULL) {
			for (int i = 0; i < this->m_EmpNum; i++) {
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		//�������������
		for (int i = 0; i < addNum; i++) {
			int id;  //ְ�����
			string name;  //ְ������
			int dSelect; //����

			cout << "�������" << i + 1 << "����ְ����ţ�" << endl;
			cin >> id;
			while (this->IsExist(id) != -1) {
				cout << "Ա������Ѿ����ڣ��뻻һ����ţ�" << endl;
				cin >> id;
			}
			

			cout << "�������" << i + 1 << "����ְ��������" << endl;
			cin >> name;

			cout << "��ѡ���ְ����λ��" << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
			cin >> dSelect;
			Worker* worker = NULL;
			while (dSelect != 1 && dSelect != 2 && dSelect != 3) {
				cout << "���������������������룺";
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
			//��������ְ��ָ�뱣�浽������
			newSpace[this->m_EmpNum + i] = worker;
		}

		//�ͷ�ԭ�пռ�
		delete[] this->m_EmpArray;

		//���¿ռ��ָ��
		this->m_EmpArray = newSpace;

		//�����µ�ְ������
		this->m_EmpNum = newSize;
		//��ʾ��ӳɹ�
		cout<<"�ɹ����"<<addNum<<"����Ա����"<<endl;
		this->save();
	}
	else {
		cout << "������������" << endl;
	}
	//������������� �ص��ϼ�Ŀ¼
	system("pause");
	system("cls");
}

//���浽�ļ���
void workerManger::save() {
	ofstream ofs;
	ofs.open(FILENAME, ios::out); //�������ʽ���ļ� --д�ļ�
	//��ÿ���˵�����д���ļ�
	for (int i = 0; i < this->m_EmpNum; i++) {
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId << " "<<endl;
	}
	//�ر��ļ�
	ofs.close();
}


//��ʾְ��
void workerManger::show_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else {
		for (int i = 0;i < m_EmpNum;i++) {
			//���ö�̬���ó���ӿ�
			this->m_EmpArray[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}

//�ж�ְ���Ƿ����
int workerManger::IsExist(int id) {
	int index = -1;
	for (int i = 0; i < this->m_EmpNum; i++) {
		if (this->m_EmpArray[i]->m_Id == id) {
			//�ҵ�ְ��
			index = i;
			break;
		}
	}
	return index;
}

//ɾ����ְְ��  ���ʣ������е����ݸ���
void workerManger::Del_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else {
		int id;
		cout << "��������Ҫɾ����ְ����ţ�" << endl;
		cin >> id;
		if (this->IsExist(id) == -1) {
			cout << "û�в��ҵ���Ҫɾ����ְ�����,ɾ��ʧ�ܣ�" << endl;
		}
		else {
			for (int i = this->IsExist(id); i < this->m_EmpNum - 1; i++) {
				//���ݸ���
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;

			this->save();
			cout << "ɾ���ɹ�" << endl;
		}
	}

	system("pause");
	system("cls");
}


//�޸�ְ��
void workerManger::Mod_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else {
		cout << "�������޸ĵ�ְ�����" << endl;
		int id;
		cin >> id;
		if (this->IsExist(id) != -1) {
			//���ҵ�ְ��
			delete this->m_EmpArray[IsExist(id)];
			int newId = 0;
			string newName;
			int did;
			cout << "���ҵ���" << id << "��ְ������������ְ����ţ�" << endl;
			cin >> newId;
			cout << "��������������" << endl;
			cin >> newName;
			cout << "�������¸�λ:" << endl;
			cout << "1����ͨԱ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
			cin >> did;
			while (did != 1 && did != 2 && did != 3) {
				cout << "��������¸�λ�������������룺" << endl;
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
				cout << "������ĸ�λ�������" << endl;
				break;
			}
			//�������ݵ�������
			this->m_EmpArray[IsExist(id)] = worker;

			cout << "�޸ĳɹ�" << endl;

			//���浽�ļ���
			this->save();
		}
		else {
			cout << "�޸�ʧ�ܣ����޴��ˣ�" << endl;
		}
	}
	system("pause");
	system("cls");
}


//����ְ��
void workerManger::Find_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "�ļ������ڻ��߼�¼Ϊ�գ�" << endl;
	}
	else {
		cout << "��������ҷ�ʽ" << endl;
		cout << "1����ְ����Ų���" << endl;
		cout << "2������������" << endl;
		int select = 0;
		cin >> select;
		while (select != 1 && select != 2) {
			cout << "���������������������룺" << endl;
			cin >> select;
		}
		if (select == 1) {
			//����ְ����Ų�
			int id;
			cout << "��������Ҫ���ҵ�ְ�����:" << endl;
			cin >> id;
			int ret = IsExist(id);
			if (ret != -1) {
				cout << "���ҳɹ�����Ա����Ϣ���£�" << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else {
				cout << "���޴��ˣ�" << endl;
			}
		}
		if (select == 2) {
			//����ְ��������
			cout << "��������Ҫ���ҵ�ְ��������" << endl;
			string name;
			bool flag = true;
			cin >> name;
			for (int i = 0; i < this->m_EmpNum; i++) {
				if (this->m_EmpArray[i]->m_Name == name) {
					cout << "���ҳɹ�,ְ�����Ϊ��" << this->m_EmpArray[i]->m_Id<<"ְ����Ϣ���£�" <<endl;
					this->m_EmpArray[i]->showInfo();
					flag = false;
				}
			}
			if (flag) {
				cout << "���޴��ˣ�" << endl;
			}
		}
	}
	system("pause");
	system("cls");
}


//ְ������
void workerManger::Sort_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "�ļ������ڻ��߼�¼Ϊ�գ�" << endl;
		system("pause");
		system("cls");
		return;
	}
	else {
		cout << "��ѡ������ʽ��" << endl;
		cout << "1����ְ���Ž�������" << endl;
		cout << "2����ְ���Ž��н���" << endl;

		int select = 0;
		//ð������
		while (true) {
			cin >> select;
			if (select != 1 && select != 2) {
				cout << "���������������������룺" << endl;
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
	cout << "����ɹ��������Ľ��Ϊ��" << endl;
	//���浽�ļ���
	this->save();
	//��ʾ
	this->show_Emp();
}

//����ļ�
void workerManger::Clean_File() {
	cout << "ȷ����գ�" << endl;
	cout << "1��ȷ��" << endl;
	cout << "2������" << endl;
	int select = 0;
	cin >> select;
	if (select == 1) {
		//����ļ�
		ofstream ofs(FILENAME, ios::trunc);//ɾ���ļ������´���
		ofs.close();
		if (this->m_EmpArray != NULL) {
			//ɾ��������ÿ��ְ������
			for (int i = 0; i < this->m_EmpNum; i++) {
				delete this->m_EmpArray[i];
				this->m_EmpArray[i] = NULL;
			}
			//ɾ����������
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_EmpNum = 0;
			this->m_FileIsEmpty = true;
		}
		cout << "��ճɹ���" << endl;
	}
	else {
		cout << "���سɹ�" << endl;
	}
	system("pause");
	system("cls");
}


//��������
workerManger::~workerManger() {
	if (this->m_EmpArray != NULL) {
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}


