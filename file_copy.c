#include<stdio.h>
int main(){
    FILE *source,*target;
    char ch;
    source=fopen("file1.txt", "r");
    if(source == NULL){
        perror("Error");
        return 1;
    }
   target=fopen("file2.txt", "w");
    if (target == NULL) {
        perror("Error");
        fclose(source);
        return 1;
    }
    while((ch=fgetc(source))!= EOF){
        fputc(ch,target);
    }
    printf("successfully.\n");
    fclose(source);
    fclose(target);
    return 0;
}
