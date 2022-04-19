#include <stdio.h>
#include <stdlib.h>
#define pi 3.1415926
void matrixAdd(double A[][10],double B[][10],int row, int column,double output[][10],int minusControl){
    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
            if(minusControl==0)
                output[i][j]=A[i][j]+B[i][j];
            else
                output[i][j]=A[i][j]-B[i][j];
        }
    }
}
void matrixMultiInt(double A[][10],double B,int row, int column,double output[][10]){
    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
                output[i][j]=B*A[i][j];
        }
    }
}
void printMatrix(double A[][10],int row, int column){
    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
            if(fabs(A[i][j]-(int)A[i][j])<0.01)
                printf("%.0f ",A[i][j]);
            else
                printf("%.2f ",A[i][j]);
        }
        printf("\n");
    }
}
void matrixTranspose(double A[][10],int row,int column,double output[][10]){
    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
            output[j][i]=A[i][j];
        }
    }
}
void matrixMulti(double A[][10],int rowA,int columnA,double B[][10],int rowB,int columnB,double output[][10],int *OpRow,int *OpColumn){
    if(columnA != rowB){
        printf("ERROR\n");
        return;
    }
    for(int i=0;i<rowA;i++){
        for(int j=0;j<columnB;j++){
            double sum=0;
            for(int l=0;l<columnA;l++){
                sum+=A[i][l]*B[l][j];
            }
            output[i][j]=sum;
        }
    }
    *OpRow=rowA;
    *OpColumn=columnB;
}
void matrixInverse(double A[][10],int row,int column,double output[][10]){
    if(row!=2 || column !=2){
        printf("I don't know how to solve it.\n");
        return;
    }
    double test = (A[0][0]*A[1][1])-(A[0][1]*A[1][0]);
    if(test <0.001 && test > -0.001){
        printf("This Matrix doesn't have inverse matrix\n");
        return;
    }
    double temp[10][10]={{A[1][1],-A[0][1]},
                          -A[1][0],A[0][0]};
    matrixMultiInt(temp,1.0/test,2,2,output);
}
int main(){
    double A[10][10]={{2,-1},
                     {3,5}};
    double B[10][10]={{-2,0},
                     {4,2}};
    double C[10][10]={{-1,2,0},
                    {2,0,3}};
    double D[10][10]={{2,0,-1},
                    {1,-2,0}};
    double E[10][10]={{2,-1},
                    {pi,log10(2)},
                    {-2,6}};
    double I[10][10]={{1,0},
                   {0,1}};

    double twoB[10][10];
    double AplusTwoB[10][10];
    //printMatrix(E,3,2);
    printf("A+2B: \n");
    matrixMultiInt(B,2,2,2,twoB);
    matrixAdd(A,twoB,2,2,AplusTwoB,0);
    printMatrix(AplusTwoB,2,2);
    printf("\n");

    double CminusD[10][10];
    printf("C-D: \n");
    matrixAdd(C,D,2,3,CminusD,1);
    printMatrix(CminusD,2,3);
    printf("\n");

    double AT[10][10];
    printf("A^T: \n");
    matrixTranspose(A,2,2,AT);
    printMatrix(AT,2,2);
    printf("\n");

    double F[10][10];
    int FRow;
    int FColumn;
    printf("F=A*B= \n");
    matrixMulti(A,2,2,B,2,2,F,&FRow,&FColumn);
    printMatrix(F,FRow,FColumn);
    printf("\n");

    double G[10][10];
    int GRow;
    int GColumn;
    printf("G=B*A= \n");
    matrixMulti(B,2,2,A,2,2,G,&GRow,&GColumn);
    printMatrix(G,GRow,GColumn);
    printf("\n");
    printf("NO!  G is not equal to F \n\n");

    double M[10][10];
    int MRow;
    int MColumn;
    printf("M=C*E= \n");
    matrixMulti(C,2,3,E,3,2,M,&MRow,&MColumn);
    printMatrix(M,MRow,MColumn);
    printf("\n");

    double N[10][10];
    int NRow;
    int NColumn;
    printf("N=E*C= \n");
    matrixMulti(E,3,2,C,2,3,N,&NRow,&NColumn);
    printMatrix(N,NRow,NColumn);
    printf("\n");
    printf("NO!  M is not equal to N \n\n");

    double ATA[10][10];
    int ATARow;
    int ATAColumn;
    printf("A^T * A: \n");
    matrixMulti(AT,2,2,A,2,2,ATA,&ATARow,&ATAColumn);
    printMatrix(ATA,ATARow,ATAColumn);
    printf("\n");

    double Am1[10][10];
    printf("A^-1: \n");
    matrixInverse(A,2,2,Am1);
    printMatrix(Am1,2,2);
    printf("\n");

    double AAm1[10][10];
    int AAm1Row;
    int AAm1Column;
    printf("A * A^-1: \n");
    matrixMulti(A,2,2,Am1,2,2,AAm1,&AAm1Row,&AAm1Column);
    printMatrix(AAm1,AAm1Row,AAm1Column);
    printf("\n");
    printf("Yes A * A^-1 is equal to I. \n\n");

    double Fm1[10][10];
    printf("F^-1: \n");
    matrixInverse(F,2,2,Fm1);
    printMatrix(Fm1,2,2);
    printf("\n");

    double FFm1[10][10];
    int FFm1Row;
    int FFm1Column;
    printf("F * F^-1: \n");
    matrixMulti(F,2,2,Fm1,2,2,FFm1,&FFm1Row,&FFm1Column);
    printMatrix(FFm1,FFm1Row,FFm1Column);
    printf("\n");
    printf("Yes F * F^-1 is equal to I. \n\n");

    return 0;
}
