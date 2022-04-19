#include <stdio.h>
#include <string.h>
int main(){
    int i,j;
    float sum[2]={0,0};
    for(i=0;i<2;i++){
        for(j=0;j<3;j++){
            char ip;
            scanf(" %c",&ip);
          //  printf("%d\n",ip);
            int num = ip-48;
            float result;
            if(num==17){
                result=1;
            }else if(num==26 ||num==33 ||num==27 ){
                result=0.5;
            }else if(num==1){
                result=10;
                fflush(stdin);
            }else{
                result=num;
            }


            sum[i]+=result;
            //printf("%.1f\n",sum[i]);
        }
    }
    for(i=0;i<2;i++){
        if(sum[i]>10.5){
            sum[i]=0;
        }
    }
    printf("%.1f\n",sum[0]);
    printf("%.1f\n",sum[1]);
    if(sum[0]>sum[1]){
        printf("A wins.\n");
    }else if(sum[1]>sum[0]){
        printf("B wins.\n");
    }else{
        printf("It's a tie.\n");
    }
    return 0;
}
