#include"BinaryTree.h"
#include<iostream>
#include <string> 
#include<stdio.h>
using namespace std;

pBiTree CreateBiTree()
{
	int i;
	//rewind(stdin);
	pBiTree T;
	cout << "input:\n";
	cin >> i;
	if (i == -1) 
	{
		cout << "stop\n";
		T = NULL;
	}
		
	else {
		T = (pBiTree)malloc(sizeof(BiTNode));
		T->data = i;
		cout << "input " << i << " successful\n";
		cout << "create left\n";
		T->leftChild = CreateBiTree();
		cout << "create right\n";
		T->rightChild = CreateBiTree();
	}
	return T;
}

int g_i = 0;
pBiTree CreateBiTreeAuto(char s[])
{
	pBiTree T;
	if (s[g_i] == '#')
	{
		T = NULL;
		g_i++;
	}

	else {
		T = (pBiTree)malloc(sizeof(BiTNode));
		cout << s[g_i];
		T->data = s[g_i]-'0';
		g_i++;
		T->leftChild = CreateBiTreeAuto(s);
		T->rightChild = CreateBiTreeAuto(s);
	}
	return T;
}

void PreOrderTraversal(pBiTree T)
{
	if (T) {
		cout << T->data << " ";
		PreOrderTraversal(T->leftChild);
		PreOrderTraversal(T->rightChild);
	}
}

void InOrderTraversal(pBiTree T) 
{
	if (T) 
	{
		InOrderTraversal(T->leftChild);
		cout << T->data << " ";
		InOrderTraversal(T->rightChild);
	}
}

void PostOrderTraversal(pBiTree T) 
{
	if(T)
	{
		PostOrderTraversal(T->leftChild);
		PostOrderTraversal(T->rightChild);
		cout << T->data << " ";
	}
}

void PreOrderTraversaln(pBiTree T)
{

}

void InOrderTraversaln(pBiTree T)
{

}

void PostOrderTraversaln(pBiTree T)
{

}