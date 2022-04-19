#include <stdio.h>
#include <stdlib.h>
int haveSame(int *list,int length){
    int *SameArray = (int*)malloc(sizeof(int)*length);
    for(int i=0;i<length;i++){
        for(int j=0;j<i;j++){
           // printf("list :%d Same : %d\n",*(list+i),*(SameArray+j));
            if(*(list+i)==*(SameArray+j)){
                free(SameArray);
                return 0;
            }
        }
        *(SameArray+i)=*(list+i);
    }
    free(SameArray);
    return 1;
}
int getLength(int input){
    //printf("inputGetLength : %d\n",input);
    int i=0;
    if(input==0)
        return 1;
    while(input != 0){
        input/=10;
        i++;
    }
    //printf("getL : %d\n",i);
    return i;
}
int seperateN(int x,int len){
    int sp=1;
    int Count=0;
    for(int i=0;i<len;i++)
        sp*=10;
    //printf("SP : %d\n",sp);
    int numL=getLength(x);
    if(numL<len)
        return 0;
    while(numL>=len){
        int *list = (int*)malloc(sizeof(int) * len);
        int c = x%sp;
      //  printf("%d\n",c);
        for(int co=0;co<len;co++){
            if(c==0)
                *list=0;
            else
                *list=c%10;
            c/=10;
            list++;
        }
        x/=10;
        numL=getLength(x);
       // printf("HaveSame : %d\n",haveSame(list-len,len));
        Count+=haveSame(list-len,len);
        //printf("Count : %d\n",Count);
        free(list);
    }
    return Count;
}


int main(){
    int iNums;
    int length;
    scanf(" %d",&iNums);
    scanf(" %d",&length);
    int n = seperateN(iNums,length);
    printf("%d\n",n);
    return 0;
}
