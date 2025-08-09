#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

int x=2;

void* fun1(){
    x++;
    sleep(2);
    printf("Value of x: %d.\n",x);
}

void* fun2(){
    // sleep(2);
    printf("Value of x: %d.\n",x);
}

int main(int argc, char const *argv[])
{
    pthread_t t1,t2;
    pthread_create(&t1,NULL,&fun1,NULL);
    pthread_create(&t2,NULL,&fun2,NULL);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);

    return 0;
}
