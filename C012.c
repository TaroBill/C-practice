#include <stdio.h>
#include <math.h>

int main(){
    int state=0;
    int bits,num,i=0;
    int result=0,x,tmp;
    while(state==0){
        scanf(" %d %d",&bits,&num);
       // printf("bits : %d num : %d\n",bits,num);
        result=0;
        i=0;
        if(num !=0){

            tmp = num % 2;
            num = num >> 1;
           // printf("num : %d\n",num);
            //printf("tmp : %d\n",tmp);
            while(num>0){
                x = num % 2;
                //printf("x: %d\n",x);
               // printf("tmp: %d\n",tmp);
                //printf("(int)pow(10,i) * (x ^ tmp): %d\n",(int)pow(10.001,i) * (x ^ tmp));
                result += (int)pow(10.001,i) * (x ^ tmp);
               // printf("result : %d\n",result);
                tmp = x;
                i++;
                num = num >> 1;
            }
            result += (int)pow(10.001,i) * 1;
        }
        while((bits-i-1)>0){
            printf("0");
            i++;
        }
        printf("%d\n",result);
        scanf(" %d",&state);
    }



    return 0;
}
