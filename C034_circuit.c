#include <stdio.h>
#include <string.h>
//#define DEBUG
#define GATEVALUE(TYPE)\
 int(*GateValue)(TYPE)
typedef struct _Gate{
    GATEVALUE(Gate);
    unsigned short I1:1;
}Gate;
int GateGetValue(){return 0;}
typedef struct _twoGate{
    GATEVALUE(twoGate);
    unsigned short I1:1;
    unsigned short I2:1;
}twoGate;
typedef struct _GateEmpty{
    GATEVALUE(GateEmpty);
    unsigned short I1:1;
}GateEmpty;
typedef struct _GateAnd{
    GATEVALUE(GateAnd);
    unsigned short I1:1;
    unsigned short I2:1;
}GateAnd;
typedef struct _GateOr{
    GATEVALUE(GateOr);
    unsigned short I1:1;
    unsigned short I2:1;
}GateOr;
typedef struct _GateXor{
    GATEVALUE(GateXor);
    unsigned short I1:1;
    unsigned short I2:1;
}GateXor;
typedef struct _GateNot{
    GATEVALUE(GateNot);
    unsigned short I1:1;
}GateNot;
int GateAndValue(GateAnd *G){return (G->I1 & G->I2); }
int GateOrValue(GateOr *G){return (G->I1 | G->I2); }
int GateXorValue(GateXor *G){return (G->I1 ^ G->I2); }
int GateNotValue(GateNot *G){return 1^(G->I1);}
int GateEmptyValue(GateEmpty *G){return (G->I1); }
void CreateGate(Gate *obj){
    obj->GateValue = GateGetValue;
}
void CreateGateAND(GateAnd *obj){
    obj->GateValue = GateAndValue;
}
void CreateGateOR(GateOr *obj){
    obj->GateValue = GateOrValue;
}
void CreateGateXor(GateXor *obj){
    obj->GateValue = GateXorValue;
}
void CreateGateNot(GateNot *obj){
    obj->GateValue = GateNotValue;
}
void CreateGateEmpty(GateEmpty *obj){
    obj->GateValue = GateEmptyValue;
}
int main(){
    Gate g[2];
    twoGate twoG[4];
    int out[3];
    char inputData[100];
    char inputGate[100];
    gets(inputData);
    gets(inputGate);
    #ifdef DEBUG
    for(int i=0;i<7;i++){
        printf("%c",inputData[i]);
    }
    printf("\n");
    #endif // DEBUG
    for(int i=0;i<11;i+=2){
        if(i%8==0){
            #ifdef DEBUG
            printf("g[%d]: %c\n",i/8,inputGate[i]);
            #endif // DEBUG
            switch(inputGate[i]){
                case 'E':
                    CreateGateEmpty(&g[i/8]);
                    break;
                case 'N':
                    CreateGateNot(&g[i/8]);
                    break;
            }
        }else{
            #ifdef DEBUG
            if(i<8)
                printf("twoG[%d]: %c\n",i/2-1,inputGate[i]);
            else
                printf("twoG[%d]: %c\n",3,inputGate[i]);
            #endif // DEBUG
            switch(inputGate[i]){
                case 'A':
                    if(i<8)
                        CreateGateAND(&twoG[i/2-1]);
                    else
                        CreateGateAND(&twoG[3]);
                    break;
                case 'O':
                    if(i<8)
                        CreateGateOR(&twoG[i/2-1]);
                    else
                        CreateGateOR(&twoG[3]);
                    break;
                case 'X':
                    if(i<8)
                        CreateGateXor(&twoG[i/2-1]);
                    else
                        CreateGateXor(&twoG[3]);
                    break;
            }
        }
    }
    g[0].I1=inputData[0]-48;
    g[1].I1=inputData[6]-48;
    twoG[0].I1=g[0].GateValue(&g[0]);
    twoG[0].I2=inputData[2]-48;
    out[0]=twoG[0].GateValue(&twoG[0]);
    twoG[1].I1=out[0];
    twoG[1].I2=inputData[4]-48;
    twoG[2].I1=out[0];
    twoG[2].I2=twoG[1].GateValue(&twoG[1]);
    out[1]=twoG[2].GateValue(&twoG[2]);
    twoG[3].I1=out[1];
    twoG[3].I2=g[1].GateValue(&g[1]);
    out[2]=twoG[3].GateValue(&twoG[3]);
    #ifdef DEBUG
    printf("I1: %d I2: %d I3: %d I4: %d\n",inputData[0]-48,inputData[2]-48,inputData[4]-48,inputData[6]-48);
    printf("Result A: %d\n",g[0].GateValue(&g[0]));
    printf("Result B: %d\n",twoG[0].GateValue(&twoG[0]));
    printf("Result C: %d\n",twoG[1].GateValue(&twoG[1]));
    printf("Result D: %d\n",twoG[2].GateValue(&twoG[2]));
    printf("Result E: %d\n",g[1].GateValue(&g[1]));
    printf("Result F: %d\n",twoG[3].GateValue(&twoG[3]));
    #endif // DEBUG
    printf("%d,%d,%d",out[0],out[1],out[2]);
    return 0;
}
