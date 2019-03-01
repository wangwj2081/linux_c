#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10
#define TEST_MSG_ERROR(fmt, ...) fprintf(stderr, "VT_ERROR %s::%d " fmt"\n",__FUNCTION__, __LINE__,## __VA_ARGS__)
#define print(fm, ...) printf(fm"line:%d \n", ##__VA_ARGS__, __LINE__)

typedef struct _LIST {
    int key;
    struct _LIST *next;
} stList;

void print_list(stList *pHead)
{
    stList *pTemp = NULL;
    if (NULL == pHead) {
        printf("pHead is null\n");
        return;
    }

    pTemp = pHead;
    while (NULL != pTemp) {
    printf("ix=%d ", pTemp->key);
    pTemp = pTemp->next;
   }
   printf("\n");
   return;
}
void invert_list(stList **pHead) {
    stList *pT = NULL;
    stList *pTail = NULL;
 
    if (NULL == pHead) {
        printf("pHead is null\n");
        return;
    }
    
    while (NULL != (*pHead)->next) {
        pT = (*pHead)->next;
        (*pHead)->next = pTail;
        pTail = (*pHead);
        (*pHead) = pT;
    }
    (*pHead)->next = pTail;//keep head connect to the previous list
    return;
}

void main() {
    stList *pHead = NULL;
    int ix;
    stList *pTemp = NULL;

    for (ix=0; ix<N; ix++) {
        printf("\n %d> pHead=%p",ix,  pHead);
        pTemp = (stList *)malloc(sizeof(stList));
        pTemp->key = ix;
        pTemp->next = pHead;
        pHead = pTemp;
        pTemp = NULL;
        printf(" pHead=%p, next=%p", pHead, pHead->next);
        pTemp = NULL;
    }
    printf("\n");

    print_list(pHead);
    invert_list(&pHead); 
    print_list(pHead);    
}
