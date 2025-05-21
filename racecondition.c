#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
void *f1();
void *f2();
int shared=1;
int main()
{pthread_t t1,t2;
pthread_create(&t1,NULL,f1,NULL);
pthread_create(&t2,NULL,f2,NULL);
pthread_join(t1,NULL);
pthread_join(t2,NULL);
printf("shared memory after update=:%d\n",shared);


}
void *f1(){
int x;
x=shared;
printf("read t1 shared variable=:%d\n",x);
x++;
printf("locally update after x=:%d\n",x);
sleep(1);
shared=x;
printf("after shared variable update%d\n",shared);
}
void *f2(){
int y;
y=shared;
printf("read t2 shared variable=:%d\n",y);
y--;
printf("locally update after =:%d\n",y);
sleep(1);
shared=y;
printf("after shared variable update%d\n",shared);
}
