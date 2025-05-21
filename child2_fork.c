
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main(){
    pid_t pid1, pid2;
    pid1=fork();
    if(pid1 == 0){
        printf("Child 1 (PID: %d, Parent PID: %d)\n",getpid(),getppid());
    } else{
        pid2=fork();
        if(pid2==0){

            printf("Child 2 (PID: %d, Parent PID: %d)\n", getpid(), getppid());
        } else{

            printf("Parent(PID: %d) created two children: %d and %d\n", getpid(), pid1, pid2);
        }
    }

    return 0;
}
