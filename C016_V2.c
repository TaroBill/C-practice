#include <stdio.h>
#include <string.h>
int haveSame(char *list,int length){
    char *SameArray = (char*)malloc(sizeof(char)*length);
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
int main(){
    char array[50];
    int m,count=0;
    scanf(" %s",&array);
    scanf(" %d",&m);
    int length = strlen(array);
    /*for(int i=0;i<length;i++){
        printf("i: %c",array[i]);
    }
    printf("\n");*/
    for(int i=0;i<length-m+1;i++){
        char *list = (char*)malloc(sizeof(char) * m);
        for(int j=0;j<m;j++){
            *(list+j)=array[i+j];
        }
        count+=haveSame(list,m);
        free(list);
    }
    printf("%d\n",count);
    return 0;
}
