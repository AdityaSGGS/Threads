#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>


void* fun(){
    printf("Hi thread.\n");
    sleep(3);
    printf("Ending thread.\n");
}

int main(int argc, char const *argv[])
{
    pthread_t t1;
    pthread_t t2;
    pthread_create(&t1,NULL,&fun,NULL);
    pthread_create(&t2,NULL,&fun,NULL);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    return 0;
}
