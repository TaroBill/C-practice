#include <stdio.h>
#include <math.h>

int gcd(int m, int n) {
    while(n != 0) {
        int r = m % n;
        m = n;
        n = r;
    }
    return m;
}
int main(){
    int chi,mot,chi2,mot2;
    char operater,operater2,operater3;
    int mother;
    int child;
    int carry;
    char state=1;
    int devide;
    while(state != 'n'){
        scanf(" %d%c%d",&chi,&operater,&mot);
        //printf("c=%d\noperater=%c\nm=%d\n",chi,operater,mot);
        scanf(" %d%c%d",&chi2,&operater2,&mot2);
        scanf(" %c",&operater3);
        switch(operater3){
            case('+'):
                carry=0;
                mother = mot * mot2;
                child = (chi * mot2) + (chi2 * mot);
                if(mother==0){
                    printf("ERROR\n");
                    scanf(" %c",&state);
                    continue;
                }else if(child==0){
                    printf("0\n");
                    scanf(" %c",&state);
                    continue;
                }
                while(abs(child) >= abs(mother)){
                    child -= mother;
                    carry++;
                }
                devide = gcd(abs(child),abs(mother));
                if(devide != 1){
                    child/=devide;
                    mother/=devide;
                }
                if(mother<0){
                    mother=0-mother;
                    child =0-child;
                }
                if(carry==0){
                    if(child==1 && mother==1)
                        printf("1\n");
                    else
                        printf("%d/%d\n",child,mother);
                }else{
                    if((child==1 || child==0) && mother==1)
                        printf("%d\n",carry);
                    else
                        printf("%d(%d/%d)\n",carry,child,mother);
                }
                break;
            case('-'):
                carry=0;
                mother = mot * mot2;
                child = (chi * mot2) - (chi2 * mot);
                if(mother==0){
                    printf("ERROR\n");
                    scanf(" %c",&state);
                    continue;
                }else if(child==0){
                    printf("0\n");
                    scanf(" %c",&state);
                    continue;
                }
                while(abs(child) >= abs(mother)){
                    child -= mother;
                    carry++;
                }
                devide = gcd(abs(child),abs(mother));
                if(devide != 1){
                    child/=devide;
                    mother/=devide;
                }
                if(mother<0){
                    mother=0-mother;
                    child =0-child;
                }
                if(carry==0){
                    if(child==1 && mother==1)
                        printf("1\n");
                    else
                        printf("%d/%d\n",child,mother);
                }else{
                    if((child==1 || child==0)&& mother==1)
                        printf("%d\n",carry);
                    else
                        printf("%d(%d/%d)\n",carry,child,mother);
                }
                break;
            case('*'):
                carry=0;
                mother = mot * mot2;
                child = chi * chi2;
                if(mother==0){
                    printf("ERROR\n");
                    scanf(" %c",&state);
                    continue;
                }else if(child==0){
                    printf("0\n");
                    scanf(" %c",&state);
                    continue;
                }
                while(abs(child) >= abs(mother)){
                    child -= mother;
                    carry++;
                }
                devide = gcd(abs(child),abs(mother));
                if(devide != 1){
                    child/=devide;
                    mother/=devide;
                }
                if(mother<0){
                    mother=0-mother;
                    child =0-child;
                }
                if(carry==0){
                    if(child==1 && mother==1)
                        printf("1\n");
                    else
                        printf("%d/%d\n",child,mother);
                }else{
                    if((child==1 || child==0)&& mother==1)
                        printf("%d\n",carry);
                    else
                        printf("%d(%d/%d)\n",carry,child,mother);
                }
                break;
            case('/'):
                carry=0;
                mother = mot * chi2;
                child = chi * mot2;
                if(mother==0){
                    printf("ERROR\n");
                    scanf(" %c",&state);
                    continue;
                }else if(child==0){
                    printf("0\n");
                    scanf(" %c",&state);
                    continue;
                }
                while(abs(child) >= abs(mother)){
                    child -= mother;
                    carry++;
                }
                devide = gcd(abs(child),abs(mother));
                if(devide != 1){
                    child/=devide;
                    mother/=devide;
                }
                if(mother<0){
                    mother=0-mother;
                    child =0-child;
                }
                if(carry==0){
                    if(child==1 && mother==1)
                        printf("1\n");
                    else
                        printf("%d/%d\n",child,mother);
                }else{
                    if((child==1 || child==0) && mother==1)
                        printf("%d\n",carry);
                    else
                        printf("%d(%d/%d)\n",carry,child,mother);
                }
                break;
        }
        scanf(" %c",&state);
    }
    return 0;
}
