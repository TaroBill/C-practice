#include <stdio.h>
#include <math.h>
#include <stdlib.h>
void carry(int a,int b,int input){
    char op[50];
    int i=0,s=0;
    if(a!=10){
        while(input>0){
            s+=(input%10)*pow(a,i);
            i++;
            input/=10;
        }
        input = s;
    }
    //printf("%d",input);
    if(b !=10){
        i=0;
        char buffer[50];
        while(input!=0){
            buffer[i]=(char)(input%b + 48);
            input/=b;
            i++;
        }
        for(int j=i-1;j>=0;j--){
            printf("%c",buffer[j]);
        }
        //printf("%s",buffer);
    }else{
        printf("%d",input);
    }
}
int main(){
    int mode,a,b,ip;
    scanf(" %d",&mode);
    switch(mode){
        case 1:
            scanf(" %d",&ip);
            carry(10,2,ip);
            break;
        case 2:
            scanf(" %d",&ip);
            carry(2,10,ip);
            break;
        case 3:
            scanf(" %d",&a);
            scanf(" %d",&b);
            scanf(" %d",&ip);
            carry(a,b,ip);
            break;
        case 4:
            scanf(" %d",&ip);
            printf("%c",ip);
            break;
    }

    return 0;
}
