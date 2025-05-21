#include <stdio.h>
int main(){
    int n,i;
    int p[100],at[100],bt[100],priority[100],ct[100],tat[100],wt[100],done[100]={0};
    int cur=0,com=0;
    float twt=0,ttt=0;
    printf("Processes: ");
    scanf("%d",&n);

    printf("Process :\n");
    for(i=0;i<n;i++)
        scanf("%d",&p[i]);

    printf("at:\n");
    for(i=0;i<n;i++)
        scanf("%d",&at[i]);

    printf("bt:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &bt[i]);

    printf("Priorities:\n");
    for(i=0;i<n;i++){
       scanf("%d",&priority[i]);}

    printf("\order:\n");
    while(com < n){
        int idx = -1;
        int min_prio = 1e9;
        for (i = 0; i < n; i++) {
            if (!done[i] && at[i] <= cur) {
                if (priority[i] < min_prio ||
                    (priority[i] == min_prio && at[i] < at[idx])) {
                    min_prio = priority[i];
                    idx = i;
                }
            }
        }
        if(idx != -1) {
            ct[idx] = cur + bt[idx];
            cur = ct[idx];
            done[idx] = 1;
            com++;
            printf("P%d ", p[idx]);
        } else{
            cur++;
        }
    }
    for(i = 0; i < n; i++) {
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
        ttt+=tat[i];
        twt+=wt[i];
    }
    printf("\n\nProcess\tAT\tBT\tPri\tCT\tWT\tTAT\n");
    for(i=0;i<n;i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n", p[i],at[i],bt[i],priority[i],ct[i],wt[i],tat[i]);
    }
    printf("\navg tat: %.2f\n",ttt / n);
    printf("avg wt : %.2f\n",twt / n);
    return 0;
}
