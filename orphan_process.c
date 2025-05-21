
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
int main(){
pid_t pid;
pid=fork();
if(pid==0){
sleep(2);
printf("i am child id:%d\n",getpid());
printf("my parents id:%d\n",getppid());
}
else{
printf("my child%d\n",pid);
printf("i am parent%d\n",getpid());
}



}
