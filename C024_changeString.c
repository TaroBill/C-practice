#include <stdio.h>
#include <string.h>
void swap(char Origin[],char P[],char Q[]){
    int lP=strlen(P);
   // printf("%d\n",lP);
    int lQ=strlen(Q);
    int lOrigin=strlen(Origin);
    char *index=strstr(Origin,P);
    if(index!=NULL){
        while(*(index+lP)!=' ' && index!=NULL && *(index+lP)!='\0' || (*(index-1)!=' '&& index!=Origin)){
            index+=lP;
            index=strstr(index,P);
            if(index==NULL)
                break;
        }
    }
    int pointer=0;
    while(pointer < lOrigin){
        //printf("%d",pointer);
        if((Origin+pointer)==index){
            printf("%s",Q);
            index+=lP;
            pointer+=lP;
            index=strstr(index,P);
            if(index!=NULL){
                while(*(index+lP)!=' ' && index!=NULL && *(index+lP)!='\0'|| (*(index-1)!=' '&& index!=Origin)){
                    //printf("\"%s\"\n",index);
                    index+=lP;
                    index=strstr(index,P);
                    if(index==NULL)
                        break;
                }
            }
        }
        if(pointer<lOrigin){
            printf("%c",*(Origin+pointer));
            pointer++;
        }
    }
    printf("\n");
}
void addPrevious(char Origin[],char P[],char Q[]){
    int lP=strlen(P);
   // printf("%d\n",lP);
    int lQ=strlen(Q);
    int lOrigin=strlen(Origin);
    char *index=strstr(Origin,P);
    if(index!=NULL){
        while(*(index+lP)!=' ' && index!=NULL && *(index+lP)!='\0'|| (*(index-1)!=' '&& index!=Origin)){
            index+=lP;
            index=strstr(index,P);
            if(index==NULL)
                break;
        }
    }
    int pointer=0;
    while(pointer < lOrigin){
        //printf("%d",pointer);
        if((Origin+pointer)==index){
            printf("%s ",Q);
            index+=lP;
            index=strstr(index,P);
            if(index!=NULL){
                while(*(index+lP)!=' ' && index!=NULL && *(index+lP)!='\0'|| (*(index-1)!=' '&& index!=Origin)){
                    index+=lP;
                    index=strstr(index,P);
                    if(index==NULL)
                        break;
                }
            }
        }
        if(pointer<lOrigin){
            printf("%c",*(Origin+pointer));
            pointer++;
        }
    }
    printf("\n");
}
void removes(char Origin[],char P[],char Q[]){
    int lP=strlen(P);
   // printf("%d\n",lP);
    int lQ=strlen(Q);
    int lOrigin=strlen(Origin);
    char *index=strstr(Origin,P);
    if(index!=NULL){
        while(*(index+lP)!=' ' && index!=NULL && *(index+lP)!='\0'|| (*(index-1)!=' '&& index!=Origin)){
            index+=lP;
            index=strstr(index,P);
            if(index==NULL)
                break;
        }
    }
    int pointer=0;
    while(pointer < lOrigin){
        //printf("%d",pointer);
        if((Origin+pointer)==index){
            index+=lP;
            pointer+=lP+1;
            index=strstr(index,P);
            if(index!=NULL){
                while(*(index+lP)!=' ' && index!=NULL && *(index+lP)!='\0'|| (*(index-1)!=' '&& index!=Origin)){
                    index+=lP;
                    index=strstr(index,P);
                    if(index==NULL)
                        break;
                }
            }
            continue;
        }
        if(pointer<lOrigin){
            printf("%c",*(Origin+pointer));
            pointer++;
        }
    }
    printf("\n");
}
void size(char str[]){
    int LS=0;
    char *s[500];
    int CountS[500];
    char *delim= " ";
    char *pch;
    pch= strtok(str,delim);
   /* s[LS]=pch;
    CountS[LS]=1;
    LS++;*/
    while (pch!= NULL)  {
        int result,i;
        for(i=0;i<LS;i++){
            result = strcmp(s[i],pch);
            if(result==0){
                CountS[i]++;
                break;
            }
        }
        if(i==LS){
            s[LS]=pch;
            CountS[LS]=1;
            LS++;
        }
        pch= strtok(NULL, delim);
    }
    int i=0,j=0;
    int temp=0;
    char *tempc;
    for(i=0;i<LS;i++) {
        for(j=i;j<LS;j++) {
            if( CountS[j] > CountS[i]) {
                temp = CountS[j];
                tempc = s[j];
                CountS[j] = CountS[i];
                CountS[i] = temp;
                s[j] = s[i];
                s[i] = tempc;
            }else if((strcmp(s[j],s[i])<0)&&(CountS[j] == CountS[i])){
                temp = CountS[j];
                tempc = s[j];
                CountS[j] = CountS[i];
                CountS[i] = temp;
                s[j] = s[i];
                s[i] = tempc;
            }
        }
    }
    for(int i=0;i<LS;i++){
        printf("%s : %d\n",s[i],CountS[i]);
    }
}
int main(){
    char str[1000];
    char strP[500];
    char strQ[500];
    gets(str);
    gets(strP);
    gets(strQ);
    swap(str,strP,strQ);
    addPrevious(str,strP,strQ);
    removes(str,strP,strQ);
    size(str);
    return 0;
}
