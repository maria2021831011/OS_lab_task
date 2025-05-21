#include <stdio.h>
int main(){
    int n,i,j,temp;
    int bt[100],pr[100],wt[100],tat[100],p[100];
    int total_wt=0,total_tat=0;
    printf(" processes: ");
    scanf("%d",&n);
     printf("process:\n");
    for(i=0;i<n;i++){
        scanf("%d",&p[i]);
    }
    printf("burst:\n");
    for(i=0;i<n;i++){
        scanf("%d",&bt[i]);
    }
    printf("Priorities:\n");
    for(i = 0;i<n; i++) {
        scanf("%d", &pr[i]);
    }
    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++){
            if(pr[i] > pr[j]){
                temp = pr[i]; pr[i] = pr[j]; pr[j] = temp;
                temp = bt[i]; bt[i] = bt[j]; bt[j] = temp;
                temp = p[i]; p[i] = p[j]; p[j] = temp;
            }
        }
    }
    wt[0]=0;
    for(i=1;i<n;i++){
        wt[i]=wt[i - 1] + bt[i - 1];
        total_wt += wt[i];
    }
    for(i=0;i< n;i++){
        tat[i]=bt[i]+wt[i];
        total_tat += tat[i];
    }
    printf("\nProcess\tPriority\tBT\tWT\tTAT\n");
    for(i = 0; i < n; i++) {
        printf("P[%d]\t%d\t\t%d\t%d\t%d\n", p[i], pr[i], bt[i], wt[i], tat[i]);
    }
    printf("\nAvg wt: %.2f\n", (float)total_wt / n);
    printf("Avg tat: %.2f\n", (float)total_tat / n);

    return 0;
}
