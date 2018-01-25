#include <stdio.h>
#include <stdlib.h>
#include<string.h> 
#define MAXSIZE 20
#define TRUE 1
#define FALSE 0 
#define M 10
typedef struct{
	int x;
	int y;
	int dir;
}pos ;
typedef struct
{
	pos data[MAXSIZE]; 
	int top;
}SeqStack; 
//新建一个空栈
SeqStack *InitStack (){
	SeqStack *S;
	S=(SeqStack *)malloc(sizeof(SeqStack));
	S->top =-1; 
	return S;
}
//判断是否为空栈 
int StackEmpty (SeqStack *S){
	if(S->top==-1)
		return TRUE;
	else 
		return FALSE; 
} 
//入栈
int Push (SeqStack *S,pos e){
	if(S->top==MAXSIZE-1)
		return FALSE;
	S->top++;
	S->data[S->top]= e;
	return TRUE;
} 
//出栈并返回 
int Pop (SeqStack *S,pos *e){
	if(S->top == -1)
		return FALSE;
	*e=S->data[S->top];
	S->top--;	
	return TRUE;
} 
//取出栈顶元素 
int GetTop (SeqStack *S,pos *e){
	if(S->top == -1)
		return FALSE;
	else{
		*e=S->data[S->top];	
		return TRUE;
	}
} 
SeqStack *SS;
int book[M][M];//标记数组 
int map[M][M];//地图 
char out[M][M][3];//输出数组
int width,high;//迷宫的宽高 
int count ;//记录走法 
pos read(){   //从文件中读入 
	FILE *fp;
	pos e;	
	fp = fopen("read.txt","r+"); 
	if(fp==NULL)
    {
        printf("文件打开失败\n");
        exit(0);
    }
	fscanf(fp,"%d %d",&width,&high);//录入迷宫的宽和高 
	fscanf(fp,"%d %d",&e.x,&e.y);//录入迷宫的起点 
	e.dir=0;
	int i,j;
	for(i=0;i<high;i++){
		for(j=0;j<width;j++){
		fscanf(fp,"%d",&map[i][j]);	
		}
	}
	
	for(i=0;i<high;i++){
		for(j=0;j<width;j++){
			printf("%d ",map[i][j]);	
		}
		printf("\n");
	}
	fclose(fp); 
	return e;
} 
void output(){
	char str[3];
	int i,j;
	for(i=0;i<high;i++){     //初始化输出数组 
		for(j=0;j<width;j++){
			str[0]=map[i][j]+'0';
			str[1]=' ';
			str[2]=0;
			strcpy(out[i][j],str);	
		}
	}
	for(i=0;i<SS->top+1;i++){ //添加路径 
		if(SS->data[i].dir==0){
			strcpy(out[SS->data[i].x][SS->data[i].y],"→");
		}else if(SS->data[i].dir==1){
			strcpy(out[SS->data[i].x][SS->data[i].y],"↓");
		}else if(SS->data[i].dir==2){
			strcpy(out[SS->data[i].x][SS->data[i].y],"←");
		}else if(SS->data[i].dir==3){
			strcpy(out[SS->data[i].x][SS->data[i].y],"↑");
		}
	
	}	
	//保存在文件中并且输出到屏幕上
	FILE *fp;
	if(count==1){
		fp = fopen("output.txt","w+");
	}
	else{
		fp = fopen("output","a+");
	}	
	 if(fp==NULL)
    {
        printf("文件打开失败\n");
        exit(0);
    }
    fprintf(fp,"第%d走法\n",count); 
    printf("\n第%d走法\n",count);
    for(i=0;i<high;i++){
    	for(j=0;j<width;j++){
	    	fprintf(fp,"%s",out[i][j]); 
	    	printf("%s",out[i][j]);
	    }
	    fprintf(fp,"%c",'\n'); 
	    printf("\n");
    }
    fprintf(fp,"%c",'\n'); 
		
	fclose(fp); 	
}
int dfs(pos e){
	int k;
	int next[4][2]={{0,1},//右 
	                {1,0},//下 
			        {0,-1},//左 
	                {-1,0}};//上
	pos e1,e2;
	e1 = e;
	e1.dir=0;
	do{	
			for(k=e1.dir;k<4;k++){
			e2.x=e1.x+next[k][0];//下一步 
			e2.y=e1.y+next[k][1];
			e1.dir=k;
			if(e2.x<0||e2.y<0||e2.y>=width||e2.x>=high)//判断是否越界 
				continue;
			if(map[e2.x][e2.y]!=1&&book[e2.x][e2.y]==0)//判断下一步是否被走过和是否有障碍物
			{
				//入栈 
				Push(SS,e1);
				book[e1.x][e1.y]=1;//标记
				e1=e2; 
				e1.dir=0;
				//printf("入(%d,%d)%d\n",e1.x,e1.y,e1.direction);
				break;				
			} 
			
		}
		int i;
		//到达终点 
		if(map[e1.x][e1.y]==2){
			Push(SS,e1);
			count++; 
			output();//输出结果 
			Pop(SS,&e1);
		}
		
		if(k==4||map[e1.x][e1.y]==2){
			//出栈 
			Pop(SS,&e1);
			book[e1.x][e1.y]=0;
			//printf("出(%d,%d)%d\n",e1.x,e1.y,e1.direction); 
			e1.dir++;
		}
	}while(!StackEmpty(SS)||e1.dir!=4);	
}
void loginmenu()
{
system("color 0f");
printf("\t\t\t\t\t\t欢迎进入迷宫小游戏系统\t\t\t\t\n");
printf(" \t ========================================================================================================");
printf("\n");
printf("\n");
printf("\n");

}
int main(void)
{	
	pos e;
	int m,n;
	loginmenu();
	SS=InitStack();
	printf("读取文件中...\n"); 
	e=read();
	dfs(e);//第一个参数是起始点的x坐标，第二个参数是起始点的y坐标，第三个参数是步数 
}


