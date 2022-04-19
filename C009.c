

#include <stdio.h>
/*float poke(char ip){
    int num = ip-48;
    float result;
    if(num==17){
        result=1;
    }else if(num==26 ||num==33 ||num==27 ||num==106-47 ){
        result=0.5;
    }else if(num==1){
        result=10;
        fflush(stdin);
    }else if(num>1 && num <10){
        result=num;
    }else{
      //  printf("error\n");
        result=0;
    }
    return result;
}*/
float poke(char *zz){
	int Cou,j,k;
	float result;
	char *array_char[13]={"A","2","3","4","5","6","7","8","9","10","J","K","Q"};
	float array_num[13]={1,2,3,4,5,6,7,8,9,10,0.5,0.5,0.5};
	for(Cou=0;Cou<13;Cou++){
		if(strcmp(zz,array_char[Cou]) == 0){
			result=array_num[Cou];
			break;
		}
	}
	return result;
}

int main(){
    float player=0,computer=0;
    int p=1,c=1;
    char tmpPlayer[3],tmpComputer[3];
    char cont;
    do{
       // printf("%.1f vs. %.1f\n",player,computer);
        if(p){
            scanf(" %s",&tmpPlayer);
            player += poke(tmpPlayer);
            if(player > 10.5){
                p=0;
                player=0;
            } //判定爆掉

        }
        if((computer<player || computer<8.1)&&c){
            scanf(" %s",&tmpComputer);
            computer+=poke(tmpComputer);
        }else{
           // printf("C=00\n");
            c=0;
        }
        if(player >10.5)
            p=0;
        if(p){
            scanf(" %c",&cont);
            if(cont=='N')
                p=0;
        }
        if(computer>10.4){ //判定店鬧10.5或以上
           // printf("C=0\n");
            c=0;}
    }while(p || c);
    if(computer>10.5)
        computer=0;
    if(player>10.5)
        player=0;
    printf("%.1f vs. %.1f\n",player,computer);
    if(player>computer)
        printf("player wins\n");
    else if(player < computer)
        printf("computer wins\n");
    else
        printf("It's a tie\n");
    return 0;
}
