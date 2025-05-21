#include <stdio.h>
int main(){
    int n,i,time=0,tq,remain;
    int p[100],at[100],bt[100] ,rt[100],ct[100],tat[100],wt[100];
    float ttt=0,twt=0;
    printf(" processes: ");
    scanf("%d",&n);
    printf(" Process IDs:\n");
    for(i=0;i<n;i++)
        scanf("%d",&p[i]);
    printf("at:\n");
    for(i=0;i<n;i++)
        scanf("%d",&at[i]);
    printf("burst:\n");
    for(i=0;i<n;i++){
        scanf("%d",&bt[i]);
        rt[i]=bt[i];
    }
    printf("quantum: ");
    scanf("%d",&tq);
    remain=n;
    printf("\nchart:\n");
    int done[100]={0};
    while(remain>0){
        int flag=0;
        for(i=0;i< n;i++){
            if(at[i] <= time && rt[i] > 0){
                flag = 1;
                if(rt[i] > tq){
                    printf("| P%d ",p[i]);
                    time += tq;
                    rt[i] -= tq;
                } else{
                    printf("| P%d ", p[i]);
                    time += rt[i];
                    ct[i] = time;
                    rt[i] = 0;
                    done[i] = 1;
                    remain--;
                }
            }
        }
        if(flag == 0){
            time++;
        }
    }
    printf("|\n");
    for(i = 0; i < n; i++){
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        ttt += tat[i];
        twt += wt[i];
    }
    printf("\nProcess\tAT\tBT\tCT\tWT\tTAT\n");
    for(i = 0; i < n; i++){
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", p[i], at[i], bt[i], ct[i], wt[i], tat[i]);
    }
    printf("\nAverage Waiting Time: %.2f\n", twt / n);
    printf("Average Turnaround Time: %.2f\n", ttt / n);

    return 0;
}
