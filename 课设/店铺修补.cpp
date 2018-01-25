struct pu 
{
	int year;
	int month;
	int day;
	int rent;
};/*店铺的租赁时间结构体*/ 
typedef struct node
{
	char id[20];
	char name[20];
	char passward[20];
	char type[20];
	char manager[20];
    double area;
	double profit;
	double wuye;
	struct pu time;
    struct node *next;
}Node,*Linklist;
Linklist L;
Node *s,*r;
char ma[20];//密码，便于个体输出信息 
//---------------------------函数声明------------------------------- 
    void admin();
	void division();
	void person();
	Linklist Creat();
	void Output();
	Linklist delect();
	Linklist idfind();
	Linklist managerfind();//管理员查找函数 
	Linklist add();
	Linklist modify(); //修改函数 
	void savefile();
	Linklist readfile();
	void mainmenu();//主菜单，登录注册的菜单 
	void adminmenu(); //管理员菜单 
	void personmenu();//个体户菜单 
	void plus();//求物业和利润和 
	void login();//总登录函数 
    void adminlogin();// 管理员登录函数 
	void  personlogin();//个体户登录函数 
	Linklist Register();//个体户注册函数 
	void totalmenu();//查看总体信息菜单 
	void totalfind();//
	void sort();//店铺排序 
	void personinformation();//个体户信息查询 
	void personmodify();//个体户修改 
