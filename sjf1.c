#include <stdio.h>
int main(){
    int n,i;
    int p[100],at[100],bt[100],ct[100],tat[100],wt[100],done[100]={0};
    int cur=0,com=0;
    float twt=0,ttt=0;
    printf(" processes: ");
    scanf("%d",&n);
    printf("process IDs:\n");
    for(i=0;i<n;i++)
        scanf("%d",&p[i]);

    printf("at :\n");
    for(i=0;i<n;i++)
        scanf("%d",&at[i]);

    printf("burst :\n");
    for(i = 0; i < n; i++)
        scanf("%d",&bt[i]);
    printf("\norder:\n");
    while(com <n){
        int idx=-1;
        int min_bt=1e9;
        for(i=0;i<n;i++){
            if(!done[i] && at[i] <= cur){
                if(bt[i] < min_bt || (bt[i] == min_bt && at[i] < at[idx])) {
                    min_bt = bt[i];
                    idx = i;
                }
            }
        }
        if(idx != -1){
            ct[idx]=cur+ bt[idx];
            cur= ct[idx];
            done[idx]=1;
            com++;
            printf("P%d ",p[idx]);
        } else {
            cur++;
        }
    }
    for (i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        ttt += tat[i];
        twt += wt[i];
    }

    printf("\n\nProcess\tAT\tBT\tCT\tWT\tTAT\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", p[i], at[i], bt[i], ct[i], wt[i], tat[i]);
    }
    printf("\nAve TAT: %.2f\n", ttt / n);
    printf("Ave WT : %.2f\n", twt / n);

    return 0;
}
