
#include<stdio.h>
int main(){
    int n,i;
    int p[100],at[100],bt[100],priority[100];
    int ct[100],tat[100],wt[100],done[100]={0},rem_bt[100];
    int cur=0,com=0;
    float ttt=0,twt=0;
    printf(" processes: ");
    scanf("%d",&n);
    printf(" Process IDs:\n");
    for(i=0;i<n;i++)
        scanf("%d",&p[i]);

    printf("at:\n");
    for(i=0;i<n;i++)
        scanf("%d",&at[i]);

    printf("bt:\n");
    for(i=0;i<n;i++){
        scanf("%d",&bt[i]);
        rem_bt[i]=bt[i];
    }
    printf(" Priorities :\n");
    for(i=0;i<n;i++)
        scanf("%d",&priority[i]);
    int prev=-1;
    printf("\nGantt Chart:\n");
    while(com<n){
        int idx=-1,min_prio=1e9;
        for(i = 0; i < n; i++){
            if(!done[i] && at[i] <= cur && rem_bt[i] > 0){
                if(priority[i]<min_prio ||(priority[i] == min_prio && at[i]<at[idx])){
                    min_prio=priority[i];
                    idx = i;
                }
            }
        }
        if(idx!=-1){
            rem_bt[idx]--;
            if(prev!=idx) {
                printf("| P%d ",p[idx]);
                prev=idx;
            }
            cur++;
            if(rem_bt[idx] == 0){
                ct[idx]=cur;
                done[idx]=1;
                com++;
            }
        } else {
            cur++;
        }
    }
    printf("|\n");
    for(i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        ttt += tat[i];
        twt += wt[i];
    }
    printf("\nProcess\tAT\tBT\tPrio\tCT\tWT\tTAT\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n", p[i], at[i], bt[i], priority[i], ct[i], wt[i], tat[i]);
    }
    printf("\nAverage Waiting Time: %.2f\n", twt / n);
    printf("Average Turnaround Time: %.2f\n", ttt / n);

    return 0;
}
