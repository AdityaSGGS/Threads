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
    pthread_t arr[4];
    pthread_mutex_init(&mutex,NULL);
    int i;
    for(i=0;i<4;i++){
        pthread_create(arr+i,NULL,&fun,NULL);
        printf("Thread %d created.\n",i+1);
    }

    for(i=0;i<4;i++){
        pthread_join(arr[i],NULL);
        printf("Thread %d exited.\n",i+1);
    }
    pthread_mutex_destroy(&mutex);
    printf("Value of x is: %d.\n",x);
    return 0;
}
