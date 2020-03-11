#include"BinaryTree.h"
#include<iostream>

/*
建树例子："124##5##36###"
				1
			  /   \
			 2     3
		    / \   /
		   4   5 6
手动建树输入格式：
	1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 -1（-1代表NULL）
自动建树节点范围为1~9

*/


using namespace std;
int main()
{
	char s[] = "124##5##36###";
	pBiTree T;
	T = CreateBiTree();
	//T = CreateBiTreeAuto(s);
	cout << "前序遍历(递归)：" << endl;
	PreOrderTraversal(T);
	cout << endl;
	cout << "中序遍历(递归)：" << endl;
	InOrderTraversal(T);
	cout << endl;
	cout << "后序遍历(递归)：" << endl;
	PostOrderTraversal(T);
	cout << endl;
	cout << "中序遍历(非递归)：" << endl;
	InOrderTraversaln(T);
	cout << endl;
	cout << "前序遍历(非递归)：" << endl;
	PreOrderTraversaln(T);
	cout << endl;
	cout << "后序遍历(非递归)：" << endl;
	PostOrderTraversaln(T);
	cout << endl;
	system("pause");
	return 0;
}