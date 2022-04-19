#include <stdio.h>
#include <string.h>
int max(int arr[],int length){
    int largest=arr[0];
    for(int i=1;i<length;i++){
        if(arr[i]>largest)
            largest=arr[i];
    }
    return largest;
}
int findx(char string[],int stringLength,int L){
    int state=0,counts=0,stateCount=1;
   // printf("%s %d %d\n",string,stringLength,L);
    for(int i=0;i<stringLength;i++){
        if(i==0){
            if(string[i]>='a'&&string[i]<='z'){
                state=0;
            }else if(string[i]>='A'&&string[i]<='Z'){
                state=1;
            }
            counts++;
            continue;
        }
        if(stateCount>=L){
            if(state){
                state=0;
                stateCount=0;
            }else{
                state=1;
                stateCount=0;
            }
        }
        if(state){
            if(string[i]>='a'&&string[i]<='z'){
                counts-=stateCount;
                return counts;
            }else if(string[i]>='A'&&string[i]<='Z'){
                stateCount++;
                counts++;
            }
        }else{
            if(string[i]>='a'&&string[i]<='z'){
                stateCount++;
                counts++;
            }else if(string[i]>='A'&&string[i]<='Z'){
                counts-=stateCount;
                return counts;
            }
        }
        /*printf("%d",i);
        printf(" %c ",string[i]);
        printf(" %d ",stateCount);
        printf("\n");*/
    }
    counts-=stateCount;
    return counts;
}
int main(){
    int L;
    char string[1000];
    scanf(" %d",&L);
    scanf(" %s",&string);
    int stringLength;
    stringLength = strlen(string);
    /*for(int i=0;i<stringLength;i++)
        printf("%c",string[i]);
    printf("\n");*/
    int count[1000];
    for(int i=0;i<1000;i++)
        count[i]=0;
    int countArrayL=0;
    for(int i=0;i<stringLength;i++){
        count[countArrayL]=findx(string+i,stringLength-i,L);
        countArrayL++;
    }
    int x=max(count,countArrayL);
    if(x<L)
        x=0;
    printf("%d",x);
    return 0;
}
