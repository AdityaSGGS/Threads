#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<time.h>

void* fun(){
    int number=(rand()%6)+1;
    int *result=malloc(sizeof(int));
    *result=number;
    return (void *) result;
}

int main(int argc, char const *argv[])
{
    int *result;
    srand(time(NULL));
    pthread_t t;
    pthread_create(&t,NULL,fun,NULL);
    pthread_join(t,(void **)&result);
    printf("The value generated is: %d",*result);
    free(result);
    return 0;
}
