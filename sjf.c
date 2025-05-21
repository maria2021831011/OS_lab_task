
#include <stdio.h>
int main(){
    int n,i,j,temp;
    int bt[100],wt[100],tat[100],pid[100];
    int total_wt=0,total_tat=0;
    printf("processes: ");
    scanf("%d",&n);
    printf("process:\n");
    for(i=0;i<n;i++){
        scanf("%d",&pid[i]);
    }
    printf("burst:\n");
    for(i=0;i<n;i++){
        scanf("%d",&bt[i]);
    }
    for (i=0;i<n-1;i++){
        for (j=i+1;j<n;j++){
            if (bt[i] > bt[j]){
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
                temp = pid[i];
                pid[i] = pid[j];
                pid[j] = temp;
            }
        }
    }
    wt[0]=0;
    for (i=1;i<n;i++){
        wt[i]=wt[i-1]+bt[i-1];
        total_wt += wt[i];
    }
    for (i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
        total_tat += tat[i];
    }
    printf("\nProcess\tBT\tWT\tTAT\n");
    for (i=0;i<n;i++){
        printf("P[%d]\t%d\t%d\t%d\n", pid[i], bt[i], wt[i], tat[i]);
    }
    printf("\nAvg Waiting  %.2f\n", (float)total_wt / n);
    printf("Avg tat : %.2f\n", (float)total_tat / n);
    printf("\nGantt Chart:\n");

    for (i = 0; i < n; i++) {
        printf(" P[%d] |", pid[i]);
    }

}
