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
        result+=((int)pow(2.00000000000001,i))*tmp;
        i++;
        bits/=10;
    }
    return result;
}
long long int d2b(int bits){
    int i=0,tmp=0;
    long long int result=0;
    if(bits==0)
        return 0;
    while(bits>0){
        tmp=bits%2;
        result+=((long long int)pow(10.000000000001,i))*tmp;
    //    printf("%lld ",result);
        i++;
        bits=bits>>1;
    }
    //printf("\n");
    return result;
}
int Cfunction(int input){
    if(input==0)
        return 0;
    int next;
    int count=0;
    next=input-1;
    int tmp=input;
    while(tmp>1){
        if(tmp%2==0)
            tmp/=2;
        else
            tmp=(tmp+1)/2;
        count++;
    }
   // printf("count: %d\n",count);
    return (count + Cfunction(next));
}
int Nbits(long long int bits){
    int i=0;
    if(bits==0)
        return 1;
    while(bits>0){
        i++;
        bits/=10;
    }
    return i;
}
void putZero(int n,long long int input){
    int N = Nbits(input);
   // printf("N: %d\n",N);

    while(n-N>0){
        printf("0");
        N++;
    }
}

int main(){
    int state=0;
    int input;
    int result;
    long long int end;
    int dec=0;
    while(state==0){
        scanf(" %d",&input);
        dec = b2d(input);
        result = Cfunction(dec);
       // printf("result: %d\n",result);
        end = d2b(result);
        putZero(11,end);
        printf("%lld\n",end);
        scanf(" %d",&state);
    }
    return 0;
}
