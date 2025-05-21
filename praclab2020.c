
#include <stdio.h>
#define MAX 100
int main(){
    FILE *fin=fopen("task a input.txt", "r");
    FILE *fout=fopen("task a output.txt", "w");
    int n,quantum,target;
    int burst[MAX],remaining[MAX], waiting[MAX]={0};
    int completed[MAX]={0};
    char buffer[100];
    // Read n
    fgets(buffer,sizeof(buffer),fin);
    fscanf(fin,"%d",&n);
    // Read quantum
    fgets(buffer,sizeof(buffer),fin);
    fscanf(fin,"%d",&quantum);
    // Read burst
    fgets(buffer,sizeof(buffer),fin);
    for (int i=0; i<n;i++){
        fscanf(fin,"%d",&burst[i]);
        remaining[i]=burst[i];
    }
    fgets(buffer,sizeof(buffer),fin);
    fscanf(fin,"%d",&target);
    target--;
    int time=0,done=0;
    while(done<n){
        for(int i=0;i<n;i++){
            if(remaining[i] > 0){
                int exec=(remaining[i]> quantum)?quantum:remaining[i];
                time += exec;
                remaining[i] -= exec;
                for(int j = 0; j < n; j++){
                    if(j != i && remaining[j] > 0){
                        waiting[j]+=exec;
                    }
                }
                if(remaining[i]==0){
                    done++;
                }
            }
        }
    }

    printf("Wt %d is: %d\n",target + 1,waiting[target]);
    fprintf(fout, "Waiting Time  %d is: %d\n",target + 1,waiting[target]);
    fclose(fin);
    fclose(fout);

    return 0;
}
