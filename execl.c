#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
int main(){
    pid_t pid;
    int status;
    pid=fork();
    if(pid==0){
       //execl("/bin/ls", "ls", NULL);
        execl("/bin/date"," date",NULL);
        printf("I am child, id: %d\n", getpid());
        //eta hobe na karon execl thik vabe hyese
    } else{
        // Parent 
        wait(&status);
        printf("I am parent\n");
    }
    return 0;
}

