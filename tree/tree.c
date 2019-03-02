#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAG "TREE"
#define print_err(fmt, ...) printf("%s E "fmt" in %s, line:%d\n", TAG, ##__VA_ARGS__, __FUNCTION__, __LINE__)
#define print_msg(fmt, ...) printf("%s M "fmt" in %s, line:%d\n", TAG, ##__VA_ARGS__, __FUNCTION__, __LINE__)

typedef struct _NODE {
    char cK;
    struct _NODE * left;
    struct _NODE * right;
} stTree, *pstTree;
/***********
1. 二叉树的第i层最多的节点数有2^(i-1),i>=1
2.深度为k的二叉树最多的节点数是2^k-1,k>=1
3.前序遍历:NLR, 中序遍历:LNR, 后序遍历:LRN
************/

int create_tree(stTree **ppTree) {
    char c = 0x00;
    printf("Plsease input a char and # is over: \n");
    scanf("%c", &c);
    getchar();
    if ('#' == c) {
        *ppTree = NULL;
        return 1;
    } else {
        *ppTree = (stTree*)malloc(sizeof(stTree));
        if (NULL == *ppTree) {
            printf("error: malloc null\n");
            return 2;
        }
        (*ppTree)->cK = c;
        create_tree(&((*ppTree)->left));
        create_tree(&((*ppTree)->right));
    }
    printf("finish to create tree\n");
    return 0;
}


void preOrder(stTree *pTree) {
    if (NULL == pTree) {
        return;
    }
    printf("%c ", pTree->cK);
    preOrder(pTree->left);
    preOrder(pTree->right);
}

main(void) {
	stTree *pRoot = NULL;
    //ABDG##H###CE#I##F##
    create_tree(&pRoot);	
	preOrder(pRoot);
    printf("\n");
}

