
#include<stdio.h>
#include<unistd.h>
int main(){
int n;
int buff[15];
n=read(0,buff,15);
write(1,buff,n);}
