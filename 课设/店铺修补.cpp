struct pu 
{
	int year;
	int month;
	int day;
	int rent;
};/*���̵�����ʱ��ṹ��*/ 
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
char ma[20];//���룬���ڸ��������Ϣ 
//---------------------------��������------------------------------- 
    void admin();
	void division();
	void person();
	Linklist Creat();
	void Output();
	Linklist delect();
	Linklist idfind();
	Linklist managerfind();//����Ա���Һ��� 
	Linklist add();
	Linklist modify(); //�޸ĺ��� 
	void savefile();
	Linklist readfile();
	void mainmenu();//���˵�����¼ע��Ĳ˵� 
	void adminmenu(); //����Ա�˵� 
	void personmenu();//���廧�˵� 
	void plus();//����ҵ������� 
	void login();//�ܵ�¼���� 
    void adminlogin();// ����Ա��¼���� 
	void  personlogin();//���廧��¼���� 
	Linklist Register();//���廧ע�ắ�� 
	void totalmenu();//�鿴������Ϣ�˵� 
	void totalfind();//
	void sort();//�������� 
	void personinformation();//���廧��Ϣ��ѯ 
	void personmodify();//���廧�޸� 
//----------------------------------------------------------
#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<windows.h>//�ı���ɫ 
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
	printf("��ѡ��");
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
	printf("��������̱��:");
	scanf("%s",t);
	if(L->next==NULL)
	{
		printf("û�д˵�����Ϣ\n");
	}
	for(q=L->next;q!=NULL;q=q->next)
	{
		if(strcmp(q->id,t)==0)
		{
			printf("����������:");
			scanf("%s",passward);
			if(strcmp(q->passward,passward)==0)
			{
			//	m=1;
				strcpy(ma,q->id);
				printf("���ڵ�¼��\n");
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
				printf("\n���ٴ���������:");
				scanf("%s",passward);
				if(strcmp(q->passward,passward)==0)
				{
					m=1;
					printf("���ڵ�¼��");
					for(i=1;i<10;i++)
					{
						printf(".");
						Sleep(100);
					}
					printf("\n");
				}
				else
				{
					printf("�����������!\n");
				}
			}

		}
	}
	if(!m)
	{
		printf("û�д˵���!");
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
    printf("��������̱�ţ��������ƣ��������룬���̵�ַ������Ա\n");
    scanf("%s%s%s%s%s",p->id,p->name,p->passward,p->type,p->manager);
    printf("���������ռ�����������,�������ڣ�����ʱ��,\n"); 
    scanf("%lf%lf%lf%d%d%d%d",&p->area,&p->profit,&p->wuye,&p->time.year,&p->time.month,&p->time.day,&p->time.rent);
    q->next=p;
    p->next=NULL;
//    while(s)
//    {
//    	
//    }
    printf("ע��ɹ�"); 
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
	    printf("\t\t\t\t\t����ѡ��:");
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
	    printf("������ѡ�� :");
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
	printf("��������̱�ţ��������ƣ����̵�ַ�����ž���\n");
	scanf("%s%s%s%s%s",a,b,c,d,e);
	printf("���������ռ�����������,��ҵ���������ڣ�����ʱ��,\n"); 
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
	printf("����ɹ�\n");
}
void Output()
{
	Node *q;
    q=L->next;
    printf("���\t����\t����\t����Ա\t���\t\t����\t\t��ҵ��\t\t��������\t����ʱ��\t\n");
    printf("===============================================================================================================================================================\n");
	while(q)
	{
		printf("%s\t%s\t%s\t%s\t%lf\t%lf\t%lf\t%d��%d��%d��\t%d\n",q->id,q->name,q->type,q->manager,q->area,q->profit,q->wuye,q->time.year,q->time.month,q->time.day,q->time.rent);
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
	printf("������������ҵĵ��̵ı��:");
	scanf("%s",t);  
	while(q)
    {
    if(strcmp(q->id,t)==0) 
		{
		printf("%s\t%s\t%s\t%s\t%s\t%lf\t%lf\t%lf\t%d��%d��%d��\t%d\n",q->id,q->name,q->passward,q->type,q->manager,q->area,q->profit,q->wuye,q->time.year,q->time.month,q->time.day,q->time.rent);
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
	printf("������������ҵĹ���Ա������:");
	scanf("%s",t);  
	while(q)
    {
    if(strcmp(q->manager,t)==0) 
		{
		printf("%s\t%s\t%s\t%s\t%s\t%lf\t%lf\t%lf\t%d��%d��%d��\t%d\n",q->id,q->name,q->passward,q->type,q->manager,q->area,q->profit,q->wuye,q->time.year,q->time.month,q->time.day,q->time.rent);
		flag=1;
		sum=sum+q->wuye;
        }
    q=q->next;
    }
	if(flag==0) 
    printf("û�иù���Ա\n");
    if(flag==1)
    {
    printf("����Ա%s���������ҵ��Ϊ:\n",t);
    printf("%lf\n",sum);
    }
}
Linklist delect()
{
	Node *q,*m;
	char t[20];
	int flag=0;
	printf("����������ɾ���ĵ��̵ı�ţ�");
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
	printf("�ܱ�Ǹ��û�иõ���");  
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
    printf("��������̱�ţ��������ƣ��������룬���̵�ַ������Ա\n");
    scanf("%s%s%s%s%s",p->id,p->name,p->passward,p->type,p->manager);
    printf("���������ռ�����������,�������ڣ�����ʱ��,\n"); 
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
	printf("������Ҫ�޸ĵ��̵ı��");
    scanf("%s",t);
    while(q)
    {
    	if(strcmp(q->id,t)==0)
    	{    
	        printf("����������Ҫ�޸ĵ���Ŀ:\n");
	    	printf("1.���\t\t2.����\t\t3.����Ա\t\t4.����\n");
			printf("5.��ҵ��\t6.����ʱ��\t7.��������\t\t0.�˳�\n"); 
	    	scanf("%d",&n);
	    	if(n==1)
	    	{
	    		printf("�������µı�ţ�");
	    		scanf("%s",q->id);
	    	}
	    	if(n==2)
	    	{
	    		printf("�������µ����֣�");
	    		scanf("%s",q->name);
	    	}
	    	if(n==3)
	    	{
	    		printf("�������µĹ���Ա��");
	    		scanf("%s",q->manager);
	    	}
	    	if(n==4)
	    	{
	    		printf("�������µ�����");
	    		scanf("%lf",&q->profit);
	    	}
	    	 if(n==5)
	    	{
	    		printf("�������µ���ҵ�ѣ�");
	    		scanf("%lf",&q->wuye);
	    	}
	    	 if(n==6)
	    	{
	    		printf("�������µ��������ڣ�");
	    		scanf("%d%d%d",q->time.year,q->time.month,q->time.day);
	    	}
	    	if(n==7)
	    	{
	    		printf("�������µ�����ʱ�䣺");
	    	}
	    	if(n==0)
	    	exit(0);
	    	printf("�޸ĺ����ϢΪ:\n");
            printf("%s\t%s\t%s\t%s\t%lf\t%lf\t%lf\t%d��%d��%d��\t%d\n",q->id,q->name,q->type,q->manager,q->area,q->profit,q->wuye,q->time.year,q->time.month,q->time.day,q->time.rent);
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
			printf("%s\t%s\t%s\t%s\t%lf\t%lf\t%lf\t%d��%d��%d��\t%d\n",p->id,p->name,p->type,p->manager,p->area,p->profit,p->wuye,p->time.year,p->time.month,p->time.day,p->time.rent);
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
				printf("������ϢΪ��\n");
				printf("%s\t%s\t%s\t%s\t%lf\t%lf\t%lf\t%d��%d��%d��\t%d\n",p->id,p->name,p->type,p->manager,p->area,p->profit,p->wuye,p->time.year,p->time.month,p->time.day,p->time.rent);
				printf("�����޸�������Щ��Ϣ��\n");
				printf("1.��������  2.�޸�����  3.�˳��޸�\n");
				scanf("%d",&a);
				if(a==1)
				{
		    		printf("�������µ����֣�");
		    		scanf("%s",p->name);
		
		    	}
				if(a==2)
				{
		    		printf("�������µ����룺");
		    		scanf("%s",p->passward);
		    		printf("�޸ĳɹ�");
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
		printf("\t\t\t\t|              ��ӭ������̹���ϵͳ                |\n");
	printf("\t\t\t==============================================================\n");
	printf("\t\t\t\t\t\t1.*���������Ϣ*\t\t\t\t\t\t\t\n"); 
	printf("\t\t\t\t\t\t2.*��ѯ������Ϣ*\t\t\t\t\t\t\t\n"); 
	printf("\t\t\t\t\t\t3.*ɾ��������Ϣ*\t\t\t\t\t\t\t\n");
	printf("\t\t\t\t\t\t4.*���������Ϣ*\t\t\t\t\t\t\t\n");
	printf("\t\t\t\t\t\t5.*�޸ĵ�����Ϣ*\t\t\t\t\t\t\t\n"); 
	printf("\t\t\t\t\t\t6.*���������Ϣ*\t\t\t\t\t\t\t\n");
	printf("\t\t\t\t\t\t7.*�鿴�̳���Ϣ*\t\t\t\t\t\t\t\n");
	printf("\t\t\t\t\t\t8.*������һ��  *\t\t\t\t\t\t\t\n");
}
void personmenu()
{
	printf("\t\t\t\t|              ��ӭ������̹���ϵͳ                |\n");
	printf("\t\t\t============================================================\n");
	printf("\t\t\t\t\t\t1.*��ѯ��Ϣ*\t\t\t\t\t\t\t\n"); 
	printf("\t\t\t\t\t\t2.*�޸���Ϣ*\t\t\t\t\t\t\t\n"); 
	printf("\t\t\t\t\t\t0.*������һ��*\t\t\t\t\t\t\n");
}
void totalmenu()
{
	printf("\t\t\t\t|              ��ӭ������̹���ϵͳ                |\n");
	printf("\t\t\t=============================================================\n");
	printf("\t\t\t\t\t\t1.*�鿴��¥����Ϣ*\t\t\t\t\t\t\t\n");
    printf("\t\t\t\t\t\t2.*�鿴������������*\t\t\t\t\t\t\t\n");
	printf("\t\t\t\t\t\t3.*�鿴�̳����������*\t\t\t\t\t\t\t\n"); 
	printf("\t\t\t\t\t\t3.*������һ��*\t\t\t\t\t\t\t\n"); 
}
void totalfind()
{
	int m;
	while(1)
	{ 
        totalmenu();
		printf("������ѡ�");
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
	printf("û���ļ�");
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
	printf("food�����ҵ�ܷ�Ϊ��%lf\t\t�����ܷ�Ϊ��%lf\n",sumw[0],sump[0]); 
	printf("daily�����ҵ�ܷ�Ϊ��%lf\t\t�����ܷ�Ϊ��%lf\n",sumw[1],sump[1]);
	printf("elec�����ҵ�ܷ�Ϊ��%lf\t\t�����ܷ�Ϊ��%lf\n",sumw[2],sump[2]);
	printf("cloth�����ҵ�ܷ�Ϊ��%lf\t\t�����ܷ�Ϊ��%lf\n",sumw[3],sump[3]);
}

void mainmenu()
{
system("color 80");
printf("\t\t\t\t\t\t��ӭ������̹���ϵͳ\t\t\t\t\n");
printf(" \t ========================================================================================================");
printf("\n");
printf("\t\t\t\t\t\t|*����Ա��¼*|\t\t\t\n");
printf("\n");
printf("\n");
printf("\t\t\t\t\t\t|*���廧��¼*|\t\t\t\n");
printf("\n");
printf("\n");
printf("\t\t\t\t\t\t|*ע��*      |\t\t\t\n");

}

void adminlogin()
{
	char a[20],b[20];
	char c[20],d[20];
	int i; 
    FILE *fp; 
	printf("�������û���:"); 
	scanf("%s",a);
	printf("����������:");
	scanf("%s",b);
	fp=fopen("guanli.txt","rt");
	if(fp==NULL)
	printf("û�д��ļ����޷���");
	fscanf(fp,"%s %s",c,d);
	fclose(fp);
	if(strcmp(a,c)==0&&strcmp(b,d)==0)
	{
		printf("���ڵ�¼��\n");
				for(i=1;i<6;i++)
				{
					printf(".");
					Sleep(100);
				}
		admin();
	}
	else
	{
		printf("�˺Ż��������,����������");
	} 
}

void sort()
{
	Node *q,*p,*l;
	int i,j,n=0;
	for(q=L->next;q;q=q->next)
	n++;//ͳ������ĸ���
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




