#include"BST.h"
#include<iostream>

using namespace std;

int main()
{
	cout << "请输入结点个数：" << endl;
	int size;
	cin >> size;
	cout << "请输入每个节点的值：" << endl;
	int *data = new int[size];
	for (int i = 0; i < size; i++)
	{
		cin >> data[i];
	}

	//int data[] = { 40,24,12,37,55 };
	//int size = 5;

	pBiTree T = CreateBST(data, size);
	cout << "前序遍历(递归)：" << endl;
	PreOrderTraversal(T);
	cout << endl;

	int finddata;
	cout << "请输入要查询的值：" << endl;
	cin >> finddata;
	cout << "查找 "<< finddata<<"的结果为：" << Find(T, finddata) << endl;
	
	cout << "请输入要删除的值：" << endl;
	int deletedata;
	cin >> deletedata;
	T = Delete(T, deletedata);
	
	cout << "删除节点后的前序遍历(递归)：" << endl;
	PreOrderTraversal(T);
	cout << endl;

	system("pause");
	return 0;
}