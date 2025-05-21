
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main(){
pid_t pid;
printf("before fork\n");
pid=fork();
if(pid==0){//child
printf("i am child having id %d\n",getpid());
printf("my parents id is %d\n",getppid());
}else
{
//parent part
printf("my child id is %d\n",pid);
printf("i am parent having id %d\n",getpid());

}
}
