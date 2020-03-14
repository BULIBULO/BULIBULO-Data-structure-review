#pragma once
typedef struct _BiTNode {
	int data;
	_BiTNode* leftChild;
	_BiTNode* rightChild;
}BiTNode, *pBiTree;
void PreOrderTraversal(pBiTree T);
pBiTree CreateBST(int *data,int size);
pBiTree Insert(pBiTree T, int data);
pBiTree Find(pBiTree, int key);
pBiTree Findmin(pBiTree T);
pBiTree Delete(pBiTree T, int data);