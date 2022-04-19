#include <stdio.h>
typedef struct workingMachine_s{
    int totalTime;
}workingMachine;
typedef struct machine_s{
    int number;
    int processTime;
}machine_t;
typedef struct work_s{
    machine_t machines[100];
    int processAmount;
    int lastDoneTime;
    int processDone;
}work_t;
int isSameWork(work_t a,work_t b){
    if(a.processAmount==b.processAmount){
        if(a.processDone==b.processDone){
            for(int i=0;i<a.processAmount;i++){
                if(a.machines[i].number!=b.machines[i].number)
                    return 0;
                else if(a.machines[i].processTime != b.machines[i].processTime)
                    return 0;
            }
            return 1;
        }
    }
    return 0;
}
int max(int a,int b){
    if(a>b)
        return a;
    else if(b>a)
        return b;
    return a;
}
void findNextProcess(work_t work[],int workAmount,workingMachine wM[]){
    work_t nextProcess=work[0];
    nextProcess.machines[nextProcess.processDone].processTime=1000000;
    int nextProcessWorkNum=0;
    int tmpT=0,tmpNext;
    for(int wc=0;wc<workAmount;wc++){
        if(work[wc].processDone>=work[wc].processAmount){
            continue;
        }
        tmpT=0;
        tmpNext=0;
        if(nextProcess.processDone-1>=0){
            tmpT+=nextProcess.lastDoneTime;
        }else{
            nextProcess.lastDoneTime=0;
        }
        tmpT=max(wM[nextProcess.machines[nextProcess.processDone].number].totalTime,tmpT);
        tmpT+=nextProcess.machines[nextProcess.processDone].processTime;
        if(work[wc].processDone-1>=0){
            tmpNext+=work[wc].lastDoneTime;
        }else{
            work[wc].lastDoneTime=0;
        }
        tmpNext=max(wM[work[wc].machines[work[wc].processDone].number].totalTime,tmpNext);
        tmpNext+=work[wc].machines[work[wc].processDone].processTime;
        if((tmpNext)<(tmpT)){
            nextProcess=work[wc];
            nextProcessWorkNum=wc;
        }
    }
    tmpT=0;
        if(nextProcess.processDone-1>=0){
            tmpT+=nextProcess.lastDoneTime;
        }else{
            nextProcess.lastDoneTime=0;
        }
    tmpT=max(wM[nextProcess.machines[nextProcess.processDone].number].totalTime,tmpT);
    tmpT+=nextProcess.machines[nextProcess.processDone].processTime;
    //printf("Work : %d Machine Num : %d processTime: %d\n",nextProcessWorkNum,nextProcess.machines[nextProcess.processDone].number,nextProcess.machines[nextProcess.processDone].processTime);
    wM[nextProcess.machines[nextProcess.processDone].number].totalTime=tmpT;
    work[nextProcessWorkNum].processDone++;
    work[nextProcessWorkNum].lastDoneTime=tmpT;
}
int allDone(work_t work[],int workAmount){
    for(int i=0;i<workAmount;i++){
        if(work[i].processAmount>work[i].processDone){
            return 0;
        }
    }
    return 1;
}
int main(){
    int machineAmount,workAmount;
    work_t work[100];
    workingMachine wM[100];
    scanf(" %d %d",&machineAmount,&workAmount);
    for(int mc=0;mc<machineAmount;mc++)
        wM[mc].totalTime=0;
    for(int wc=0;wc<workAmount;wc++){
        work[wc].processDone=0;
        scanf(" %d",&work[wc].processAmount);
        for(int pc=0;pc<work[wc].processAmount;pc++){
            scanf(" %d",&work[wc].machines[pc].number);
            scanf(" %d",&work[wc].machines[pc].processTime);
        }
    }
    /*for(int wc=0;wc<workAmount;wc++){
        printf("Work %d\n    ",wc);
        for(int pc=0;pc<work[wc].processAmount;pc++){
            printf("(m%d : t%d)",work[wc].machines[pc].number,work[wc].machines[pc].processTime);
            printf("->");
        }
        printf("\n");
    }*/
    int optime=0;
    while(!allDone(work,workAmount)){
        findNextProcess(work,workAmount,wM);
        /*for(int i=0;i<machineAmount;i++){
            printf("WorkingMachine : %d , TotalTime: %d\n",i,wM[i].totalTime);
        }
        printf("--------------------------------------\n");*/
        for(int i=0;i<workAmount;i++){
            if(work[i].processDone==work[i].processAmount){
                optime+=wM[work[i].machines[work[i].processDone-1].number].totalTime;
                work[i].processDone++;
            }
        }

    }
    printf("%d",optime);

}
