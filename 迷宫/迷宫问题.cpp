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
//�½�һ����ջ
SeqStack *InitStack (){
	SeqStack *S;
	S=(SeqStack *)malloc(sizeof(SeqStack));
	S->top =-1; 
	return S;
}
//�ж��Ƿ�Ϊ��ջ 
int StackEmpty (SeqStack *S){
	if(S->top==-1)
		return TRUE;
	else 
		return FALSE; 
} 
//��ջ
int Push (SeqStack *S,pos e){
	if(S->top==MAXSIZE-1)
		return FALSE;
	S->top++;
	S->data[S->top]= e;
	return TRUE;
} 
//��ջ������ 
int Pop (SeqStack *S,pos *e){
	if(S->top == -1)
		return FALSE;
	*e=S->data[S->top];
	S->top--;	
	return TRUE;
} 
//ȡ��ջ��Ԫ�� 
int GetTop (SeqStack *S,pos *e){
	if(S->top == -1)
		return FALSE;
	else{
		*e=S->data[S->top];	
		return TRUE;
	}
} 
SeqStack *SS;
int book[M][M];//������� 
int map[M][M];//��ͼ 
char out[M][M][3];//�������
int width,high;//�Թ��Ŀ�� 
int count ;//��¼�߷� 
pos read(){   //���ļ��ж��� 
	FILE *fp;
	pos e;	
	fp = fopen("read.txt","r+"); 
	if(fp==NULL)
    {
        printf("�ļ���ʧ��\n");
        exit(0);
    }
	fscanf(fp,"%d %d",&width,&high);//¼���Թ��Ŀ�͸� 
	fscanf(fp,"%d %d",&e.x,&e.y);//¼���Թ������ 
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
	for(i=0;i<high;i++){     //��ʼ��������� 
		for(j=0;j<width;j++){
			str[0]=map[i][j]+'0';
			str[1]=' ';
			str[2]=0;
			strcpy(out[i][j],str);	
		}
	}
	for(i=0;i<SS->top+1;i++){ //���·�� 
		if(SS->data[i].dir==0){
			strcpy(out[SS->data[i].x][SS->data[i].y],"��");
		}else if(SS->data[i].dir==1){
			strcpy(out[SS->data[i].x][SS->data[i].y],"��");
		}else if(SS->data[i].dir==2){
			strcpy(out[SS->data[i].x][SS->data[i].y],"��");
		}else if(SS->data[i].dir==3){
			strcpy(out[SS->data[i].x][SS->data[i].y],"��");
		}
	
	}	
	//�������ļ��в����������Ļ��
	FILE *fp;
	if(count==1){
		fp = fopen("output.txt","w+");
	}
	else{
		fp = fopen("output","a+");
	}	
	 if(fp==NULL)
    {
        printf("�ļ���ʧ��\n");
        exit(0);
    }
    fprintf(fp,"��%d�߷�\n",count); 
    printf("\n��%d�߷�\n",count);
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
	int next[4][2]={{0,1},//�� 
	                {1,0},//�� 
			        {0,-1},//�� 
	                {-1,0}};//��
	pos e1,e2;
	e1 = e;
	e1.dir=0;
	do{	
			for(k=e1.dir;k<4;k++){
			e2.x=e1.x+next[k][0];//��һ�� 
			e2.y=e1.y+next[k][1];
			e1.dir=k;
			if(e2.x<0||e2.y<0||e2.y>=width||e2.x>=high)//�ж��Ƿ�Խ�� 
				continue;
			if(map[e2.x][e2.y]!=1&&book[e2.x][e2.y]==0)//�ж���һ���Ƿ��߹����Ƿ����ϰ���
			{
				//��ջ 
				Push(SS,e1);
				book[e1.x][e1.y]=1;//���
				e1=e2; 
				e1.dir=0;
				//printf("��(%d,%d)%d\n",e1.x,e1.y,e1.direction);
				break;				
			} 
			
		}
		int i;
		//�����յ� 
		if(map[e1.x][e1.y]==2){
			Push(SS,e1);
			count++; 
			output();//������ 
			Pop(SS,&e1);
		}
		
		if(k==4||map[e1.x][e1.y]==2){
			//��ջ 
			Pop(SS,&e1);
			book[e1.x][e1.y]=0;
			//printf("��(%d,%d)%d\n",e1.x,e1.y,e1.direction); 
			e1.dir++;
		}
	}while(!StackEmpty(SS)||e1.dir!=4);	
}
void loginmenu()
{
system("color 0f");
printf("\t\t\t\t\t\t��ӭ�����Թ�С��Ϸϵͳ\t\t\t\t\n");
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
	printf("��ȡ�ļ���...\n"); 
	e=read();
	dfs(e);//��һ����������ʼ���x���꣬�ڶ�����������ʼ���y���꣬�����������ǲ��� 
}


