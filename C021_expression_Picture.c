#include <stdio.h>
#include <string.h>
void toCoordinates(char ip[],int op[][500],int deep,int *InPointer,int OutPointerX,int OutPointerY,int side){
    int effect = side/deep;
    int Num=(ip[(*InPointer)]-48);
   // printf("opPointer[%d][%d]\n",OutPointerX,OutPointerY);
    (*InPointer)++;
    //printf("effect: %d\n",effect);
    //printf("Pointer: %d\n",*InPointer);
    if(Num==2){
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                toCoordinates(ip,op,deep*2,InPointer,OutPointerX,OutPointerY,side);
                OutPointerX+=effect/2;
            }
            OutPointerX-=effect;
            OutPointerY+=effect/2;
        }
    }else if(Num==1 || Num==0){
        for(int i=OutPointerY;i<(OutPointerY+effect);i++){
            for(int j=OutPointerX;j<(OutPointerX+effect);j++){
                op[i][j]=Num;
               /* if(Num==1){
                    printf("op[%d][%d]\n",i,j);
                }*/
            }
        }
    }
}
void print(int op[][500],int side){
    int allWhite=1;
    for(int i=0;i<side;i++){
        for(int j=0;j<side;j++){
            if(op[i][j]==1){
                printf("%d,%d\n",i,j);
                allWhite=0;
            }
           // printf("%d\n",op[i][j]);
        }
    }
    if(allWhite)
        printf("all white\n");
}
int main(){
    char input[50000];
    int op[500][500];
    scanf(" %s",&input);
    int side,pointer=0;
    scanf(" %d",&side);
    toCoordinates(input,op,1,&pointer,0,0,side);
    print(op,side);
}
