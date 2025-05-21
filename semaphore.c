
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>
void *f1();
void *f2();
int shared=1;
sem_t s;
int main()
{pthread_t t1,t2;
sem_init(&s,0,1);
pthread_create(&t1,NULL,f1,NULL);
pthread_create(&t2,NULL,f2,NULL);
pthread_join(t1,NULL);
pthread_join(t2,NULL);
printf("shared memory after update=:%d\n",shared);


}
void *f1(){
int x;
sem_wait(&s);
x=shared;
printf("read t1 shared variable=:%d\n",x);
x++;
printf("locally update after x=:%d\n",x);
sleep(1);
shared=x;
printf("after shared variable update%d\n",shared);
sem_post(&s);
}
void *f2(){
int y;
sem_wait(&s);
y=shared;
printf("read t2 shared variable=:%d\n",y);
y--;
printf("locally update after =:%d\n",y);
sleep(1);
shared=y;
printf("after shared variable update%d\n",shared);
sem_post(&s);}
