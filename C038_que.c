#include <stdio.h>
typedef struct stack_s{
    char name[100];
    int nameLength;
    int age;
    int year;
    int month;
    int date;
    struct stack_s *next;
}stack_t;
typedef stack_t *stackp_t;

stackp_t addStack(stackp_t sp,char names[],int NameLength,int age,int year,int month,int date){
    stackp_t newStack;
    newStack=(stackp_t)malloc(sizeof(stack_t));
    for(int i=0;i<NameLength;i++){
        *(newStack->name+i)=names[i];
    }
    newStack->nameLength=NameLength;
    newStack->age=age;
    newStack->year=year;
    newStack->month=month;
    newStack->date=date;
    newStack->next=NULL;
    if(sp==NULL){
        return newStack;
    }else{
        stackp_t head=sp;
        while(sp->next!=NULL)
            sp=sp->next;
        sp->next=newStack;
        return head;
    }
}

int main(){
    stackp_t Lists=NULL;
    int mode=0;
    char c;
    int l=0;
    int age;
    int year;
    int month;
    int date;
    int choose;
    char Name[100];
    scanf("%d",&mode);
    while(mode!=3){
        if(mode==1){
            l=0;
            scanf("%c",&c);
            scanf("%c",&c);
            scanf("%c",&c);
            while(c!='"'){
                Name[l]=c;
                l++;
                scanf("%c",&c);
            }
            scanf(" %d",&age);
            scanf(" %d",&year);
            scanf(" %d",&month);
            scanf(" %d",&date);
            /* for(int i=0;i<l;i++)
                printf("%c",Name[i]);
            printf("\nage:%d\n",age);
            printf("birth: %d_%d_%d\n",year,month,date);*/
            Lists = addStack(Lists,Name,l,age,year,month,date);
        }else if(mode==2){
            scanf(" %d",&choose);
            if(Lists ==NULL){
                printf("The Queue is empty\n");
                scanf("%d",&mode);
                continue;
            }else if(choose==1){
                for(int i=0;i<Lists->nameLength;i++)
                    printf("%c",Lists->name[i]);
                printf("\n");
            }else if(choose==2){
                printf("%d\n",Lists->age);
            }else if(choose==3){
                printf("%d_%d_%d\n",Lists->year,Lists->month,Lists->date);
            }
            stackp_t t=Lists;
            Lists=Lists->next;
            free(t);
        }
        scanf("%d",&mode);
    }
    return 0;
}
