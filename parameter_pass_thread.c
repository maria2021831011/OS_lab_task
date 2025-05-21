
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<pthread.h>
void *thread_function(void *arg);
int num[3]={3,4,5};
int main()
{
pthread_t a_thread;
void *result;
pthread_create(&a_thread,NULL,thread_function,(void*)num);
pthread_join(a_thread,&result);
printf("main part\n");
printf("from thread %s\n",(char*)result);


}
void *thread_function(void *arg)
{
int *x=arg;
int sum=x[0]+x[1]+x[2];
printf("thread %d\n",sum);
pthread_exit("result give");

}
