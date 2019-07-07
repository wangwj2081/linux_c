/*****************************************
* 1. pthread_cond_t  is used with pthread_mutex_t
* 2. learn how to use pthread_cond_timewait()
* 3. the program create 2 pthreads. one is to produce products and the 2th is to sell products
********************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> /* usleep() */
#include <pthread.h>
//#include <sys/time.h>
#include <time.h>

#define PRODUCE_UNIT 20

typedef struct _stMsg
{    
    pthread_mutex_t lock;
    pthread_cond_t cond;
}stMsg;

static int flag = 1;
static int iProductNum = 150;

//pthread_mutex_t lock;
//pthread_cond_t cond;
//stMsg msg_produce;
//stMsg msg_sell;
//pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
//pthread_cond_t cond = PTHREAD_COND_INITIALIZER; 

/********
defore using pthread_cond_timedwait(), set up 3 steps:
1£ºmutex lock£º  pthread_mutex_lock(&__mutex)
2: wait:         pthread_cond_timedwait(&__cond, &__mutex, &__abstime) // unlock -> wait -> lock
3: mutex unlock: pthread_mutex_unlock(&__mutex)
************/

void * thd_produce(void * p_arg)
{
	int ix = 0;
    stMsg *pmsg = (stMsg*)p_arg;
    printf("%s(), start, iProductNum=%d\n", __FUNCTION__, iProductNum);
	struct timeval now;
	struct timespec outtime;

	while(1 == flag)
	{
		pthread_mutex_lock(&(pmsg->lock));
		#if 1
		if(iProductNum >= 100)
		{
            printf("productNum > 100.Now have a rest, but rest time is 5s\n");
			gettimeofday(&now, NULL);
			outtime.tv_sec = now.tv_sec + 5;
			outtime.tv_nsec = now.tv_usec * 1000;

			pthread_cond_timedwait(&(pmsg->cond), &(pmsg->lock), &outtime);
		    printf("produce tast wake up.\n");
		}
        #endif
		
        printf("start to produce , productNum=%d\n", iProductNum); 
		iProductNum += 10;
		pthread_mutex_unlock(&(pmsg->lock));
        usleep(1000*1000);
	}

	printf("%s() end\n", __FUNCTION__);
}

void * thd_sell(void * p_arg)
{
	int ix = 0;
	int num = 0;
    stMsg* pmsg = (stMsg*)p_arg;

    printf("%s(), start, iProductNum=%d\n", __FUNCTION__, iProductNum);
    for(ix = 0; ix < 100; ix++)
    {
        pthread_mutex_lock(&pmsg->lock);
        if (iProductNum < 30)
        {
            printf("Product is not enouth.must produce\n");
            pthread_cond_signal(&pmsg->cond);
        }
        printf("start to sell , productNum=%d\n", iProductNum); 
        iProductNum -= 5;
        pthread_mutex_unlock(&pmsg->lock);
        usleep(1000*1000);
    }
	printf("flag = %d\n", flag);
	flag = 0;
	printf("%s() end\n", __FUNCTION__);
}

void msg_init(stMsg *pMsg)
{
    pthread_mutex_init(&(pMsg->lock), NULL);
	pthread_cond_init(&(pMsg->cond), NULL);
}

void msg_uninit(stMsg *pMsg)
{
    pthread_mutex_destroy(&(pMsg->lock));
	pthread_cond_destroy(&(pMsg->cond));
}

int main()
{
    int ret = 0;
    pthread_t tid;
    pthread_t tid2;
    stMsg msg;

    msg_init(&msg);
    //pthread_mutex_init(&lock, NULL);
	//pthread_cond_init(&cond, NULL);
	ret = pthread_create(&tid, NULL, thd_produce, &msg);
	if(ret < 0)
	{
		printf("fail to pthread_create()\n");
		goto end;
	}

	ret = pthread_create(&tid2, NULL, thd_sell, &msg);
	if(ret < 0)
	{
		printf("fail to pthread_create()\n");
		goto end;
	}

    pthread_join(tid, NULL);
    pthread_join(tid2, NULL);

end:	
    //pthread_mutex_destroy(&lock);
	//pthread_cond_destroy(&cond);
    msg_uninit(&msg);
    return ret;
}

