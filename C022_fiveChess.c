#include <stdio.h>
#define N 10
int Line(int array[][N],int op[],int *opIndex,int x,int y,int mode,int count,int keep,int *kx,int *ky){
    if(keep){
        if(array[y][x]==0)
            keep=0;
        switch(mode){
            case 1://往右
                if(!keep){
                    if(x+1>=N)
                        return 0;
                    *kx=x;
                    *ky=y;
                    return Line(array,op,opIndex,x+1,y,1,count,0,kx,ky);
                }
                if(count>=4){
                    if(x+1>=N)
                        return 1;
                    else{
                        op[*opIndex]= y*10+x+1;
                        (*opIndex)++;
                        return 1;
                    }
                }else{
                    if(x+1>=N)
                        return 0;
                    else
                        return Line(array,op,opIndex,x+1,y,1,count+1,1,kx,ky);
                }
                break;
            case 2://往左下
                if(!keep){
                    if(y+1>=N || x-1<0)
                        return 0;
                    *kx=x;
                    *ky=y;
                    return Line(array,op,opIndex,x-1,y+1,2,count,0,kx,ky);
                }
                if(count>=4){
                    if(y+1>=N || x-1<0)
                        return 1;
                    else{
                        op[*opIndex]=(y+1)*10+x-1;
                        (*opIndex)++;
                        return 1;
                    }
                }else{
                    if(y+1>=N || x-1<0)
                        return 0;
                    else
                        return Line(array,op,opIndex,x-1,y+1,2,count+1,1,kx,ky);
                }
                break;
            case 3://往下
                if(!keep){
                    if(y+1>=N)
                        return 0;
                    *kx=x;
                    *ky=y;
                    return Line(array,op,opIndex,x,y+1,3,count,0,kx,ky);
                }
                if(count>=4){
                    if(y+1>=N)
                        return 1;
                    else{
                        op[*opIndex]=(y+1)*10+x;
                        (*opIndex)++;
                        return 1;
                    }
                }else{
                    if(y+1>=N)
                        return 0;
                    else
                        return Line(array,op,opIndex,x,y+1,3,count+1,1,kx,ky);
                }
                break;
            case 4: //往右下
                 if(!keep){
                    if(y+1>=N || x+1>=N)
                        return 0;
                    *kx=x;
                    *ky=y;
                    return Line(array,op,opIndex,x+1,y+1,4,count,0,kx,ky);
                 }
                 if(count>=4){
                    if(y+1>=N || x+1>=N)
                        return 1;
                    else{
                        op[*opIndex]= (y+1)*10+x+1;
                        (*opIndex)++;
                        return 1;
                    }
                }else{
                    if(y+1>=N || x+1>=N)
                        return 0;
                    else
                        return Line(array,op,opIndex,x+1,y+1,4,count+1,1,kx,ky);
                }
                break;
        }
    }else{
        if(array[y][x]==0)
            return 0;
        switch(mode){
            case 1://往右
                if(count>=4){
                    return 2;
                }else{
                    if(x+1>=N)
                        return 0;
                    else
                        return Line(array,op,opIndex,x+1,y,1,count+1,0,kx,ky);
                }
                break;
            case 2://往左下
                if(count>=4){
                    return 2;
                }else{
                    if(y+1>=N || x-1<0)
                        return 0;
                    else
                        return Line(array,op,opIndex,x-1,y+1,2,count+1,0,kx,ky);
                }
                break;
            case 3://往下
                if(count>=4){
                    return 2;
                }else{
                    if(y+1>=N)
                        return 0;
                    else
                        return Line(array,op,opIndex,x,y+1,3,count+1,0,kx,ky);
                }
                break;
            case 4: //往右下
                 if(count>=4){
                    return 2;
                }else{
                    if(y+1>=N || x+1>=N)
                        return 0;
                    else
                        return Line(array,op,opIndex,x+1,y+1,4,count+1,0,kx,ky);
                }
                break;
        }
    }
    return 0;
}
void findWinPossible(int array[][N],int op[],int *opIndex){
    int kx,ky;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(array[i][j]==1){
                int modeA=Line(array,op,opIndex,j,i,1,1,1,&kx,&ky);
                if(modeA==1){
                    //printf("+1\n");
                    if(j-1>=0){
                        op[*opIndex]= i*10+j-1;
                        (*opIndex)++;
                    }
                }else if(modeA==2){
                   // printf("modA2\n");
                    op[*opIndex]= ky*10+kx;
                    (*opIndex)++;
                }
                int modeB=Line(array,op,opIndex,j,i,2,1,1,&kx,&ky);
                if(modeB==1){
                    //printf("+1\n");
                    if(i-1>=0 && j+1<N){
                        op[*opIndex]= (i-1)*10+j+1;
                        (*opIndex)++;
                    }
                }else if(modeB==2){
                    //printf("modB2\n");
                    op[*opIndex]= ky*10+kx;
                    (*opIndex)++;
                }
                int modeC=Line(array,op,opIndex,j,i,3,1,1,&kx,&ky);
                if(modeC==1){
                    //printf("+1\n");
                    if(i-1>=0){
                        op[*opIndex]= (i-1)*10+j;
                        (*opIndex)++;
                    }
                }else if(modeC==2){
                    //printf("modC2\n");
                    op[*opIndex]= ky*10+kx;
                    (*opIndex)++;
                }
                int modeD=Line(array,op,opIndex,j,i,4,1,1,&kx,&ky);
                if(modeD==1){
                    //printf("+1\n");
                    if(i-1>=0 && j-1>=0){
                        op[*opIndex]= (i-1)*10+j-1;
                        (*opIndex)++;
                    }
                }else if(modeD==2){
                    //printf("modD2\n");
                    op[*opIndex]= ky*10+kx;
                    (*opIndex)++;
                }
            }
        }
    }
}
void BubbleSort(int arr[], int len)
{
	int i, j, temp;
	for (i = 0; i < len - 1; ++i)          //循環N-1次
		for (j = 0; j < len - 1 - i; ++j)  //每次循環要比較的次數
			if (arr[j] > arr[j + 1])       //比大小後交換
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
}
int main(){
    int array[N][N];
    int op[100];
    int opIndex=0;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            scanf(" %d",&array[i][j]);
    findWinPossible(array,op,&opIndex);
    BubbleSort(op,opIndex);
    int y,x,ly=10,lx=10;
    for(int i=0;i<opIndex;i++){
        x=op[i]%10;
        y=op[i]/10;
        if(ly==y && lx==x)
            continue;
        printf("%d %d\n",y,x);
        ly=y;
        lx=x;
    }
    if(opIndex==0)
        printf("impractical attempt!\n");
}
