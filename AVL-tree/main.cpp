#include"AVL.h"
#include<iostream>

using namespace std;

int main()
{
	/*cout << "�������������" << endl;
	int size;
	cin >> size;
	cout << "������ÿ���ڵ��ֵ��" << endl;
	int *data = new int[size];
	for (int i = 0; i < size; i++)
	{
		cin >> data[i];
	}*/

	int data[] = { 50,40,30 };
	int size = 3;

	pBiTree T = CreateAVL(data, size);

	cout << "ǰ�����(�ݹ�)��" << endl;
	PreOrderTraversal(T);
	cout << endl;

	T = Delete(T, 30);

	cout << "ɾ���ڵ���ǰ�����(�ݹ�)��" << endl;
	PreOrderTraversal(T);
	cout << endl;

	system("pause");
	return 0;
}