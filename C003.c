#include <stdio.h>

int main(){
    int M1T,M2T,mph,balence;
    scanf(" %d",&M1T);
    scanf(" %d",&M2T);
    scanf(" %d",&mph);
    scanf(" %d",&balence);
    float income = (M1T + M2T)*mph;
    float tax = income * 0.08;
    float workM = balence * 0.05;
    printf("%.1f\n",income-tax-workM);
    printf("%.1f\n",workM);
    printf("%.1f\n",tax);



    return 0;
}
