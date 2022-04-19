#include <stdio.h>
#include <math.h>
int b2d(int bits){
    int i=0,tmp=0,result=0;
    if(bits==0)
        return 0;
    else if(bits==1)
        return 1;
    while(bits>0){
        tmp=bits%10;
        result+=(int)pow(2.001,i)*tmp;
        i++;
        bits/=10;
    }
    return result;
}
int d2b(int bits){
    int i=0,tmp=0,result=0;
    if(bits==0)
        return 0;
    else if(bits==1)
        return 1;
    while(bits>0){
        tmp=bits%2;
        result+=(int)pow(10.001,i)*tmp;
        i++;
        bits=bits>>1;
    }
    return result;
}

int main(){
    int state=0;
    int input;
    int count=0;
    while(state==0){
        scanf(" %d",&input);
        int dec = b2d(input);
        while(dec>1){
            if(dec%2==0)
                dec/=2;
            else
                dec=(dec+1)/2;
            count++;
        }
        int end=d2b(count);
        if(end>=100 && end <1000)
            printf("0");
        else if(end>=10 && end<100)
            printf("00");
        else if(end<10)
            printf("000");
        printf("%d\n",end);
        scanf(" %d",&state);
        count=0;
    }
    return 0;
}
