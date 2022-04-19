#include <stdio.h>
void printChar(int n,char c){
    for(int i=0;i<n;i++)
        printf("%c",c);
}
void printNum(int n,int forward){
    if(forward){
        for(int i=1;i<=n;i++)
            printf("%d",i);
    }else{
        for(int i=n;i>=1;i--)
            printf("%d",i);
    }
}
void printNumTwo(int n){
    for(int i=2;i<=1+n;i++)
        printf("%d",i);
}
void first(int n){
    for(int i=1;i<=n;i++){
        printNum(i,1);
        printf("\n");
    }
    for(int i=n;i>=1;i--){
        printNum(i,0);
        printf("\n");
    }
    for(int i=1;i<=n;i++){
        printChar(i,i+48);
        printf("\n");
    }
}
void sec(int n){
    for(int i=1;i<=n;i++){
        printNum(i,1);
        printNum(i-1,0);
        printf("\n");
    }
    for(int i=n-1;i>=1;i--){
        printChar(i-1,'_');
        printNum(n-i,0);
        printNumTwo(n-i-1);
        printChar(i-1,'_');
        printf("\n");
    }
    for(int i=1;i<=n-1;i++){
        printChar(i-1,'_');
        printNum(n-i,0);
        printNumTwo(n-i-1);
        printChar(i-1,'_');
        printf("\n");
    }

}
int main(){
    int sharp,inputN;
    scanf(" %d",&sharp);
    scanf(" %d",&inputN);
    if(sharp==1)
        first(inputN);
    else if(sharp==2)
        sec(inputN);
    return 0;
}
