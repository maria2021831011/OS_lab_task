
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
int shared=1;
int readcount=0;
pthread_mutex_t mutex;
pthread_mutex_t rw_mutex;
void *reader(){
    while (1){
        pthread_mutex_lock(&mutex);
        readcount++;
        if(readcount == 1) {
            pthread_mutex_lock(&rw_mutex);
        }
        pthread_mutex_unlock(&mutex);
        printf("Reader reads shared = %d\n", shared);
        sleep(1);
        pthread_mutex_lock(&mutex);
        readcount--;
        if (readcount == 0) {
            pthread_mutex_unlock(&rw_mutex);
        }
        pthread_mutex_unlock(&mutex);
       sleep(1);
    }
}
void *writer(){
    while (1){
        pthread_mutex_lock(&rw_mutex);
        shared++;
        printf("Writer updates shared to = %d\n", shared);
        sleep(2);

        pthread_mutex_unlock(&rw_mutex);
        sleep(2);
    }
}
int main(){
    pthread_t r1, r2, w1;
   pthread_mutex_init(&mutex, NULL);
    pthread_mutex_init(&rw_mutex, NULL);
    pthread_create(&r1, NULL, reader, NULL);
    pthread_create(&r2, NULL, reader, NULL);
    pthread_create(&w1, NULL, writer, NULL);
    pthread_join(r1, NULL);
    pthread_join(r2, NULL);
    pthread_join(w1, NULL);

    return 0;
}