//----------------------------------------------------------
#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<windows.h>//改变颜色 
int main()
{
L=readfile();
login();
}
void login()
{
	
	int n;
	printf("\n");
	 mainmenu();
	printf("请选择：");
	while(1)
	{
		scanf("%d",&n);
		if(n==1)
		{
		adminlogin();	
		}
		if(n==2)
		{
		personlogin();
	    }  
	    if(n==3)
	    {
	    Register();
	    }
	}
}
void personlogin()
{
	
	int m=0,i;
	char  passward[20];
	char t[20];
	Node *q;
	printf("请输入店铺编号:");
	scanf("%s",t);
	if(L->next==NULL)
	{
		printf("没有此店铺信息\n");
	}
	for(q=L->next;q!=NULL;q=q->next)
	{
		if(strcmp(q->id,t)==0)
		{
			printf("请输入密码:");
			scanf("%s",passward);
			if(strcmp(q->passward,passward)==0)
			{
			//	m=1;
				strcpy(ma,q->id);
				printf("正在登录中\n");
				for(i=1;i<6;i++)
				{
					printf(".");
					Sleep(100);
				}
				printf("\n");
				person(); 
			}
			else
			{
				printf("\n请再次输入密码:");
				scanf("%s",passward);
				if(strcmp(q->passward,passward)==0)
				{
					m=1;
					printf("正在登录中");
					for(i=1;i<10;i++)
					{
						printf(".");
						Sleep(100);
					}
					printf("\n");
				}
				else
				{
					printf("密码输入错误!\n");
				}
			}

		}
	}
	if(!m)
	{
		printf("没有此店铺!");
	}
}
Linklist Register()// 
{
	Node *q,*p;
	q=L->next;
	while(q->next)
	{
	q=q->next;
	}
	p=(Node*)malloc(sizeof(Node));
    printf("请输入店铺编号，店铺名称，店铺密码，店铺地址，管理员\n");
    scanf("%s%s%s%s%s",p->id,p->name,p->passward,p->type,p->manager);
    printf("请输入店铺占地面积，利润,租赁日期，租赁时间,\n"); 
    scanf("%lf%lf%lf%d%d%d%d",&p->area,&p->profit,&p->wuye,&p->time.year,&p->time.month,&p->time.day,&p->time.rent);
    q->next=p;
    p->next=NULL;
//    while(s)
//    {
//    	
//    }
    printf("注册成功"); 
    savefile();
    return L;
}
void admin()
{
	system("cls");
	int m;
    L=readfile();
    while(1)
		{ 
		adminmenu();
	    printf("\t\t\t\t\t输入选项:");
	    scanf("%d",&m);
	    system("cls");
	    switch(m)
            {
			    case 1:Creat();
					   Output();
				printf("-----------------------------------------------------------------------------------------------------------\n");
                      break;
                case 2:idfind();
                printf("-----------------------------------------------------------------------------------------------------------\n");
                      break;
                case 3:delect();
                printf("----------------------------------------------------------------------------------------------------------\n");
                      break;
                case 4:add();
                printf("----------------------------------------------------------------------------------------------------------\n");
                      break;
                case 5:modify();
                printf("-----------------------------------------------------------------------------------------------------------\n");
                      break;
                case 6:Output();
                printf("-----------------------------------------------------------------------------------------------------------\n");
                      break;
                case 7:totalfind();
                printf("-----------------------------------------------------------------------------------------------------------\n");
                      break;
                case 0:login();
                printf("-----------------------------------------------------------------------------------------------------------\n");
                      break;
                
            }
		}
}
 void person()
{
    system("cls");
	int m;
	personmenu();
	Linklist p;
	L=readfile();
	p=p->next; 
	while(1)
	{
	    printf("请输入选项 :");
		scanf("%d",&m);
		switch(m)
		{
		    
			case 1:personinformation();
			       printf("-----------------------------------------------------------------------------------------------------------\n");
	               break;
	        case 2:personmodify();
			       printf("-----------------------------------------------------------------------------------------------------------\n");
	               break;
			case 0:login();
	               printf("-----------------------------------------------------------------------------------------------------------\n");
	               break;
			default :exit(0) ;
		}
	}
	
}
Linklist Creat()
{
	char a[20],b[20],c[20],d[20],e[20];
	double x,y,z;
	int m,n,p,q;
	L=(Linklist)malloc(sizeof(Node));
	L->next=NULL;
	r=L;
	while(1)
	{
	printf("请输入店铺编号，店铺名称，店铺地址，部门经理\n");
	scanf("%s%s%s%s%s",a,b,c,d,e);
	printf("请输入店铺占地面积，利润,物业，租赁日期，租赁时间,\n"); 
	scanf("%lf%lf%lf%d%d%d%d",&x,&y,&z,&m,&n,&p,&q);
		if(strcmp(a,"0")>0||strcmp(a,"0")<0)
		{
			s=(Node*)malloc(sizeof(Node));
			strcpy(s->id,a);
			strcpy(s->name,b);
			strcpy(s->passward,c);
			strcpy(s->type,d);
		    strcpy(s->manager,e);
			s->area=x;
			s->profit=y;
			s->wuye=z;
			s->time.year=m;
			s->time.month=n;
			s->time.day=p;
			s->time.rent=q;
			r->next=s;
			r=s;
		}
		else
		{
			r->next=NULL;
			break;
		}
	}
	savefile();
	printf("保存成功\n");
}
void Output()
{
	Node *q;
    q=L->next;
    printf("编号\t名称\t类型\t管理员\t面积\t\t利润\t\t物业费\t\t租赁日期\t租赁时间\t\n");
    printf("===============================================================================================================================================================\n");
	while(q)
	{
		printf("%s\t%s\t%s\t%s\t%lf\t%lf\t%lf\t%d年%d月%d日\t%d\n",q->id,q->name,q->type,q->manager,q->area,q->profit,q->wuye,q->time.year,q->time.month,q->time.day,q->time.rent);
		q=q->next;
	}
}

