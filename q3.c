#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
int main(){
    int n;
    char buff[1024];
    int sender, receiver;
    sender = open("f1.txt", O_RDONLY);
    receiver = open("f2.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
  while((n = read(sender, buff, sizeof(buff))) > 0) {
        write(receiver, buff, n);
    } close(sender);
    close(receiver);
    return 0;
}
