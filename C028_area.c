#include <stdio.h>
#include <math.h>
double f1(double a,double x){return sqrt(a-x*x);}
double f2(double a,double x){return (a*x*x*x+7*x)/sqrt(a+x);}
double abs(double d)
{
    if(d<0)
        d*=-1;
    return d;
}
double area(double (*f)(double,double),int n,double p,double q,double a){
    long double gap = (q-p)/n;
    double areas=0;
    int i=0;
    double total=0;
    do {
        total += abs((*f)(a,p+gap*(++i)));
    }while(i<n-1);
    areas=(total*2+abs((*f)(a,p))+abs((*f)(a,q)))*gap/2;
    return areas;
}

int main(){
    int er;
    int n=1;
    double a;
    double p,q;
    int choiceFunction;
    do{
        scanf(" %d",&choiceFunction);
        if(choiceFunction==0)
            break;
        scanf(" %lf",&a);
        scanf(" %lf",&p);
        scanf(" %lf",&q);
        scanf(" %d",&er);
        double Result;
        double lastResult;
        double test;
        double err=pow(10,er);
        double temp;
        if(p>q){
            temp=p;
            p=q;
            q=temp;
        }
        switch(choiceFunction){
            case 1:
                n=1;
                lastResult=area(f1,n,p,q,a);
                n=n<<1;
                Result=area(f1,n,p,q,a);
                test = lastResult-Result;
                if(test<0)test=0-test;
                while(test*err>1.0){
                    lastResult=Result;
                    n=n<<1;
                    Result=area(f1,n,p,q,a);
                    test = lastResult-Result;
                    //printf("Last: %lf\n",lastResult);
                    //printf("Now: %lf\n",Result);
                    if(test<0)test=0-test;
                }
                break;
            case 2:
                n=1;
                lastResult=area(f2,n,p,q,a);
                n=n<<1;
                Result=area(f2,n,p,q,a);
                test = lastResult-Result;
                if(test<0)test=0-test;
                while(test*err>1.0){
                    lastResult=Result;
                    n=n<<1;
                    Result=area(f2,n,p,q,a);
                    test = lastResult-Result;
                    //printf("Last: %lf\n",lastResult);
                    //printf("Now: %lf\n",Result);
                    if(test<0)test=0-test;
                }
                break;
        }
        printf("%.12f\n",Result);
    }while(choiceFunction!=0);
    return 0;
}
