#include"BST.h"
#include<iostream>

using namespace std;

int main()
{
	cout << "�������������" << endl;
	int size;
	cin >> size;
	cout << "������ÿ���ڵ��ֵ��" << endl;
	int *data = new int[size];
	for (int i = 0; i < size; i++)
	{
		cin >> data[i];
	}

	//int data[] = { 40,24,12,37,55 };
	//int size = 5;

	pBiTree T = CreateBST(data, size);
	cout << "ǰ�����(�ݹ�)��" << endl;
	PreOrderTraversal(T);
	cout << endl;

	int finddata;
	cout << "������Ҫ��ѯ��ֵ��" << endl;
	cin >> finddata;
	cout << "���� "<< finddata<<"�Ľ��Ϊ��" << Find(T, finddata) << endl;
	
	cout << "������Ҫɾ����ֵ��" << endl;
	int deletedata;
	cin >> deletedata;
	T = Delete(T, deletedata);
	
	cout << "ɾ���ڵ���ǰ�����(�ݹ�)��" << endl;
	PreOrderTraversal(T);
	cout << endl;

	system("pause");
	return 0;
}