#include"BinaryTree.h"
#include<iostream>

/*
�������ӣ�"124##5##36###"
				1
			  /   \
			 2     3
		    / \   /
		   4   5 6
�ֶ����������ʽ��
	1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 -1��-1����NULL��
�Զ������ڵ㷶ΧΪ1~9

*/


using namespace std;
int main()
{
	char s[] = "124##5##36###";
	pBiTree T;
	T = CreateBiTree();
	//T = CreateBiTreeAuto(s);
	cout << "ǰ�����(�ݹ�)��" << endl;
	PreOrderTraversal(T);
	cout << endl;
	cout << "�������(�ݹ�)��" << endl;
	InOrderTraversal(T);
	cout << endl;
	cout << "�������(�ݹ�)��" << endl;
	PostOrderTraversal(T);
	cout << endl;
	cout << "�������(�ǵݹ�)��" << endl;
	InOrderTraversaln(T);
	cout << endl;
	cout << "ǰ�����(�ǵݹ�)��" << endl;
	PreOrderTraversaln(T);
	cout << endl;
	cout << "�������(�ǵݹ�)��" << endl;
	PostOrderTraversaln(T);
	cout << endl;
	system("pause");
	return 0;
}