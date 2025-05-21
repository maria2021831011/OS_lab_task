
#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#define BUFFER_SIZE 5
int buffer[BUFFER_SIZE];
int in=0,out=0;
int counter=0;
void* producer(void* arg){
    int item=1;
    while(item<=10){
        while(counter==BUFFER_SIZE);
        buffer[in]=item;
        printf("Producer produced: %d at index %d\n",item, in);
        in=(in + 1)% BUFFER_SIZE;
        counter++;
        item++;
        sleep(1);
    }
    return NULL;
}

void* consumer(void* arg){
    int item;
    for(int i=0;i<10;i++) {
        while(counter==0);
        item = buffer[out];
        printf("Consumer consumed: %d from index %d\n", item, out);
        out=(out + 1) % BUFFER_SIZE;
        counter--;
        sleep(1);
    }
    return NULL;
}

int main(){
    pthread_t t1, t2;
    pthread_create(&t1, NULL, producer, NULL);
    pthread_create(&t2, NULL, consumer, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    printf("Done\n");
    return 0;
}
