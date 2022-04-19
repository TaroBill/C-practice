#include <stdio.h>

int isPrime(int n){
    if(n==1)
        return 0;
    else if(n==2)
        return 1;
    for(int i=2;i<n;i++){
        if(n%i==0)
            return 0;
    }
    return 1;
}

int main(){
    int input;
    scanf(" %d",&input);
    int count=0;
    for(int i=2;i<=input;i++){
        if(isPrime(i)){
            count++;
            if(count%3==0){
                printf("%d\n",i);
            }
        }
    }
    if(count<3){
        printf("含括的質數未達三個\n");
    }
    return 0;
}
