#include <stdio.h>
int main() {
    const char *filename = "file1.txt";
if(remove(filename)==0){
        printf("delete %s.\n", filename);
    } else {
        perror("Error");
    }

    return 0;
}

