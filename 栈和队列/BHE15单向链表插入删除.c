#include <stdio.h>
#include <stdlib.h>

struct Student
{
	int grade;
	struct Student*next; 
};

typedef struct Student Node;
typedef Node *Ptr;

int main(void)
{
	Ptr head;
	int num;
	Ptr CreatLinklist();
	void Insert(Ptr head);
	void Delete1(Ptr head);
	head=CreatLinklist();
	printf("please input your option：\n1、insert\n2、delete");
	
	scanf("%d",&num);
	if (num==1)
	{
		Insert(head);
	}
	else if(num==2)
	{
		Delete1(head);
	}
	return 0;
}

Ptr CreatLinklist()
{
	Ptr head,previous,last;
	int num;
	
	//ask for the firt Node
	head=(Ptr)malloc(sizeof(Node));
	if (head==NULL)
	{
		printf("wrong!");
		return NULL;
	}
	
	last=head;
	scanf("%d",&num);
	
	//在用户输入0之前循环创建结点并进行结点连接和结点赋值
	while (num!=0)
	{
		previous=last;
		previous->grade=num;
		
		last=(Ptr)malloc(sizeof(Node));
		if(last==NULL)
		{
			printf("wrong!");
			return NULL;
		}
		
		previous->next=last;
		scanf("%d",&num);
	} 
	
	//将倒数第二个结点的next指针赋值给NULL，为释放掉最后一个结点做准备 
	previous->next=NULL;
	free(last);
	return head; 
}

void Insert(Ptr head)
{
	Ptr previous,last,temp;
	int num,num1,i;
	last=head;
	printf("请输入要插入的成绩：");
	scanf("%d",&num);
	printf("请输入要插入的位置：");
	scanf("%d",&num1);
	
	//申请要插入位置的结点空间，如果失败则退出
	temp=(Ptr)malloc(sizeof(Node));
	if(temp==NULL)
	{
		printf("wrong!");
		return;
	}
	
	temp->grade=num;
	
	//如果插入点在第一个结点之前，将head指针指向新结点，即新结点成为第一个结点 
	if(num==1)
	{
		temp->next=head;
		head=temp; 
	}
	
	else
	{
		for(i=num1;i>1;i--)
		{
			previous=last;//最开始的last是head！！！ 
			last=last->next;
		}
		
		previous->next=temp;
		temp->next=last;
	} 
	
	printf("插入成功！当前成绩为：\n");
	
	while(head!=NULL)
	{
		printf("%d\n",head->grade);
		previous=head;
		head=head->next;
		free(previous);
	}
}

void Delete1(Ptr head)
{
	Ptr previous,last;
	int num;
	last=head;
	previous=NULL;
	printf("请输入要删除的成绩");
	scanf("%d",&num);
	
	//匹配各结点成绩 
	while(last->grade!=num) 
	{
		previous=last;
		last=last->next;
	}
	
	//判断被删除的是不是第一个节点，如果不是就执行正常删除结点操作 
	if (previous!=NULL)
	{
		previous->next=last->next;
		free(last);
	}
	
	//如果被删除的是第一个结点，将head指针指向第二个结点后释放第一个结点空间
	{
		head=last->next;
		free(last);
	}
	
	printf("删除成功，当前成绩为：\n");
	
	while(head!=NULL)//循环输出
	{
		printf("%d\n",head->grade);
		previous=head;
		head=head->next;
		free(previous);
	}
}
