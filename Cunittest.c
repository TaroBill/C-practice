#include <stdio.h> // main.c
#include <math.h>
#include <assert.h>
double computeBMI(int kg, int height) {
    double BMI = 0.0, M = height/100.0;
    if (kg<=0 || height<=0)
        return 0;
    BMI = round(100*kg/(M*M))/100; //四捨五入取兩位小數
    if (BMI <18.5)
        return -1;
    if (BMI >24)
        return -2;
    return BMI;
}
int main(){
    assert(computeBMI(0,0)==0);
    assert(computeBMI(0,100)==0);
    assert(computeBMI(1,0)==0);
    assert(computeBMI(1,100)==-1);
    assert(computeBMI(100,100)==-2);
    assert(fabs(computeBMI(52,155) - 21.64f)<0.0001);
    return 0;
}

