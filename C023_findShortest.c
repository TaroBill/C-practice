#include <stdio.h>

int min(int arr[],int length){
    int smallest=arr[0];
    for(int i=1;i<length;i++){
        if(arr[i]<smallest)
            smallest=arr[i];
    }
    return smallest;
}
int findShortestRoad(int arr[][50],int arrlength,int remainArr[],int rLength,int currentPlace){
    if(rLength==1){
      //  printf("CurrentPlace: %d to %d Length is %d\n",currentPlace,remainArr[0],arr[currentPlace][remainArr[0]]);
        return arr[currentPlace][remainArr[0]];
    }
    int FindLeastArr[50],tempArr[50];
    int point=0,tempPoint=0;
    while(point<rLength){
        for(int i=0;i<rLength;i++){
            if(remainArr[i]==remainArr[point])
                continue;
            tempArr[tempPoint]=remainArr[i];
           // printf("tempArr[%d]: %d \n",tempPoint,tempArr[tempPoint]);
            tempPoint++;
        }
        FindLeastArr[point]=findShortestRoad(arr,arrlength,tempArr,tempPoint,remainArr[point])+arr[currentPlace][remainArr[point]];
       // printf("CurrentPlace: %d findShortestRoad : %d\n",currentPlace,FindLeastArr[point]);
        tempPoint=0;
        point++;
    }
    return min(FindLeastArr,point);
}
int main(){
    int length;
    int array[50][50];
    scanf(" %d",&length);
    for(int i=0;i<length;i++)
        for(int j=0;j<length;j++)
            scanf(" %d",&array[i][j]);
    int remainArr[50];
    int j,pointj=0;
    for(j=1;j<length;j++){
        remainArr[pointj]=j;
        pointj++;
    }
    int smallest=findShortestRoad(array,length,remainArr,j-1,0);
    printf("%d\n",smallest);
    return 0;
}
