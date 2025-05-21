#include<stdio.h>
int main(){
    FILE *fp=fopen("file1.txt", "w");
    if(fp==NULL){
        perror(" failed");
        return 1;
    }
    fprintf(fp,"Hello,C!\n");
    fclose(fp);
    printf("File successfully.\n");
    return 0;
}
