#include <stdio.h>

int main(){
    int classNum[3]={0,0,0};
    int classTime[3]={0,0,0};
    int i,j;
    int classList[3][6] = {{0,0,0,0,0,0},
                            {0,0,0,0,0,0},
                            {0,0,0,0,0,0}};
    for(j=0;j<3;j++){
        scanf(" %d",&classNum[j]);
        scanf(" %d",&classTime[j]);
        for(i=0;i<classTime[j];i++){
            scanf(" %d",&classList[j][i]);
        }

    }
    for(j=0;j<classTime[0];j++){
        for(i=0;i<classTime[1];i++){
            if(classList[0][j]==classList[1][i]){
                printf("%d and %d conflict on %d",classNum[0],classNum[1],classList[0][j]);
            }
        }
    }
    for(j=0;j<classTime[0];j++){
        for(i=0;i<classTime[2];i++){
            if(classList[0][j]==classList[2][i]){
                printf("%d and %d conflict on %d",classNum[0],classNum[2],classList[0][j]);
            }
        }
    }
    for(j=0;j<classTime[2];j++){
        for(i=0;i<classTime[1];i++){
            if(classList[2][j]==classList[1][i]){
                printf("%d and %d conflict on %d",classNum[1],classNum[2],classList[2][j]);
            }
        }
    }
    return 0;
}
