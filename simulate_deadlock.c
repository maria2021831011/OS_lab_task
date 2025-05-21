#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<pthread.h>
void *f1();
void *f2();
pthread_mutex_t first_mutex,second_mutex;
int main(){
//initialize
pthread_mutex_init(&first_mutex,NULL);
pthread_mutex_init(&second_mutex,NULL);
pthread_t t1,t2;
pthread_create(&t1,NULL,f1,NULL);
pthread_create(&t2,NULL,f2,NULL);
pthread_join(t1,NULL);
pthread_join(t2,NULL);
printf("join successfully\n");
}
void *f1(){
printf("t1 acquired first mutex\n");
pthread_mutex_lock(&first_mutex);
printf("t1 acquired\n");
sleep(1);
printf("t1 acquired second mutex\n");
pthread_mutex_lock(&second_mutex);
printf("t1 acquired\n");
pthread_mutex_unlock(&first_mutex);

}
void *f2(){
printf("t2 acquired second mutex\n");
pthread_mutex_lock(&second_mutex);
printf("t2 acquired\n");
sleep(1);
printf("t2 acquired first mutex\n");
pthread_mutex_lock(&first_mutex);
printf("t2 acquired\n");
pthread_mutex_unlock(&second_mutex);}
