
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
int num[3] = {3, 4, 5};
void *thread_function(void *arg) {
    int *x = (int *)arg;
    int sum = x[0] + x[1] + x[2];
    printf("Thread sum: %d\n", sum);
int *result = malloc(sizeof(int));
    *result = sum;
    return result;
}

int main(){
    pthread_t thread;
    void *result;
    pthread_create(&thread, NULL, thread_function, (void *)num);
    pthread_join(thread, &result);
    printf("Main received sum: %d\n", *(int *)result);
    free(result);
    return 0;
}
