#include <stdio.h>

int main(){
    double Cpm[3][5] = {{0.08,0.1393,0.1349,1.1287,1.4803},
                        {0.07,0.1304,0.1217,1.1127,1.2458},
                        {0.06,0.1087,0.1018,0.9572,1.1243}};
    int i,j;
    double sum[3]={0,0,0};
    for(i=0;i<5;i++){
        int tmp;
        scanf(" %d",&tmp);
        for(j=0;j<3;j++){
            sum[j]+=tmp*Cpm[j][i];
           // printf("%f\n",sum[j]);
        }
    }
    if((sum[0]-183)<0){
        printf("183型\n");
    }else if(sum[0]<383)        printf("%d\n",ip);{
        printf("183型\n");
    }else if(sum[1]-383<0){
        printf("383型\n");
    }else if(sum[1] < 983){
        printf("383型\n");
    }else{
        printf("983型\n");
    }

    return 0;
}
