#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10
#define PRINT_MSG(fmt, ...) printf("%s::%d " fmt"\n", __FUNCTION__, __LINE__, ## __VA_ARGS__)
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
        // printf("ix=%d, pHead=%p ,pHead->next=%p\n", pHead->key, pHead, pHead->next);
        printf("%d ", pHead->key);
        pHead = pHead->next;
   }
   printf("\n %s END\n", __FUNCTION__);
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
        //printf("Now clear %d, pHead:%p, pTemp:%p \n", pHead->key, pHead, pTemp);
        printf("%d ", pHead->key);
        pHead->key = 0x0;
        free(pHead);
        pHead = pTemp;
    }
    pTemp = NULL;
    pHead = NULL;
    printf("\n %s end\n", __FUNCTION__);
}
#if 0
void remove_list(stList **ppHead, int count) {
    stList *pt = *ppHead;
    stList *pre = NULL;
    while (count != pt->key) {
        printf("now is %d\n", pt->key);
        pre = pt;
        pt = pt->next;
    }
    printf("now find it:%d\n", pt->key);
    if (pt->key == (*ppHead)->key) {
        printf("should remove the head\n");
        //ppHead = &(pt->next); it is wrong
        *ppHead = pt->next;
    } else {
       printf("should remove the others\n");
       pre->next = pt->next;
    }
    printf("pt = %p\n", pt);
    printf("pt->next = %p\n", pt->next);
    printf("*ppHead = %p\n", *ppHead);
   // pt->next = NULL;
   // free(pt);
    pt = NULL;
    pre = NULL;  
}
#endif
void remove_list(stList **ppHead, int count) {
    //stList **ppLink = NULL;
    //*ppLink = *ppHead;
    stList *pt = *ppHead;
    printf("pt = %p\n", pt);
    while (pt->key != count) {
        ppHead = &(pt->next);
        pt = *ppHead;
    }

    *ppHead = pt->next;
    pt->next = NULL;
    free(pt);
}

void create_list(stList **ppHead, int num) {
    int ix = 0;
    stList *pTemp = NULL;
    stList *pHead = NULL;

    printf("%s enter, create %d node\n", __FUNCTION__, num);
    if (NULL == ppHead) {
        printf("ppHead is null\n");
        return;
    }
    if (NULL != *ppHead) {
        printf("*ppHead is not null\n");
        return;
    }
    for (ix=0; ix<num; ix++) {
       //printf("create %d> pHead=%p \n",ix, pHead);
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
    int num = 12;
    stList *pHead = NULL;
    
    create_list(&pHead, num);
    PRINT_MSG("pHead=%p\n", pHead);
    print_list(pHead);
    remove_list(&pHead, 9);
    PRINT_MSG("pHead=%p\n", pHead);
    print_list(pHead);
#if 0
    invert_list(&pHead); 
    print_list(pHead);
#endif
    clear_list(pHead);
    pHead = NULL; // prevent pHead is wild pointer
    print_list(pHead); 
}
