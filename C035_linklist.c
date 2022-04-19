#include <stdio.h>
#include <string.h>
typedef struct node_s{
    int data;
    struct node_s *next;
    struct node_s *behind;
}node_t;
typedef node_t *nodep_t;

nodep_t addNode(nodep_t np,int data){
    nodep_t newNode;
    newNode=(nodep_t)malloc(sizeof(node_t));
    newNode->data=data;
    if(np==NULL){
        newNode->next=NULL;
    }else{
        newNode->next=np;
        np->behind=newNode;
    }
    newNode->behind=NULL;
    return newNode;
}
nodep_t addNode2(nodep_t np,int data){
    nodep_t newNode;
    newNode=(nodep_t)malloc(sizeof(node_t));
    newNode->data=data;
    if(np==NULL){
        newNode->behind=NULL;
    }else{
        newNode->behind=np;
        np->next=newNode;
    }
    newNode->next=NULL;
    return newNode;
}
void print(nodep_t np){
    nodep_t current=np;
    while(current!=NULL){
        np=current;
        current=current->next;
    }
    current=np;
    int zeroTest=1;
    while(current!=NULL){
        np=current;
        if(zeroTest && current->data==0){
            free(current);
            current=current->behind;
            continue;
        }
        zeroTest=0;
        printf("%d ",current->data);
        free(current);
        current=np->behind;
    }
    if(zeroTest)
        printf("0");
}
nodep_t add(nodep_t data1, nodep_t data2,int minus){
    nodep_t output=NULL;
    while(data1!=NULL || data2!=NULL){
        int D1=0,D2=0;
        if(data1==NULL)
            D1=0;
        else
            D1=data1->data;
        if(data2==NULL)
            D2=0;
        else
            D2=data2->data;
        if(minus)
            output = addNode2(output,D1-D2);
        else
            output = addNode2(output,D1+D2);
        if(data1!=NULL)
            data1=data1->next;
        if(data2!=NULL)
            data2=data2->next;
    }
    while(output->behind!=NULL)
        output=output->behind;
    return output;
}
nodep_t multiDig(nodep_t data1,int d,int offset){
    nodep_t output=NULL;
    while(offset>0){
        offset--;
        output=addNode2(output,0);
    }
    while(data1!=NULL){
        int D=data1->data * d;
        output=addNode2(output,D);
        data1=data1->next;
    }
    while(output->behind!=NULL)
        output=output->behind;
    return output;
}
nodep_t multi(nodep_t data1,nodep_t data2){
    nodep_t output=NULL;
    nodep_t c=NULL;
    int offset=0;
    nodep_t result=NULL;
    while(data2 !=NULL){
        output = multiDig(data1,data2->data,offset);
        offset++;
        result=add(output,result,0);
       /* while(output!=NULL){
            c=output;
            free(output);
            output=c->next;
        }*/
        data2=data2->next;
    }
    return result;
}
int main(){
    char c;
    int ip;
    nodep_t data1=NULL;
    nodep_t data2=NULL;
    do{
        scanf("%d",&ip);
        scanf("%c",&c);
        data1 = addNode(data1,ip);
    }while(c!='\n');
    do{
        scanf("%d",&ip);
        scanf("%c",&c);
        data2 = addNode(data2,ip);
    }while(c!='\n');
    nodep_t op1=add(data1,data2,0);
    print(op1);
    printf("\n");
    nodep_t op2=add(data1,data2,1);
    print(op2);
    printf("\n");
    nodep_t op3=multi(data1,data2);
    print(op3);
    printf("\n");
    return 0;
}
