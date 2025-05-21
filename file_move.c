#include <stdio.h>
int main() {
    const char *old="file2.txt";
    const char *new= "moved_file1.txt";
    if(rename(old,new) == 0){
        printf("File moved/renamed successfully'%s'to'%s'.\n",old, new);
    } else {
        perror("Error");
    }

    return 0;
}

