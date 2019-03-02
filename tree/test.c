#include<stdio.h>
#include<stdlib.h>
typedef struct BiTNode {
 char data;
 struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

void PreOrderTraverse(BiTree T)//二叉树的先序遍历 
{ 
if(T==NULL) return ; 
printf("%c ",T->data); 
PreOrderTraverse(T->lchild); 
PreOrderTraverse(T->rchild); 
} 
void InOrderTraverse(BiTree T)//二叉树的中序遍历 
{ 
if(T==NULL) return ; 
InOrderTraverse(T->lchild); 
printf("%c ",T->data); 
InOrderTraverse(T->rchild); 
} 

void PostOrderTraverse(BiTree T)//后序遍历 
{ 
if(T==NULL) return; 
PostOrderTraverse(T->lchild);
PostOrderTraverse(T->rchild); 
printf("%c ",T->data); 
} 
#if 0
void CreateBiTree(BiTree *T) { 
  char ch; 
  scanf("%c",&ch); 
  if(ch=='#') {
    *T=NULL;
  } else { 
    *T=(BiTree )malloc(sizeof(BiTNode)); 
    if(NULL == *T) 
      exit(-1); 
    (*T)->data=ch; 
    CreateBiTree(&(*T)->lchild); 
    CreateBiTree(&(*T)->rchild); 
  } 
} 
#endif
void CreateBiTree(BiTree *T) { 
BiTree temp = NULL;
temp = (BiTree)malloc(sizeof(BiTNode));
temp->data= 'B';
temp->lchild = NULL;
temp->rchild = NULL;
*T = temp;

temp = (BiTree)malloc(sizeof(BiTNode));
temp->data= 'A';
temp->lchild = NULL;
temp->rchild = NULL;
(*T)->lchild= temp;

temp = (BiTree)malloc(sizeof(BiTNode));
temp->data= 'C';
temp->lchild = NULL;
temp->rchild = NULL;
(*T)->rchild = temp;
}

int main() { 
  BiTree T; 
  CreateBiTree(&T);
  printf("\n"); 
  PreOrderTraverse (T); 
  printf("\n"); 
  InOrderTraverse(T); 
  printf("\n"); 
  PostOrderTraverse(T); 
  printf("\n"); 
  return 0; 
}
/**
--------------------- 

作者：dream0130__ 

来源：CSDN 

原文：https://blog.csdn.net/dream0130__/article/details/80779486 

版权声明：本文为博主原创文章，转载请附上博文链接！
**/
