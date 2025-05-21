#include <stdio.h>
int main(){
    FILE *fp=fopen("file1.txt", "w");
    if(fp==NULL){
        perror("File creation failed");
        return 1;
    }

    fprintf(fp, "Hello, this file is created from C!\n");
    fclose(fp);
    printf("File successfully.\n");
    return 0;
}