Linklist idfind()
{        
	Node *q;
    char t[20];
    int flag=0;
	q=L->next; 
	system("color 83"); 
	printf("请输入你想查找的店铺的编号:");
	scanf("%s",t);  
	while(q)
    {
    if(strcmp(q->id,t)==0) 
		{
		printf("%s\t%s\t%s\t%s\t%s\t%lf\t%lf\t%lf\t%d年%d月%d日\t%d\n",q->id,q->name,q->passward,q->type,q->manager,q->area,q->profit,q->wuye,q->time.year,q->time.month,q->time.day,q->time.rent);
		flag=1;
        }
    q=q->next;
    }
	if(flag==0) 
    savefile();
}
Linklist managerfind()
{
	Node *q,*p;
    char t[20];
    int flag=0;
    double sum=0;
	q=L->next;
	p=L->next;  
	printf("请输入你想查找的管理员的名字:");
	scanf("%s",t);  
	while(q)
    {
    if(strcmp(q->manager,t)==0) 
		{
		printf("%s\t%s\t%s\t%s\t%s\t%lf\t%lf\t%lf\t%d年%d月%d日\t%d\n",q->id,q->name,q->passward,q->type,q->manager,q->area,q->profit,q->wuye,q->time.year,q->time.month,q->time.day,q->time.rent);
		flag=1;
		sum=sum+q->wuye;
        }
    q=q->next;
    }
	if(flag==0) 
    printf("没有该管理员\n");
    if(flag==1)
    {
    printf("管理员%s管理的总物业费为:\n",t);
    printf("%lf\n",sum);
    }
}
Linklist delect()
{
	Node *q,*m;
	char t[20];
	int flag=0;
	printf("请输入你想删除的店铺的编号：");
	scanf("%s",t);  
	q=L->next; 
	if(strcmp(q->id,t)==0)
		{ 
			r=q;
			L->next=q->next;
			free(r);
			flag=1;
			Output();
		}   
	while(q->next)
	{
		if(strcmp(q->next->id,t)==0)
		{
			r=q->next;
			q->next=q->next->next;
			free(r);
			flag=1;
			Output();
			break;
		}
		else
		{
	    q=q->next;
	    } 
	}
	if(flag==0) 
	printf("很抱歉，没有该店铺");  
	savefile();
}
Linklist add()
{
	Node *q,*p;
	q=L->next;
	while(q->next)
	{
	q=q->next;
	}
	p=(Node*)malloc(sizeof(Node));
    printf("请输入店铺编号，店铺名称，店铺密码，店铺地址，管理员\n");
    scanf("%s%s%s%s%s",p->id,p->name,p->passward,p->type,p->manager);
    printf("请输入店铺占地面积，利润,租赁日期，租赁时间,\n"); 
    scanf("%lf%lf%lf%d%d%d%d",&p->area,&p->profit,&p->wuye,&p->time.year,&p->time.month,&p->time.day,&p->time.rent);
    q->next=p;
    p->next=NULL;
    savefile();
    Output();
}
Linklist modify()
{
	Node *q; 
	q=L->next;
	char t[20];
	int n;
	printf("请输入要修改店铺的编号");
    scanf("%s",t);
    while(q)
    {
    	if(strcmp(q->id,t)==0)
    	{    
	        printf("请输入你需要修改的项目:\n");
	    	printf("1.编号\t\t2.名称\t\t3.管理员\t\t4.利润\n");
			printf("5.物业费\t6.租赁时间\t7.租赁日期\t\t0.退出\n"); 
	    	scanf("%d",&n);
	    	if(n==1)
	    	{
	    		printf("请输入新的编号：");
	    		scanf("%s",q->id);
	    	}
	    	if(n==2)
	    	{
	    		printf("请输入新的名字：");
	    		scanf("%s",q->name);
	    	}
	    	if(n==3)
	    	{
	    		printf("请输入新的管理员：");
	    		scanf("%s",q->manager);
	    	}
	    	if(n==4)
	    	{
	    		printf("请输入新的利润：");
	    		scanf("%lf",&q->profit);
	    	}
	    	 if(n==5)
	    	{
	    		printf("请输入新的物业费：");
	    		scanf("%lf",&q->wuye);
	    	}
	    	 if(n==6)
	    	{
	    		printf("请输入新的租赁日期：");
	    		scanf("%d%d%d",q->time.year,q->time.month,q->time.day);
	    	}
	    	if(n==7)
	    	{
	    		printf("请输入新的租赁时间：");
	    	}
	    	if(n==0)
	    	exit(0);
	    	printf("修改后的信息为:\n");
            printf("%s\t%s\t%s\t%s\t%lf\t%lf\t%lf\t%d年%d月%d日\t%d\n",q->id,q->name,q->type,q->manager,q->area,q->profit,q->wuye,q->time.year,q->time.month,q->time.day,q->time.rent);
	        }
		    q=q->next; 
        } 
		savefile(); 
}
void personinformation()
{
	Node *p;
	p=L->next;
	while(p)
		{
			if(strcmp(ma,p->id)==0)
			printf("%s\t%s\t%s\t%s\t%lf\t%lf\t%lf\t%d年%d月%d日\t%d\n",p->id,p->name,p->type,p->manager,p->area,p->profit,p->wuye,p->time.year,p->time.month,p->time.day,p->time.rent);
			p=p->next;
		}
} 
void personmodify()
{
	Node *p;
	int a,b;
	p=L->next;
	while(p)
		{
			if(strcmp(ma,p->id)==0)
			{
				printf("您的信息为：\n");
				printf("%s\t%s\t%s\t%s\t%lf\t%lf\t%lf\t%d年%d月%d日\t%d\n",p->id,p->name,p->type,p->manager,p->area,p->profit,p->wuye,p->time.year,p->time.month,p->time.day,p->time.rent);
				printf("你想修改以下哪些信息：\n");
				printf("1.店铺名称  2.修改密码  3.退出修改\n");
				scanf("%d",&a);
				if(a==1)
				{
		    		printf("请输入新的名字：");
		    		scanf("%s",p->name);
		
		    	}
				if(a==2)
				{
		    		printf("请输入新的密码：");
		    		scanf("%s",p->passward);
		    		printf("修改成功");
		    	}
		    	if(a==3)
		    	{
		    	person();
		    	} 
		    		
	    	}
		p=p->next;
		}
savefile();
}

