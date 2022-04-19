#include <stdio.h>
#include <string.h>
int same(char *set1[],int set1L,char *set2[],int set2L){
   int i,j,result;
    for(j=0;j<set2L;j++){
        for(i=0;i<set1L;i++){
            result = strcmp(set2[j],set1[i]);
            if(result==0){
                break;
            }
        }
        if(i==set1L){
            return 0;
        }
    }
    for(j=0;j<set1L;j++){
        for(i=j+1;i<set1L;i++){
            result = strcmp(set1[j],set1[i]);
            if(result==0){
                return 0;
            }
        }
    }
    return 1;
}
int combine(char *set1[],int set1L,char *set2[],int set2L,char *temp[]){
    /*printf("set1L: %d,set2L: %d\n",set1L,set2L);
    for(int t=0;t<set1L;t++){
        printf("%s ",set1[t]);
    }printf("------\n");
    for(int t=0;t<set2L;t++){
        printf("%s ",set2[t]);
    }printf("-------\n");*/
    int tempL=set1L;
    for(int i=0;i<set1L;i++){
        temp[i] = set1[i];
    }
    int i,j,result;
    for(j=0;j<set2L;j++){
        temp[tempL]=set2[j];
        tempL++;
    }
    return tempL;
}
int stringSet(char str[],char *output[]){
    int LS=0;
    char *s[500];
    char *delim= " ";
    char *pch;
    pch= strtok(str,delim);
    while (pch!= NULL)  {
        int result,i;
        for(i=0;i<LS;i++){
            result = strcmp(s[i],pch);
            if(result==0)
                break;
        }
        if(i==LS){
            s[LS]=pch;
            LS++;
        }
        pch=strtok(NULL, delim);
    }
    int i=0,j=0;
    char *tempc;
    for(i=0;i<LS;i++) {
        for(j=i;j<LS;j++) {
            if((strcmp(s[j],s[i])<0)){
                tempc = s[j];
                s[j] =  s[i];
                s[i] = tempc;
            }
        }
    }
    for(int i=0;i<LS;i++){
        output[i] = s[i];
    }
    return LS;
}
int main(){
    char FullString[500];
    char *FSSet[500];
    char *TheOther[100][500];
    int LFS,NumbersOfStringInput;
    int LOS[100];
    gets(FullString);
    LFS = stringSet(FullString,FSSet);
    scanf(" %d",&NumbersOfStringInput);
    getchar();
    char inputString[500][500];
    for(int i=0;i<NumbersOfStringInput;i++){
        gets(inputString[i]);
        LOS[i]=stringSet(inputString[i],TheOther[i]);
    }
    int counts=0;
    for(int i=0;i<NumbersOfStringInput;i++){
        for(int j=i+1;j<NumbersOfStringInput;j++){
            int combineLength;
            char *combineSet[500];
            /*for(int j=0;j<LOS[0];j++){
                printf("%s\n",TheOther[0][j]);
            }*/
            combineLength=combine(TheOther[i],LOS[i],TheOther[j],LOS[j],combineSet);
            /*for(int k=0;k<combineLength;k++){
                printf("%s ",combineSet[k]);
            }printf("\n");*/
            if(same(combineSet,combineLength,FSSet,LFS)){
                counts++;
            }
        }
    }
    printf("%d",counts);
    return 0;
}
