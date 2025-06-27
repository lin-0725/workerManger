#pragma once
#include<iostream> 
using namespace std;

#include "worker.h"
#include<fstream>
#define FILENAME "Employee.txt"

class workerManger {
public:
	//���캯��
	workerManger();

	//��ʾ�˵�
	void Show_Menu();

	//���ְ��
	void Add_Emp();

	//�޸�ְ��
	void Mod_Emp();

	//�����ļ�
	void save();

	//����ļ�
	void Clean_File();

	//�ж��ļ��Ƿ�Ϊ��
	bool m_FileIsEmpty;

	//ͳ���ļ�������
	int get_EmpNum();
	//��ʼ��Ա��
	void init_Emp();

	//��ʾԱ��
	void show_Emp();

	//�ж�ְ���Ƿ����
	int IsExist(int id);

	//ɾ��ְ��
	void Del_Emp();

	//����ְ��
	void Find_Emp();

	//����ְ���������
	void Sort_Emp();

	//�˳�ϵͳ
	void exitSystem();
	
	//��¼ְ������
	int m_EmpNum;

	//ְ������ָ��
	Worker** m_EmpArray;

	//��������
	~workerManger();
};