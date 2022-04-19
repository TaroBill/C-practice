#include<stdio.h>
typedef struct node_s{
    int connectTo[99];
    int lengthConnectTo;
    int beConnected[99];
    int lengthBeConnected;
    int devDays;
    int done;
}node;
void createEmptyNode(node *n){
    n->lengthBeConnected=0;
    n->devDays=0;
    n->lengthConnectTo=0;
    n->done=0;
}
void nodeConnectCalculator(node n[],int number,int *days){
    //printf("n[number-1]->done: %d\n",n[number-1].done);
    /*if(n[number-1].done)
        return;
    for(int i=0;i<(n[number-1].lengthBeConnected);i++){
        if(!(n[(n[number-1].beConnected[i])-1].done)){
            *days+=n[number-1].devDays;
            return;
        }
    }*/
    //printf("Number: %d\n",number);
    *days+=n[number-1].devDays;
    n[number-1].done=1;
    int day[100];
    for(int i=0;i<(n[number-1].lengthConnectTo);i++){
        day[i]=0;
        nodeConnectCalculator(n, n[number-1].connectTo[i] ,&day[i]);
    }
    if(n[number-1].lengthConnectTo==0)
        return;
    int longest=day[0];
    for(int i=1;i<(n[number-1].lengthConnectTo);i++){
        if(day[i]>longest)
            longest=day[i];
    }
    *days+=longest;
}
int main(){
    int dataNum;
    scanf(" %d",&dataNum);
    for(int i=0;i<dataNum;i++){
        int days=0;
        node n[100];
        int nodeAmount;
        scanf(" %d",&nodeAmount);
        for(int j=0;j<nodeAmount;j++)
            createEmptyNode(&n[j]);
        for(int j=0;j<nodeAmount;j++){
            scanf(" %d",&n[j].devDays);
            scanf(" %d",&n[j].lengthConnectTo);
            for(int k=0;k<n[j].lengthConnectTo;k++){
                scanf(" %d",&n[j].connectTo[k]);
                n[n[j].connectTo[k]-1].beConnected[n[n[j].connectTo[k]-1].lengthBeConnected]=j+1;
                (n[n[j].connectTo[k]-1].lengthBeConnected)+=1;
            }
        }
       /* for(int j=0;j<nodeAmount;j++){
            printf("number: %d\n",j+1);
            printf("devDays: %d\n",n[j].devDays);
            printf("lengthConnectTo: %d\n",n[j].lengthConnectTo);
            for(int k=0;k<n[j].lengthConnectTo;k++)
                printf("connect to %d\n",n[j].connectTo[k]);
            printf("lengthBeConnected: %d\n",n[j].lengthBeConnected);
            for(int k=0;k<n[j].lengthBeConnected;k++)
                printf("Be connected to %d\n",n[j].beConnected[k]);
        }*/
        nodeConnectCalculator(n,1,&days);
        printf("%d\n",days);
    }
    return 0;
}
