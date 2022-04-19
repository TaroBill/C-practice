#include <stdio.h>
#include <string.h>
typedef enum scoreType_s {G,GPA,S} scoreType_t;
typedef struct studentsInfo_s{
    int studentsScore[20];
    char studentID[20];
    float studentsAverage;
} studentsInfo_t;

int getGrade(scoreType_t st){
    if(st==G){
        char score[5];
        gets(score);
        if(strcmp(score,"A+")==0)
            return 95;
        else if(strcmp(score,"A")==0)
            return 87;
        else if(strcmp(score,"A-")==0)
            return 82;
        else if(strcmp(score,"B+")==0)
            return 78;
        else if(strcmp(score,"B")==0)
            return 75;
        else if(strcmp(score,"B-")==0)
            return 70;
        else if(strcmp(score,"C+")==0)
            return 68;
        else if(strcmp(score,"C")==0)
            return 65;
        else if(strcmp(score,"C-")==0)
            return 60;
        else if(strcmp(score,"F")==0)
            return 50;
    }else if(st==GPA){
        float sc;
        scanf("%f",&sc);
        getchar();
        if(sc>4.2)
            return 95;
        else if(sc>3.9)
            return 87;
        else if(sc>3.6)
            return 82;
        else if(sc>3.2)
            return 78;
        else if(sc>2.9)
            return 75;
        else if(sc>2.6)
            return 70;
        else if(sc>2.2)
            return 68;
        else if(sc>1.9)
            return 65;
        else if(sc>1.6)
            return 60;
        else
            return 50;
    }else if(st==S){
        char score[10];
        gets(score);
        if(strcmp(score,"90-100")==0)
            return 95;
        else if(strcmp(score,"85-89")==0)
            return 87;
        else if(strcmp(score,"80-84")==0)
            return 82;
        else if(strcmp(score,"77-79")==0)
            return 78;
        else if(strcmp(score,"73-76")==0)
            return 75;
        else if(strcmp(score,"70-72")==0)
            return 70;
        else if(strcmp(score,"67-69")==0)
            return 68;
        else if(strcmp(score,"63-66")==0)
            return 65;
        else if(strcmp(score,"60-62")==0)
            return 60;
        else if(strcmp(score,"59以下")==0)
            return 50;
    }
    return -1;
}

int main(){
    int classAmount;
    scoreType_t classType[20];
    int studentsAmount;
    studentsInfo_t studentsInfo[100];
    scanf(" %d",&classAmount);
    getchar();
    char type[30];
    for(int i=0;i<classAmount;i++){
        gets(type);
        if(strcmp(type,"G")==0){
            classType[i]=G;
        }else if(strcmp(type,"GPA")==0){
            classType[i]=GPA;
        }else if(strcmp(type,"S")==0){
            classType[i]=S;
        }
    }
    scanf("%d",&studentsAmount);
    getchar();
    for(int i=0;i<studentsAmount;i++){
       gets(studentsInfo[i].studentID);
        float total=0;
        for(int j=0;j<classAmount;j++){
            int score=getGrade(classType[j]);
            studentsInfo[i].studentsScore[j]=score;
            total+=score;
        }
        studentsInfo[i].studentsAverage=total/classAmount;
    }
    for(int i=0;i<studentsAmount;i++){
        for(int j=i;j<studentsAmount;j++){
            studentsInfo_t temp;
            if(studentsInfo[i].studentsAverage<studentsInfo[j].studentsAverage){
                temp = studentsInfo[i];
                studentsInfo[i]=studentsInfo[j];
                studentsInfo[j]=temp;
            }
        }
    }
    for(int i=0;i<3;i++){
        printf("%s\n",studentsInfo[i].studentID);
        int integerScore =studentsInfo[i].studentsAverage;
        if(studentsInfo[i].studentsAverage-integerScore>0.49)
            printf("%d\n",integerScore+1);
        else
            printf("%d\n",integerScore);
    }
    return 0;
}
