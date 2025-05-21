
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
#include <stdlib.h>
int main(){
pid_t pid;
pid=fork();
if(pid==0){
printf("i am child id:%d\n",getpid());
printf("my parents id:%d\n",getppid());
exit(0);
}
else{
sleep(5);
printf("my child%d\n",pid);
printf("i am parent%d\n",getpid());
//wait(NULL);//
}
}