void savefile()
{
	FILE *fp;
	fp=fopen("shop.txt","wt");
	for(s=L->next;s;s=s->next)
	{
	fprintf(fp,"%s %s %s %s %s ",s->id,s->name,s->passward,s->type,s->manager);
	fprintf(fp,"%lf %lf %lf %d %d %d %d\n",s->area,s->profit,s->wuye,s->time.year,s->time.month,s->time.day,s->time.rent);
    }
	fclose(fp); 
}
void adminmenu()
{
		printf("\t\t\t\t|              欢迎进入店铺管理系统                |\n");
	printf("\t\t\t==============================================================\n");
	printf("\t\t\t\t\t\t1.*输入店铺信息*\t\t\t\t\t\t\t\n"); 
	printf("\t\t\t\t\t\t2.*查询店铺信息*\t\t\t\t\t\t\t\n"); 
	printf("\t\t\t\t\t\t3.*删除店铺信息*\t\t\t\t\t\t\t\n");
	printf("\t\t\t\t\t\t4.*增添店铺信息*\t\t\t\t\t\t\t\n");
	printf("\t\t\t\t\t\t5.*修改店铺信息*\t\t\t\t\t\t\t\n"); 
	printf("\t\t\t\t\t\t6.*输出店铺信息*\t\t\t\t\t\t\t\n");
	printf("\t\t\t\t\t\t7.*查看商场信息*\t\t\t\t\t\t\t\n");
	printf("\t\t\t\t\t\t8.*返回上一级  *\t\t\t\t\t\t\t\n");
}
void personmenu()
{
	printf("\t\t\t\t|              欢迎进入店铺管理系统                |\n");
	printf("\t\t\t============================================================\n");
	printf("\t\t\t\t\t\t1.*查询信息*\t\t\t\t\t\t\t\n"); 
	printf("\t\t\t\t\t\t2.*修改信息*\t\t\t\t\t\t\t\n"); 
	printf("\t\t\t\t\t\t0.*返回上一级*\t\t\t\t\t\t\n");
}
void totalmenu()
{
	printf("\t\t\t\t|              欢迎进入店铺管理系统                |\n");
	printf("\t\t\t=============================================================\n");
	printf("\t\t\t\t\t\t1.*查看各楼层信息*\t\t\t\t\t\t\t\n");
    printf("\t\t\t\t\t\t2.*查看店铺利润排名*\t\t\t\t\t\t\t\n");
	printf("\t\t\t\t\t\t3.*查看商场总收入情况*\t\t\t\t\t\t\t\n"); 
	printf("\t\t\t\t\t\t3.*返回上一级*\t\t\t\t\t\t\t\n"); 
}
void totalfind()
{
	int m;
	while(1)
	{ 
        totalmenu();
		printf("请输入选项：");
		scanf("%d",&m);
		switch(m)
		{
			 case 1:system("cls");
			 		managerfind();
			 		printf("-----------------------------------------------------------------------------------------------------------\n");
					break;
			 case 2:system("cls");
			 		sort();
			 		printf("-----------------------------------------------------------------------------------------------------------\n");
             		break;
			 case 3:system("cls");
			 		plus();
			 		printf("-----------------------------------------------------------------------------------------------------------\n");
             case 0:admin();
			  printf("-----------------------------------------------------------------------------------------------------------\n");
                      break;
		}
    }
}
Linklist readfile()
{
	FILE *fp;
	Node *s,*r;
	fp=fopen("shop.txt","a+");
	fclose(fp);
	if((fp=fopen("shop.txt","rt"))==NULL)
	printf("没有文件");
	L=(Linklist)malloc(sizeof(Node));
	L->next=NULL;	
	r=L;
	while(!feof(fp))
	{
		s=(Node *)malloc(sizeof(Node));
		fscanf(fp,"%s %s %s %s %s ",s->id,s->name,s->passward,s->type,s->manager);
	    fscanf(fp,"%lf %lf %lf %d %d %d %d\n",&s->area,&s->profit,&s->wuye,&s->time.year,&s->time.month,&s->time.day,&s->time.rent);
		r->next=s;
		r=s;
	} 
	r->next=NULL;
	fclose(fp);
	return L;
}
void plus()
{
Node *p;
p=L->next; 
int i;
double sumw[4]={0,0,0,0},sump[4]={0,0,0,0};
while(p)
{
		if(strcmp(p->type,"food")==0)
		{
		sumw[0]=sumw[0]+p->wuye;
		sump[0]=sump[0]+p->profit;
	    }
		if(strcmp(p->type,"daily")==0)
		{
		sumw[1]=sumw[1]+p->wuye;
		sump[1]=sump[1]+p->profit;
	    }
		if(strcmp(p->type,"elec")==0)
		{
		sumw[2]=sumw[2]+p->wuye;
		sump[2]=sump[2]+p->profit;
	    }
		if(strcmp(p->type,"cloth")==0)
		{
		sumw[3]=sumw[3]+p->wuye; 
		sump[3]=sump[3]+p->profit;
	    }
	    p=p->next;
	}
	printf("food类的物业总费为：%lf\t\t利润总费为：%lf\n",sumw[0],sump[0]); 
	printf("daily类的物业总费为：%lf\t\t利润总费为：%lf\n",sumw[1],sump[1]);
	printf("elec类的物业总费为：%lf\t\t利润总费为：%lf\n",sumw[2],sump[2]);
	printf("cloth类的物业总费为：%lf\t\t利润总费为：%lf\n",sumw[3],sump[3]);
}

