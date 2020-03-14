#include<iostream>
#include"BST.h"

using namespace std;

void PreOrderTraversal(pBiTree T)
{
	if (T) {
		cout << T->data << " ";
		PreOrderTraversal(T->leftChild);
		PreOrderTraversal(T->rightChild);
	}
}

pBiTree CreateBST(int *data, int size)
{
	pBiTree tempT = NULL;
	for (int i = 0; i < size; i++)
	{
		tempT = Insert(tempT, data[i]);
	}
	return tempT;
}

pBiTree Insert(pBiTree T, int data)
{
	if (T == NULL)
	{
		T = new BiTNode;
		T->data = data;
		T->leftChild = T->rightChild = NULL;
	}
	else
	{
		if (data < T->data)
		{
			T->leftChild = Insert(T->leftChild, data);
		}
		else
		{
			T->rightChild = Insert(T->rightChild, data);
		}
	}
	return T;
}

pBiTree Find(pBiTree T, int key)
{
	BiTNode *cur = T;
	if (cur == NULL)
	{
		return NULL;
	}
	while (cur)
	{
		if (key == cur->data)
		{
			return cur;
		}
		else if (key < cur->data)
		{
			cur = cur->leftChild;
		}
		else
		{
			cur = cur->rightChild;
		}
	}
	return cur;
}

pBiTree Findmin(pBiTree T)
{
	pBiTree cur = T;
	if (T == NULL)
	{
		return NULL;
	}
	while (cur)
	{
		if (cur->leftChild == NULL)
		{
			return cur;
		}
		else
		{
			cur = cur->leftChild;
		}
	}
	return cur;
}

pBiTree Delete(pBiTree T, int data)
{
	if (T == NULL)
	{
		return NULL;
	}
	else if (data < T->data)
	{
		T->leftChild = Delete(T->leftChild, data);
	}
	else if (data > T->data)
	{
		T->rightChild = Delete(T->rightChild, data);
	}
	else
	{
		if (T->leftChild&&T->rightChild)
		{
			pBiTree tmp = Findmin(T->rightChild);
			T->data = tmp->data;
			T->rightChild = Delete(T->rightChild, tmp->data);
		}
		else
		{
			pBiTree tmp = T;
			if (T->leftChild)
			{
				T = T->leftChild;
			}
			else
			{
				T = T->rightChild;
			}
			delete tmp;
		}
	}
	return T;
}