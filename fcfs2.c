#include<stdio.h>
int main(){
    int n, i;
    int bt[100],wt[100];
    printf("number: ");
    scanf("%d",&n);
    printf("burst:\n");
    for(i=0;i<n;i++){
        scanf("%d",&bt[i]);
    }
    wt[0]=0;
    for (i=1;i<n;i++){
        wt[i]=wt[i-1]+bt[i-1];
    }

    printf("\nWaiting times:\n");
    for (i=0;i<n; i++){
        printf("%d ",wt[i]);
    }
    printf("\n");

    return 0;
}
