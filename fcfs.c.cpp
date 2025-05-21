#include <stdio.h>
int main() {
    int n,i,j;
    int p[100],at[100],bt[100],ct[100],tat[100],wt[100];
    int tmp,total_wt=0,total_tat=0;
    printf("enter process: ");
    scanf("%d",&n);

    printf("pocess id:\n");
    for(i=0;i<n;i++){
        scanf("%d",&p[i]);
    }

    printf("arrival:\n");
    for (i=0;i<n;i++){
        scanf("%d",&at[i]);
    }

    printf("burst :\n");
    for (i=0;i<n;i++){
        scanf("%d",&bt[i]);
    }

   
    for (i=0;i<n-1;i++){
        for (j=i+1;j<n;j++){
            if (at[i]>at[j]){
                tmp=at[i];at[i]=at[j];at[j]=tmp;
                tmp=bt[i];bt[i]=bt[j];bt[j]=tmp; 
                tmp=p[i];p[i]=p[j];p[j]=tmp;
            }
        }
    }
    int cur=0;
    for(i=0;i<n;i++){
        if (cur<at[i]){
            cur=at[i]; 
        }
        cur+=bt[i];
        ct[i]=cur;
    }
    for(i=0;i<n;i++){
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
        total_tat+=tat[i];
        total_wt+=wt[i];
    }
    printf("\nProcess\tAT\tBT\tCT\tWT\tTAT\n");
    for(i=0;i<n;i++){
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", p[i], at[i], bt[i], ct[i], wt[i], tat[i]);
    }
    printf("\nAvg TAT:%.2f\n",(float)total_tat/n);
    printf("Avg WT:%.2f\n",(float)total_wt/n);

    return 0;
}