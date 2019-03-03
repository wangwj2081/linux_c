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
    printf("%s enter\n", __FUNCTION__);
    if (NULL == pHead) {
        printf("pHead is null\n");
        return;
    }

    while (NULL != pHead) {
        printf("ix=%d, pHead=%p ,pHead->next=%p\n", pHead->key, pHead, pHead->next);
        pHead = pHead->next;
   }
   printf("%s END\n", __FUNCTION__);
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

void clear_list(stList* pHead) {
    stList *pTemp = NULL;
    printf("%s enter\n", __FUNCTION__);
    if (NULL == pHead) {
        printf("pHead is null\n");
        return;
    }

    while (NULL != pHead) {
        pTemp = pHead->next;
        pHead->next = NULL;
        printf("Now clear %d, pHead:%p, pTemp:%p \n", pHead->key, pHead, pTemp);
        pHead->key = 0x0;
        free(pHead);
        pHead = pTemp;
    }
    pTemp = NULL;
    pHead = NULL;
    printf("%s end\n", __FUNCTION__);
}

void create_list(stList **ppHead) {
    int ix = 0;
    stList *pTemp = NULL;
    stList *pHead = NULL;
    if (NULL == ppHead) {
        printf("ppHead is null\n");
        return;
    }
    if (NULL != *ppHead) {
        printf("*ppHead is not null\n");
        return;
    }
    for (ix=0; ix<N; ix++) {
        printf("create %d> pHead=%p \n",ix, pHead);
        pTemp = (stList *)malloc(sizeof(stList));
        pTemp->key = ix;
        pTemp->next = pHead;
        pHead = pTemp;
        pTemp = NULL;
    }
    *ppHead = pHead; //do not forget to get the addr
    printf("%s end\n", __FUNCTION__);
}

void main() {
    int ix;
    stList *pHead = NULL;
#if 0    
    stList *pTemp = NULL;
    for (ix=0; ix<N; ix++) {
        printf("create %d> pHead=%p \n",ix,  pHead);
        pTemp = (stList *)malloc(sizeof(stList));
        pTemp->key = ix;
        pTemp->next = pHead;
        pHead = pTemp;
        pTemp = NULL;
    }
#endif
    create_list(&pHead);
    print_list(pHead);
#if 0
    invert_list(&pHead); 
    print_list(pHead);
#endif
    clear_list(pHead);
    pHead = NULL; // prevent pHead is wild pointer
    print_list(pHead); 
}
