#include <stdio.h>

int main(){
    int player = 0;
    char pstat[] = {0,0,0,0,0};
    int stat=0;
    int out=0;
    while(player <5){
        scanf(" %c",&pstat[player]);
        //printf("%d\n",pstat[player]);
        int st = pstat[player]-48;
        if(st<=9){
            stat = (stat<<st) | (1<<(st-1));
        }else if(st==24){
            stat=0;
        }else if(st==31){
            out++;
            if(out>2){
                stat=0;
                break;
            }
        }
        player++;
    }
    stat = stat & 7;
    int i=0;
    while(i<3){
        printf("%d\n",stat & 1);
        stat=stat>>1;
        i++;
    }
    return 0;
}
