#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define TRUE  1
#define FALSE 0

typedef struct  _stPersion{
char cName[16];
int  iAge;
}stPersion;

static int g_iFlag = FALSE;

void* run_task(void* args){
	int jx = 0;
	stPersion *pstW = NULL;
	pstW = (stPersion*)malloc(sizeof(stPersion));
	memset(pstW, 0, sizeof(stPersion));
	
	if(NULL != args){
	memcpy(pstW, (stPersion*)args, sizeof(stPersion));
	}
	printf("name = %s, age=%d\n", pstW->cName, pstW->iAge);
	free(pstW);
	pstW = NULL;	
	for(;jx<2;jx++){
		if(TRUE == g_iFlag){
			printf("exit while cycle.\n");
			g_iFlag = FALSE;
			break;
		}
		usleep(1000*1000);
		printf("task run at %dth cycle\n", jx);
	}
	
	printf("%s end.\n", __FUNCTION__);
}


//int pthread_create(pthread_t *tidp,const pthread_attr_t *attr, 
//(void*)(*start_rtn)(void*),void *arg);

int main()
{
	int ret = 0;
	int ix =0;
	pthread_t tid = 0;
	stPersion *pstLi = NULL;
	pstLi = (stPersion*)malloc(sizeof(stPersion));
	memset(pstLi, 0, sizeof(stPersion));
	memcpy(pstLi->cName, "LiMing", sizeof(pstLi->cName)-1);
	pstLi->iAge = 33;

	printf("start to pthread_create()\n");
	ret = pthread_create(&tid, NULL, run_task, pstLi);
	if(0 != ret)
	{
		printf("error to pthread_create()");
	}
	
	/*for(;ix<10;ix++)
	{
		if(5 == ix)
		{
			g_iFlag = TRUE;
		}
		usleep(1000*1000);
		
		printf("main run at %dth cycle\n", ix);
	}*/

	printf("start to pthread_join()\n");
	pthread_join(tid, NULL);
	printf("end to pthread_join()\n");

free(pstLi);
pstLi = NULL;
	return 0;
}
