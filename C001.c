#include <stdio.h>
#include <math.h>

int main(){
    int a,b,c;
    scanf(" %d",&a);
    scanf(" %d",&b);
    scanf(" %d",&c);
    float A1,A2;
    A1 = ((-b)+sqrt(b*b-4*a*c))/(2*a);
    A2 = ((-b)-sqrt(b*b-4*a*c))/(2*a);
    printf("%.1f\n",A1);
    printf("%.1f",A2);
    return 0;
}
