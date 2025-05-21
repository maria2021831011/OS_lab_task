#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
int shared=0;
void* producer(void* arg){
    for(int i=0;i<5;i++){
        int val=shared;
        printf("Producer reads: %d\n",val);
        val++;
        sleep(1);
        shared=val;
        printf("Producer writes: %d\n",shared);
    }
    return NULL;
}

void* consumer(void* arg){
    for(int i=0;i<5;i++){
        int val=shared;
        printf("Consumer reads: %d\n",val);
        val--;
        sleep(1);
        shared=val;
        printf("Consumer writes: %d\n",shared);
    }
    return NULL;
}
int main(){
    pthread_t t1, t2;
    pthread_create(&t1, NULL, producer, NULL);
    pthread_create(&t2, NULL, consumer, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    printf("Final shared value: %d\n", shared);
    return 0;
}
