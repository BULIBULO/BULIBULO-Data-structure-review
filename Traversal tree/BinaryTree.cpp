#include"BinaryTree.h"
#include<iostream>
#include <string> 
#include<stdio.h>
#include<stack>
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
	stack<pBiTree> s;
	pBiTree cur = T;
	while (cur != NULL || !s.empty())
	{
		cout << cur->data << " ";
		s.push(cur);
		cur = cur->leftChild;
		while (cur == NULL && !s.empty()) {
			cur = s.top();
			s.pop();
			cur = cur->rightChild;
		}

	}
}

void InOrderTraversaln(pBiTree T)
{
	stack<pBiTree> s;
	pBiTree cur = T;
	while (cur != NULL || !s.empty())
	{
		while (cur!=NULL)
		{
			s.push(cur);
			cur = cur->leftChild;
		}
		cur = s.top();
		cout << cur->data << " ";
		s.pop();
		cur = cur->rightChild;
	}
}

void PostOrderTraversaln(pBiTree T)
{
	cout << "begin";
	stack<pBiTree> s;
	stack<int> result;
	pBiTree cur = T;
	while (cur != NULL || !s.empty())
	{	
		while (cur != NULL)
		{	
			result.push(cur->data);
			s.push(cur);
			cur = cur->rightChild;
		}
		cur = s.top();
		s.pop();
		cur = cur->leftChild;
	}
	while (!result.empty())
	{
		cout << result.top()<<" ";
		result.pop();
	}
}