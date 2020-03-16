#include"AVL.h"
#include<iostream>

using namespace std;

int main()
{
	/*cout << "请输入结点个数：" << endl;
	int size;
	cin >> size;
	cout << "请输入每个节点的值：" << endl;
	int *data = new int[size];
	for (int i = 0; i < size; i++)
	{
		cin >> data[i];
	}*/

	int data[] = { 50,40,30 };
	int size = 3;

	pBiTree T = CreateAVL(data, size);

	cout << "前序遍历(递归)：" << endl;
	PreOrderTraversal(T);
	cout << endl;

	T = Delete(T, 30);

	cout << "删除节点后的前序遍历(递归)：" << endl;
	PreOrderTraversal(T);
	cout << endl;

	system("pause");
	return 0;
}