#include<iostream>
#include"AVL.h"

using namespace std;

void PreOrderTraversal(pBiTree T)
{
	if (T) {
		cout << "Öµ£º" << T->data << " ¸ß¶È£º" << T->height << endl;;
		PreOrderTraversal(T->leftChild);
		PreOrderTraversal(T->rightChild);
	}
}

pBiTree CreateAVL(int *data, int size)
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
		T->height = 0;
		T->leftChild = T->rightChild = NULL;
		
	}
	else if (data < T->data)
	{
		T->leftChild = Insert(T->leftChild, data);
		int lheight = getHeight(T->leftChild);
		int rheight = getHeight(T->rightChild);
		if (lheight - rheight == 2)
		{
			if (data < T->leftChild->data)
			{
				T = SingleLRotation(T);
			}
			else
			{
				T = DoubleLRRotation(T);
			}
		}
	}
	else if (data > T->data)
	{
		T->rightChild = Insert(T->rightChild, data);
		int lheight = getHeight(T->leftChild);
		int rheight = getHeight(T->rightChild);
		if (rheight - lheight == 2)
		{
			if (data > T->rightChild->data)
			{
				T = SingleRRotation(T);
			}
			else
			{
				T = DoubleRLRotation(T);
			}
		}
	}
	T->height = Max(getHeight(T->leftChild), getHeight(T->rightChild)) + 1;
	return T;
}

pBiTree Delete(pBiTree T, int data)
{
	if (!T) 
	{
		return T;
	}
	else if (data < T->data)
	{
		T->leftChild = Delete(T->leftChild, data);
		int	lheight = getHeight(T->leftChild);
		int rheight = getHeight(T->rightChild);
		if (lheight - rheight == 2)
		{
			if (data > T->rightChild->data) 
			{
				T = SingleLRotation(T);
			}			
			else
			{
				T = DoubleRLRotation(T);
			}
		}
	}
	else if (data > T->data)
	{
		T->leftChild = Delete(T->leftChild, data);
		int	lheight = getHeight(T->leftChild);
		int rheight = getHeight(T->rightChild);
		if (rheight - lheight == 2)
		{
			if (data < T->leftChild->data) 
			{
				T = SingleLRotation(T);
			}
			else
			{
				T = DoubleLRRotation(T);
			}
		}
	}
	else if (data == T->data)
	{
		if (T->leftChild&&T->rightChild)
		{
			pBiTree tmp = Findmin(T);
			T->data = tmp->data;
			T->rightChild = Delete(T->rightChild, data);
		}
		else
		{
			pBiTree tmp = T;
			if (!T->leftChild)
			{
				T = T->rightChild;
			}
			else if (!T->rightChild)
			{
				T = T->leftChild;
			}
			delete tmp;
		}
	}
	return T;
}

int getHeight(pBiTree T)
{
	if (!T)
	{
		return 0;
	}
	return T->height;
}

int Max(int a, int b)
{
	return (a > b) ? a : b;
}

pBiTree SingleLRotation(pBiTree T)
{
	pBiTree tmp = T->leftChild;
	T->leftChild = tmp->rightChild;
	tmp->rightChild = T;
	T->height = Max(getHeight(T->rightChild), getHeight(T->leftChild)) + 1;
	tmp->height = Max(getHeight(tmp->rightChild), getHeight(tmp->leftChild)) + 1;
	return tmp;
}

pBiTree SingleRRotation(pBiTree T)
{
	pBiTree tmp = T->rightChild;
	T->rightChild = tmp->leftChild;
	tmp->leftChild = T;
	T->height = Max(getHeight(T->rightChild), getHeight(T->leftChild)) + 1;
	tmp->height = Max(getHeight(tmp->rightChild), getHeight(tmp->leftChild)) + 1;
	return tmp;
}

pBiTree DoubleLRRotation(pBiTree T)
{
	T->leftChild = SingleRRotation(T->leftChild);
	return SingleLRotation(T);
}

pBiTree DoubleRLRotation(pBiTree T)
{
	T->rightChild = SingleLRotation(T->rightChild);
	return SingleRRotation(T);
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