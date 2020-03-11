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
建树的两种方法
*/
pBiTree CreateBiTree();
pBiTree CreateBiTreeAuto(char s[]);
/*
遍历的递归写法
*/
void PreOrderTraversal(pBiTree T);
void InOrderTraversal(pBiTree T);
void PostOrderTraversal(pBiTree T);
/*
遍历的非递归写法
*/
void PreOrderTraversaln(pBiTree T);
void InOrderTraversaln(pBiTree T);
void PostOrderTraversaln(pBiTree T);


