#include <stdio.h>
long long int S(int A[],int B[],int lengthA,int lengthB){
    long long int Count=0;
    for(int i=0;i<lengthA;i++){
        for(int j=0;j<lengthB;j++){
            if(A[i]>B[j]){
                Count++;
            }
        }
    }
    return Count;
}
long long int W(int X[],int lengthX){
    if(lengthX>3){
        int A[30000],B[30000];
        int lengthA,lengthB,pointB=0;
        if(lengthX % 2==1){
            lengthA=(lengthX+1)/2;
            lengthB=(lengthX-1)/2;
            for(int i=0;i<lengthX;i++){
                if(i<lengthA)
                    A[i]=X[i];
                else{
                    B[pointB]=X[i];
                    pointB++;
                }
            }
            return W(A,lengthA)+W(B,lengthB)+S(A,B,lengthA,lengthB);
        }else{
            lengthA=lengthX/2;
            lengthB=lengthX/2;
            for(int i=0;i<lengthX;i++){
                if(i<lengthA)
                    A[i]=X[i];
                else{
                    B[pointB]=X[i];
                    pointB++;
                }
            }
            return W(A,lengthA)+W(B,lengthB)+S(A,B,lengthA,lengthB);
        }
    }else{
        int Count=0;
        for(int i=0;i<lengthX-1;i++){
           for(int j=i+1;j<lengthX;j++){
                if(X[i]>X[j])
                    Count++;
            }
        }
        return Count;

    }

}
int main(){
    int length;
    unsigned long long int Count;
    int array[50000];
    scanf(" %d",&length);
    for(int i=0;i<length;i++){
        scanf(" %d",&array[i]);
    }
    Count = W(array,length);
    printf("%lld\n",Count);
    return 0;
}

