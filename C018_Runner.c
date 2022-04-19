#include <stdio.h>

void FindOut(char arr[][50],int outAmount,int total,int *ia,int *ib){
    int i=0;
    int PT=1;
    int Out=0;
    while(total>0){
        if(arr[i][PT]=='O')
            Out++;
        if(Out>=outAmount){
            *ia=i;
            *ib=PT;
            break;
        }
        i++;
        if(i>=9){
            i=0;
            PT++;
        }
        total--;
    }
}
int getScore(char arr[][50],int indexA,int indexB,int NthPlayer,int *HitsByN,int *ScoreByN){
    int score=0;
    int player = 0;
    int totalPlayers=(indexB-1)*9+(indexA+1);
    /*  index=[2][5] 總共39名 (5-1)*9+(2+1)
        900000
        900000
        900001
        90000
        90000
        90000
        90000
        90000
        90000
    */
    char pstat[100];
    long long int stat=0;
    int NthHit=0;
    long long int NthStat=0;
    int NthScore=0;
    int out=0;
    int i=0;
    int PT=1;
  //  printf("totalPlayers: %d\n",totalPlayers);
    while(player<totalPlayers){
      //  printf("player: %d, score: %d\n",player,score);
        pstat[player]= arr[i][PT];
        //printf("%d\n",pstat[player]);
        int st = pstat[player]-48;
        if(st<=9){
            stat = (stat<<st) | (1<<(st-1));
            if(i==NthPlayer){
                NthStat= (NthStat<<st)|(1<<(st-1));
                NthHit++;
            }else{
                NthStat=NthStat<<st;
            }
        }else if(st==24){
            if(i==NthPlayer){
                NthHit++;
                NthScore++;
            }
            while(NthStat){
                NthScore+=(NthStat&1);
                NthStat=NthStat>>1;
            }
            NthStat=0;
            while(stat){
                score+=(stat&1);
                stat=stat>>1;
            }
            score++;
            stat=0;
        }else if(st==31){
            out++;
            if(out>2){
                NthStat=NthStat>>3;
                stat=stat>>3;
                while(stat){
                    score+=(stat&1);
                    stat=stat>>1;
                }
                while(NthStat){
                    NthScore+=(NthStat&1);
                    NthStat=NthStat>>1;
                }
                NthStat=0;
                stat=0;
                out=0;
            }
        }
        player++;
        i++;
        if(i>=9){
            i=0;
            PT++;
        }
    }
    NthStat=NthStat>>3;
    stat=stat>>3;
    while(NthStat){
        NthScore+=(NthStat&1);
        NthStat=NthStat>>1;
    }
    while(stat){
        score+=(stat&1);
        stat=stat>>1;
    }
    *HitsByN = NthHit;
    *ScoreByN = NthScore;
    return score;
}
int main(){
    char fullState[9][50];
    int total=0;
    for(int i=0;i<9;i++){
        scanf(" %c",&fullState[i][0]);
        int count=fullState[i][0]-48;
        total+=count;
        for(int j=1;j<=count;j++)
            scanf(" %c",&fullState[i][j]);
    }
    int indexA,indexB;
    int outAmount;
    int NthPlayer,Nhit,NScore;
    scanf(" %d",&outAmount);
    scanf(" %d",&NthPlayer);
    NthPlayer--;
    FindOut(fullState,outAmount,total,&indexA,&indexB);
    //printf("indexA: %d, indexB: %d\n",indexA,indexB);
    int score = getScore(fullState,indexA,indexB,NthPlayer,&Nhit,&NScore);
    //printf("score: %d\n",score);
    //printf("Hits By N: %d\n",Nhit);
    //printf("Score By N: %d\n",NScore);
    printf("%d\n",score);
    printf("%d,%d",Nhit,NScore);
    return 0;
}

