#include <stdio.h>
void xyChange(int array[][50],int sideLength){
    int temp[50][50];
    for(int i=0;i<sideLength;i++)
        for(int j=0;j<sideLength;j++)
            temp[j][i]=array[i][j];


    for(int i=0;i<sideLength;i++)
        for(int j=0;j<sideLength;j++)
            array[i][j]=temp[i][j];

}
void mirrorX(int array[][50],int sideLength){
    int temp[50][50];
        for(int i=0;i<sideLength;i++)
            for(int j=0;j<sideLength;j++)
                temp[i][j]=array[i][sideLength-j-1];

    for(int i=0;i<sideLength;i++)
        for(int j=0;j<sideLength;j++)
            array[i][j]=temp[i][j];

}
void mirrorY(int array[][50],int sideLength){
    int temp[50][50];
        for(int i=0;i<sideLength;i++)
            for(int j=0;j<sideLength;j++)
                temp[i][j]=array[sideLength-i-1][j];

    for(int i=0;i<sideLength;i++)
        for(int j=0;j<sideLength;j++)
            array[i][j]=temp[i][j];

}
void print(int array[][50],int sideLength){
    for(int i=0;i<sideLength;i++){
        for(int j=0;j<sideLength;j++){
            printf("%d ",array[i][j]);
        }
        printf("\n");
    }
}

void rotateLeft(int array[][50],int sideLength){
    mirrorX(array,sideLength);
    xyChange(array,sideLength);
}
void rotateRight(int array[][50],int sideLength){
    xyChange(array,sideLength);
    mirrorX(array,sideLength);
}
void flip(int array[][50],int sideLength){
    mirrorY(array,sideLength);
}
int main(){
    int array[50][50];
    int sideLength;
    int mode;
    int num=1;
    scanf(" %d",&sideLength);
    scanf(" %d",&mode);
    for(int i=0;i<sideLength;i++){
        for(int j=0;j<sideLength;j++){
            array[i][j]=num;
            num++;
        }
    }
    switch(mode){
        case 2:
            rotateRight(array,sideLength);
            break;
        case 3:
            rotateLeft(array,sideLength);
            break;
        case 4:
            flip(array,sideLength);
            break;
    }
    print(array,sideLength);
}
