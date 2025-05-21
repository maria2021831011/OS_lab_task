
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
int main(){
    int n;
    int buff[15];
    int f1, f2;
    f1 = open("f1.txt", O_RDONLY);
    f2 = open("f2.txt", O_WRONLY | O_APPEND);
    n = read(f1, buff, 15);
    write(f2, buff, n);
    close(f1);
    close(f2);
    return 0;
}
