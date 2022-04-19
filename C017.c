#include <stdio.h>
#include <string.h>
int add(int a[],int b[],int out[],int la,int lb){
    int carry=0,lo=0;
    int tmpO[100];
    while(la>=0 || lb>=0){
        la--;
        lb--;
        int numA;
        int numB;
        if(la <0)
            numA=0;
        else
            numA=a[la];
        if(lb<0)
            numB=0;
        else
            numB=b[lb];
        int sum=numA+numB+carry;
       // printf("sum: %d ",sum);
        tmpO[lo]=sum%10;
        carry = sum/10;
        lo++;
    }
    for(int index=0;index<lo;index++)
        out[index]=tmpO[index];
    //printf("\n");
    upsidedown(out,lo);
    return lo;
}
int sub(int a[],int b[],int out[],int la,int lb){
    int borrow=0,lo=0,pb=0;
    while(la>=0 || lb>=0){
        pb=borrow;
        la--;
        lb--;
        int numA;
        int numB;
        if(la <0)
            numA=0;
        else
            numA=a[la];
        if(lb<0)
            numB=0;
        else
            numB=b[lb];
        if(numA-pb<numB){
            borrow=1;
            numA+=10;
        }else{
            borrow=0;
        }
        int sum=numA-numB-pb;
       // printf("sum: %d ",sum);
        out[lo]=sum%10;
        lo++;
    }
   // printf("\n");
    upsidedown(out,lo);
    return lo;
}
int multDigit(int a[],int b,int out[],int la,int offset){
    int carry=0,lo=0,off;
    while(la>=0){
        la--;
        int numA;
        if(la <0)
            numA=0;
        else
            numA=a[la];
        int sum=numA*b+carry;
       // printf("sum: %d ",sum);
        out[lo]=sum%10;
        carry = sum/10;
        lo++;
    }
    //printf("\n");
    upsidedown(out,lo);
    for(off=0;off<offset;off++){
        out[lo]=0;
        lo++;
    }
    return lo;
}
int multi(int a[],int b[],int out[],int la,int lb){
    int total[100]={0};
    int lo,lto=1;
    upsidedown(b,lb);
    for(int i=0;i<lb;i++){
        lo=multDigit(a,b[i],out,la,i);
        lto=add(total,out,total,lto,lo);
    }
    for(int index=0;index<lto;index++)
        out[index]=total[index];
    return lto;
}
void upsidedown(int inp[],int length){
    int tmp[100];
    int index;
    for(index=length-1;index>=0;index--){
        tmp[length-index-1]=inp[index];
    }
    for(index=0;index<length;index++){
        inp[index]=tmp[index];
    }
}
int isBigger(int a[],int b[],int la,int lb){
    if(la>lb)
        return 1;
    else if(la<lb)
        return 0;
    else{
        for(int i=0;i<la;i++){
            if(a[i]>b[i])
                return 1;
            else if(a[i]<b[i])
                return 0;
        }
        return 1;
    }

}
void print(int o[],int length,int haveMinus){
    int zero=1;
    if(haveMinus)
        printf("-");
    for(int i=0;i<length;i++){
        if(o[i]==0 && zero)
            continue;
        else
            zero=0;
        printf("%d",o[i]);
    }
    if(zero)
        printf("\r0\n");
}
int main(){
    int mode;
    char fir[50];
    char sec[50];
    int out[100];
    scanf(" %d",&mode);
    scanf(" %s",&fir);
    scanf(" %s",&sec);
    int la = strlen(fir);
    int lb = strlen(sec);
    int a[50];
    int b[50];
    for(int index=0;index<la;index++)
        a[index]=(fir[index]-48);
    for(int index=0;index<lb;index++)
        b[index]=(sec[index]-48);
    int lo;
    switch(mode){
        case 1:
            lo=add(a,b,out,la,lb);
            print(out,lo,0);
            break;
        case 2:
            if(isBigger(a,b,la,lb)){
                lo=sub(a,b,out,la,lb);
                print(out,lo,0);
            }else{
                lo=sub(b,a,out,lb,la);
                print(out,lo,1);
            }
            break;
        case 3:
            lo=multi(a,b,out,la,lb);
            print(out,lo,0);
            break;
    }
    return 0;
}
