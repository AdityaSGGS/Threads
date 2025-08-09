#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

int x=0;
pthread_mutex_t mutex;

void * fun(){
    int i;
    for (i = 0; i < 100000; i++)
    {
        pthread_mutex_lock(&mutex);
        x++;
        pthread_mutex_unlock(&mutex);
    }
    
}


int main(int argc, char const *argv[])
{
    pthread_t t1,t2;
    pthread_mutex_init(&mutex,NULL);
    pthread_create(&t1,NULL,&fun,NULL);
    pthread_create(&t2,NULL,&fun,NULL);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    pthread_mutex_destroy(&mutex);
    printf("Value of x is: %d.\n",x);
    return 0;
}
