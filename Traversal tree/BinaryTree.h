#pragma once
#include<string>
#define RET_ERROR -1;
#define RET_OK 0;

typedef struct _BiTNode {
	int data;
	_BiTNode* leftChild;
	_BiTNode* rightChild;
}BiTNode, *pBiTree;
/*
���������ַ���
*/
pBiTree CreateBiTree();
pBiTree CreateBiTreeAuto(char s[]);
/*
�����ĵݹ�д��
*/
void PreOrderTraversal(pBiTree T);
void InOrderTraversal(pBiTree T);
void PostOrderTraversal(pBiTree T);
/*
�����ķǵݹ�д��
*/
void PreOrderTraversaln(pBiTree T);
void InOrderTraversaln(pBiTree T);
void PostOrderTraversaln(pBiTree T);


