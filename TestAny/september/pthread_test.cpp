//
//  pthread_test.cpp
//  TestAny
//
//  Created by delims on 2020/8/21.
//  Copyright © 2020 delims. All rights reserved.
//

#include "pthread_test.hpp"
#include <pthread/pthread.h>
#include <semaphore.h>
#include <unistd.h>


void *newThread(void *p){
    for (int i = 0; i < 2; i ++) {
        printf("I am new thread\n");
        sleep(1);
    }
    return NULL;
}

static pthread_key_t my_thread_key;

void craeteKey(void)
{
    printf("create Key invoke \n");
    pthread_key_create(&my_thread_key, __DARWIN_NULL);
}

void freeKey(long *win)
{
    delete win;
}


void *createLong(void*)
{
    long *i = new long;
    *i = 1000;
    
    static pthread_once_t once; //16字节结构体，静态变量所有线程共享。
    pthread_once(&once, craeteKey); //不管有多少线程都执行一次craeteKey()。key只有一个。
    
    
    
    printf("pthread_setspecific \n");
    pthread_setspecific(my_thread_key, i); //不同的线程有不同的线程数据。
    return 0;
}

pthread_mutex_t mutex;
struct timespec delay;

static long money;

void product(void)
{
    while (1) {
        
        int ret = 1;
        while (ret) {
            ret = pthread_mutex_trylock(&mutex);;
        }
        money ++;
        printf("earn  money %ld\n",money);
        pthread_mutex_unlock(&mutex);
        usleep(2000000);
    }
    
}

void *consume(void*)
{
    printf("%p \n",pthread_self());
    
    while (1) {
        
        int ret = 1;
        while (ret) {
            ret = pthread_mutex_trylock(&mutex);
        }
        
        while (money <= 0) {
            pthread_mutex_unlock(&mutex);
            
            int ret = 1;
            while (ret) {
                ret = pthread_mutex_trylock(&mutex);
            }
        }

        money --;
        printf("speed money %ld\n",money);
        pthread_mutex_unlock(&mutex);
        usleep(5000);
    }
    return 0;
}


void pthread_test(void)
{
//    pthread_t ptd;
//    pthread_create(&ptd, NULL, createLong, NULL);
//    for (int i = 0; i < 5; i ++) {
//        printf("I am main thread\n");
//        sleep(1);
//    }
    
//    createLong(__DARWIN_NULL);
    
//    int ret = pthread_join(ptd, NULL);//等待这个线程执行完了在继续执行。
//    sleep(1);
//    void *p = pthread_getspecific(my_thread_key); //不同线程中通过同一个key取出不同的数据。也就是线程数据。
    
//    printf("ret = %i \n",ret);
//    printf("key value = %li \n",*(long *)p);
    
//    pthread_mutexattr_t pthread_attr;
//    pthread_mutexattr_init(&pthread_attr);
//    pthread_mutex_init(&mutex, &pthread_attr);
//    
//    pthread_t pro_thread;
//    pthread_t con_thread;
//    
//    pthread_create(&pro_thread, __DARWIN_NULL, (void*(*)(void*))product, __DARWIN_NULL);
//    pthread_create(&con_thread, __DARWIN_NULL, (void*(*)(void*))consume, __DARWIN_NULL);
//    
//    printf("消费者，%p \n",con_thread);
//    
//    pthread_join(pro_thread, __DARWIN_NULL);
//
//    
//    
//    
//    sem_t sem;
//    
//    sem_init(&sem, 0, 3);
//    sem_post(&sem);
//    sem_wait(&sem);
    

}
