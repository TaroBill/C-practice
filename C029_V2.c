#include <stdio.h>
#include <string.h>
typedef struct llDouble_s{
    int integerPart[100];
    int integerPartLength;
    int floatPart[100];
    int floatPartLength;
    int signal;
}llDouble_t;
int add(int a[],int b[],int out[],int la,int lb){
    int carry=0,lo=0;
    int tmpO[300];
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
int floatAdd(int a[],int b[],int out[],int la,int lb){
    int carry=0,lo=0;
    int tmpO[300];
    if(la>lb){
        for(int i=lb;i<la;i++){
            b[i]=0;
        }
        lb=la;
    }else if(lb>la){
        for(int i=la;i<lb;i++){
            a[i]=0;
        }
        la=lb;
    }
    la--;
    while(la>=0){
        int numA;
        int numB;
        numA=a[la];
        numB=b[la];
        int sum=numA+numB+carry;
       // printf("a: %d b: %d sum: %d ",numA,numB,sum);
        tmpO[lo]=sum%10;
        carry = sum/10;
        lo++;
        la--;
    }
    tmpO[lo]=carry;
    lo++;
    for(int index=0;index<lo;index++)
        out[index]=tmpO[index];
    //printf("\n");
    upsidedown(out,lo);
    return lo;
}
int sub(int a[],int b[],int out[],int la,int lb){
    int borrow=0,lo=0,pb=0;
    int tmpO[200];
    la--;
    lb--;
    while(la>=0 || lb>=0){
        pb=borrow;
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
      //  printf("sum: %d ",sum);
        tmpO[lo]=sum%10;
        lo++;
        la--;
        lb--;
    }
    //printf("\n");
    for(int index=0;index<lo;index++)
        out[index]=tmpO[index];
    upsidedown(out,lo);
    return lo;
}
int floatSub(int a[],int b[],int out[],int la,int lb){
    int borrow=0,lo=0,pb=0;
    int tmpO[200];
    if(la>lb){
        for(int i=lb;i<la;i++){
            b[i]=0;
        }
        lb=la;
    }else if(lb>la){
        for(int i=la;i<lb;i++){
            a[i]=0;
        }
        la=lb;
    }
    la--;
    while(la>=0){
        pb=borrow;
        int numA;
        int numB;
        numA=a[la];
        numB=b[la];
        if(numA-pb<numB){
            borrow=1;
            numA+=10;
        }else{
            borrow=0;
        }
        int sum=numA-numB-pb;
       // printf("sum: %d ",sum);
        tmpO[lo]=sum%10;
        lo++;
        la--;
    }
   // printf("\n");
    for(int index=0;index<lo;index++)
        out[index]=tmpO[index];
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
    int total[500]={0};
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
    int tmp[500];
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
        return -1;
    else{
        for(int i=0;i<la;i++){
            if(a[i]>b[i])
                return 1;
            else if(a[i]<b[i])
                return -1;
        }
        return 0;
    }
}
int isFloatBigger(int a[],int b[],int la,int lb){
    int l;
    if(la>lb)
        l=lb;
    else
        l=la;
    for(int i=0;i<l;i++){
        if(a[i]>b[i])
            return 1;
        else if(a[i]<b[i])
            return -1;
    }
    if(la>lb)
        return 1;
    else if(la<lb)
        return -1;
    return 0;

}
void print(int o[],int length,int haveMinus,int maxPrintLength,int isFloat){
    int zero=1;
    int i;
    int plength;
    if(length>maxPrintLength)
        plength=maxPrintLength;
    else
        plength=length;
    if(haveMinus)
        printf("-");
    if(!isFloat){
        for(i=0;i<plength;i++){
            if(o[i]==0 && zero)
                continue;
            else
                zero=0;
            printf("%d",o[i]);
        }
        if(zero)
            printf("0");
    }else{
        int zerotest=1;
        for(int j=0;j<plength;j++){
            if(o[j]!=0){
                zerotest=0;
                break;
            }
        }
        if(zerotest)
            return;
        printf(".");
        for(i=0;i<plength;i++){
            zerotest=1;
            for(int j=i;j<plength;j++){
                if(o[j]!=0){
                    zerotest=0;
                    break;
                }
            }
            if(zerotest){
                break;
            }
            printf("%d",o[i]);
        }
        if(i<maxPrintLength){
            for(int www=0;www<maxPrintLength-i;www++)
                printf("0");
        }
    }
}
void addDone(llDouble_t out,llDouble_t a,llDouble_t b,int printFloatLength){
//開始加法
    out.integerPartLength=add(a.integerPart,b.integerPart,out.integerPart,a.integerPartLength,b.integerPartLength);
    out.floatPartLength=floatAdd(a.floatPart,b.floatPart,out.floatPart,a.floatPartLength,b.floatPartLength);
    int *pint=out.floatPart;
    int compareL;
    if(a.floatPartLength>b.floatPartLength)
        compareL=a.floatPartLength;
    else
        compareL=b.floatPartLength;
    if(out.floatPartLength>compareL){
        int temp[10];
        int tempL=out.floatPartLength-compareL;
        for(int i=0;i<tempL;i++){
            temp[i]=out.floatPart[i];
        }
        pint+=tempL;
        out.integerPartLength=add(out.integerPart,temp,out.integerPart,out.integerPartLength,tempL);
    }
    print(out.integerPart,out.integerPartLength,0,120,0);
    print(pint,compareL,0,printFloatLength,1);
    printf("\n");
}
void subDone(llDouble_t out,llDouble_t a,llDouble_t b,int printFloatLength){
    //開始減法
    int temp[1]={1};
    if(isBigger(a.integerPart,b.integerPart,a.integerPartLength,b.integerPartLength)>0){
        out.integerPartLength=sub(a.integerPart,b.integerPart,out.integerPart,a.integerPartLength,b.integerPartLength);
        if(isFloatBigger(a.floatPart,b.floatPart,a.floatPartLength,b.floatPartLength)>0){
            out.floatPartLength=floatSub(a.floatPart,b.floatPart,out.floatPart,a.floatPartLength,b.floatPartLength);
            print(out.integerPart,out.integerPartLength,0,120,0);
            print(out.floatPart,out.floatPartLength,0,printFloatLength,1);
            printf("\n");
        }else if(isFloatBigger(a.floatPart,b.floatPart,a.floatPartLength,b.floatPartLength)<0){
            out.floatPartLength=floatSub(a.floatPart,b.floatPart,out.floatPart,a.floatPartLength,b.floatPartLength);
            out.integerPartLength=sub(out.integerPart,temp,out.integerPart,out.integerPartLength,1);
            print(out.integerPart,out.integerPartLength,0,120,0);
            print(out.floatPart,out.floatPartLength,0,printFloatLength,1);
            printf("\n");
        }else{
            print(out.integerPart,out.integerPartLength,0,120,0);
            printf("\n");
        }
    }else if(isBigger(a.integerPart,b.integerPart,a.integerPartLength,b.integerPartLength)<0){
        out.integerPartLength=sub(b.integerPart,a.integerPart,out.integerPart,b.integerPartLength,a.integerPartLength);
        if(isFloatBigger(a.floatPart,b.floatPart,a.floatPartLength,b.floatPartLength)>0){
            out.floatPartLength=floatSub(b.floatPart,a.floatPart,out.floatPart,b.floatPartLength,a.floatPartLength);
            out.integerPartLength=sub(out.integerPart,temp,out.integerPart,out.integerPartLength,1);
            print(out.integerPart,out.integerPartLength,1,120,0);
            print(out.floatPart,out.floatPartLength,0,printFloatLength,1);
            printf("\n");
        }else if(isFloatBigger(a.floatPart,b.floatPart,a.floatPartLength,b.floatPartLength)<0){
            out.floatPartLength=floatSub(b.floatPart,a.floatPart,out.floatPart,b.floatPartLength,a.floatPartLength);
            print(out.integerPart,out.integerPartLength,1,120,0);
            print(out.floatPart,out.floatPartLength,0,printFloatLength,1);
            printf("\n");
        }else{
            print(out.integerPart,out.integerPartLength,0,120,0);
            printf("\n");
        }
    }else{
        if(isFloatBigger(a.floatPart,b.floatPart,a.floatPartLength,b.floatPartLength)>0){
            out.floatPartLength=floatSub(a.floatPart,b.floatPart,out.floatPart,a.floatPartLength,b.floatPartLength);
            printf("0");
            print(out.floatPart,out.floatPartLength,0,printFloatLength,1);
            printf("\n");
        }else if(isFloatBigger(a.floatPart,b.floatPart,a.floatPartLength,b.floatPartLength)<0){
            out.floatPartLength=floatSub(b.floatPart,a.floatPart,out.floatPart,b.floatPartLength,a.floatPartLength);
            printf("-0");
            print(out.floatPart,out.floatPartLength,0,printFloatLength,1);
            printf("\n");
        }
    }
}
void multiDone(llDouble_t out,llDouble_t a,llDouble_t b,int printFloatLength,int combineA[],int combineB[],int combineALength,int combineBLength){
 //開始乘法
    int multiOutput[500];
    int multiOutputL;
    multiOutputL= multi(combineA,combineB,multiOutput,combineALength,combineBLength);
    int zero=1,count=0,floatLength=0;
    int isFloat=0;
    int floatAmount=b.floatPartLength+a.floatPartLength;
    upsidedown(combineB,combineBLength);
    int zerotest=1;
    for(int j=0;j<multiOutputL;j++){
        if(multiOutput[j]!=0){
            zerotest=0;
            break;
        }
    }
    if(zerotest)
        printf("0\n");
    for(int i=0;i<multiOutputL;i++){
        if(multiOutput[i]==0&&zero)
            continue;
        zero=0;
       // printf("(integerAmountOffSet) %d Count: %d\n",integerAmountOffSet,count);
        zerotest=1;
        for(int j=i;j<multiOutputL;j++){
            if(multiOutput[j]!=0){
                zerotest=0;
                break;
            }
        }
        if((multiOutputL-i)==floatAmount){
            if(zerotest)
                break;
            printf(".");
            isFloat=1;
        }
        if(zerotest&&isFloat){
            break;
        }
        printf("%d",multiOutput[i]);
        if(isFloat)
            floatLength++;
        count++;
        if(count==120||(floatLength==printFloatLength &&printFloatLength!=0)){
            break;
        }
    }
    if(floatLength<printFloatLength){
        for(int www=0;www<printFloatLength-floatLength;www++)
            printf("0");
    }
}
int main(){
    char fir[150];
    char sec[150];
    int printFloatLength;
    scanf(" %s",fir);
    scanf(" %s",sec);
    scanf(" %d",&printFloatLength);
    int la = strlen(fir);
    int lb = strlen(sec);
    llDouble_t a;a.floatPart[0]=0;a.floatPartLength=1;
    llDouble_t b;b.floatPart[0]=0;b.floatPartLength=1;
    llDouble_t out;
    int isFloatPart=0;
    char *p=fir;
    if(fir[0]=='-'){
        a.signal=1;
        p++;
    }else
        a.signal=0;
    int index=0,findex=0;
    int combineA[200];
    int combineALength=0;
    int combineB[200];
    int combineBLength=0;
    for(index=0,findex=0;index<la-a.signal;index++){
        if(p[index]=='.'){
            isFloatPart=1;
            continue;
        }
        combineA[combineALength]=(p[index]-48);
        combineALength++;
        if(!isFloatPart)
            a.integerPart[index]=(p[index]-48);
        else{
            a.floatPart[findex]=(p[index]-48);
            findex++;
        }
    }
    a.floatPartLength=findex;
    a.integerPartLength=la-a.signal-findex-isFloatPart;
    p=sec;
    isFloatPart=0;
    if(sec[0]=='-'){
        b.signal=1;
        p++;
    }else
        b.signal=0;
    for(index=0,findex=0;index<lb-b.signal;index++){
        if(p[index]=='.'){
            isFloatPart=1;
            continue;
        }
        combineB[combineBLength]=(p[index]-48);
        combineBLength++;
        if(!isFloatPart)
            b.integerPart[index]=(p[index]-48);
        else{
            b.floatPart[findex]=(p[index]-48);
            findex++;
        }
    }
    b.floatPartLength=findex;
    b.integerPartLength=lb-b.signal-findex-isFloatPart;

    /*printf("combineA: ");
    for(int i=0;i<combineALength;i++)
        printf("%d",combineA[i]);
    printf("\n");
    printf("combineB: ");
    for(int i=0;i<combineBLength;i++)
        printf("%d",combineB[i]);
    printf("\n");
    printf("a.integerPart: ");
    for(int i=0;i<a.integerPartLength;i++)
        printf("%d",a.integerPart[i]);
    printf("\n");
    printf("a.floatPart: ");
    for(int i=0;i<a.floatPartLength;i++)
        printf("%d",a.floatPart[i]);
    printf("\n");
    printf("a.signal: %d\n",a.signal);

    printf("b.integerPart: ");
    for(int i=0;i<b.integerPartLength;i++)
        printf("%d",b.integerPart[i]);
    printf("\n");
    printf("b.floatPart: ");
    for(int i=0;i<b.floatPartLength;i++)
        printf("%d",b.floatPart[i]);
    printf("\n");
    printf("b.signal: %d\n",b.signal);*/



    if(a.signal==0&&b.signal==0){
        addDone(out,a,b,printFloatLength);
        if(strcmp(fir,sec)==0)
            printf("0\n");
        else
            subDone(out,a,b,printFloatLength);
        multiDone(out,a,b,printFloatLength,combineA,combineB,combineALength,combineBLength);
    }else if(a.signal==0&&b.signal==1){
        if(strcmp(fir,sec)==0)
            printf("0\n");
        else
            subDone(out,a,b,printFloatLength);
        addDone(out,a,b,printFloatLength);
        printf("-");
        multiDone(out,a,b,printFloatLength,combineA,combineB,combineALength,combineBLength);
    }else if(a.signal==1&&b.signal==0){
        if(strcmp(fir,sec)==0)
            printf("0\n");
        else
            subDone(out,b,a,printFloatLength);
        printf("-");
        addDone(out,a,b,printFloatLength);
        printf("-");
        multiDone(out,a,b,printFloatLength,combineA,combineB,combineALength,combineBLength);
    }else if(a.signal==1&&b.signal==1){
        printf("-");
        addDone(out,a,b,printFloatLength);
        if(strcmp(fir,sec)==0)
            printf("0\n");
        else
            subDone(out,b,a,printFloatLength);
        multiDone(out,a,b,printFloatLength,combineA,combineB,combineALength,combineBLength);
    }
    return 0;
}
