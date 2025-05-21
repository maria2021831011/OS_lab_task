#include<stdio.h>
#include<unistd.h>
#include<string.h>
int main(){char buffer[30];
write(1,"enter some",11);
int ss=read(0,buffer,sizeof(buffer));
write(1,"output",7);
write(1,buffer,ss);
}
