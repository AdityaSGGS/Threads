#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>


void* fun(){
    printf("Hi thread");
}

int main(int argc, char const *argv[])
{
    pthread_t t1;
    pthread_create(&t1,NULL,&fun,NULL);
    pthread_join(t1,NULL);
    return 0;
}
