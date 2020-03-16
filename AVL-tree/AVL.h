#pragma once
typedef struct _BiTNode
{	
	int height;
	int data;
	_BiTNode* leftChild;
	_BiTNode* rightChild;
}BiTNode,*pBiTree;

pBiTree CreateAVL(int *data, int size);
pBiTree Insert(pBiTree T, int data);
pBiTree Delete(pBiTree T, int data);


pBiTree DoubleRLRotation(pBiTree T);
pBiTree DoubleLRRotation(pBiTree T);
pBiTree SingleRRotation(pBiTree T);
pBiTree SingleLRotation(pBiTree T);

int Max(int a, int b);
int getHeight(pBiTree T);

void PreOrderTraversal(pBiTree T);

pBiTree Findmin(pBiTree T);