void mainmenu()
{
system("color 80");
printf("\t\t\t\t\t\t欢迎进入店铺管理系统\t\t\t\t\n");
printf(" \t ========================================================================================================");
printf("\n");
printf("\t\t\t\t\t\t|*管理员登录*|\t\t\t\n");
printf("\n");
printf("\n");
printf("\t\t\t\t\t\t|*个体户登录*|\t\t\t\n");
printf("\n");
printf("\n");
printf("\t\t\t\t\t\t|*注册*      |\t\t\t\n");

}

void adminlogin()
{
	char a[20],b[20];
	char c[20],d[20];
	int i; 
    FILE *fp; 
	printf("请输入用户名:"); 
	scanf("%s",a);
	printf("请输入密码:");
	scanf("%s",b);
	fp=fopen("guanli.txt","rt");
	if(fp==NULL)
	printf("没有此文件，无法打开");
	fscanf(fp,"%s %s",c,d);
	fclose(fp);
	if(strcmp(a,c)==0&&strcmp(b,d)==0)
	{
		printf("正在登录中\n");
				for(i=1;i<6;i++)
				{
					printf(".");
					Sleep(100);
				}
		admin();
	}
	else
	{
		printf("账号或密码错误,请重新输入");
	} 
}

void sort()
{
	Node *q,*p,*l;
	int i,j,n=0;
	for(q=L->next;q;q=q->next)
	n++;//统计链表的个数
    for(i=1;i<=n;i++)
	{
	  l=L;
		for(j=1;j<n-i;j++)
		{
			p=l->next;
			q=p->next;
			if(p->profit<q->profit)
			{
				l->next=q;
				p->next=q->next;
			    q->next=p; 
			}
			l=l->next;
		} 
	}
	Output();
} 
void print()
{
	printf("\t\t\t\t)
}




