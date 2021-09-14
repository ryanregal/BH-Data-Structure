#include<stdio.h>
#include<stdlib.h>

struct Student
{
	int grade;
	struct Student *next;
	struct Student *back;
};

typedef struct Student Node;
typedef Node *Ptr;

int main(void)
{
	Ptr head;
	int num; 
	Ptr CreatLinkList();
	head=CreatLinkList();
	void Insert(Ptr head);
	void Delete(Ptr head);
	printf("请输入要执行的操作：\n1、插入\n2、删除\n"); 
	
	scanf("%d",&num);
	if(num==1)
	{
		Insert(head);
	}
	else if(num==1)
	{
		Delete(head); 
	}
	
	return 0; 
} 

Ptr CreatLinkList()
{
	Ptr head,previous,last;
	int num,i;
	
	//申请第一个节点空间，如果失败则退出
	head=(Ptr)malloc(sizeof(Node));
	if (head==NULL)
	{
		printf("wrong!");
		return NULL;
	}
	
	head->back=NULL;//第一个节点的back指针赋值NULL
	previous=head;
	scanf("%d",&num);//获取用户第一次输入的成绩 
	
	while(num!=0)//在成绩不为0时循环创建结点及连接双向链表 
	{
		previous->grade=num;
		last=(Ptr)malloc(sizeof(Node));
		
		if(last==NULL)
		{
			printf("wrong!");
			return NULL;
		}
		last->back=previous;
		previous->next=last;
		previous=last;
		scanf("%d",&num); 
	} 
	
	//先将previous指针指向倒数第二个结点 
	previous=previous->back;
	previous->next=NULL;//将倒数第二个结点next指针设为NULL
	free(last);
	return head; 
}

void Insert(Ptr head)
{
	Ptr previous,last,temp;
	int num,num1,i;
	last=head;
	
	//申请要插入的结点空间，失败则退出
	temp=(Ptr)malloc(sizeof(Node));
	if(temp==NULL)
	{
		printf("wrong!");
		return;
	}
	
	printf("请输入要插入的成绩：");
	scanf("%d",&num);
	printf("请输入要插入的位置：");
	scanf("%d",&num1);
	
	temp->grade=num;
	
	//如果插入的位置为1，即第一个结点的位置，则将head指针指向新结点，并处理相应指针 
	if(num1==1)
	{
		temp->back=NULL;
		temp->next=head;
		head->back=temp;
		head=temp;
	}
	
	else
	{
		for (i=num1;i>1;i--)
		{
			previous=last;
			last=last->next;
		}
		
		temp->back=previous;
		previous->next=temp;
		
		//如果插入位置不是尾结点，执行这个操作 
		if(last!=NULL)
		{
			last->back=temp; 
		}
		temp->next=last;
	}
	printf("插入成功！顺序输出为：");
	
	//因为后面还要倒序输出，还要用到这些结点，所以顺序输出时候不释放结点空间 
	while(head!=NULL)
	{
		printf("%d\n",head->grade);
		previous=head;
		head=head->next; 
	} 
	
	printf("倒序输出为：\n:");
	head=previous;
	while(head!=NULL)
	{
		printf("%d\n",head->grade);
		previous=head;
		head=head->back;
		free(previous);//释放结点空间 
	}  
}

void Delete(Ptr head)
{
	Ptr previous,last;
	int num;
	last=head;
	previous=NULL;
	
	printf("请输入要删除的成绩：");
	scanf("%d",&num);
	while(last->grade!=num)
	{
		previous=last;
		last=last->next;
	} 
	
	//如果删除的是第一个结点
	if(previous==NULL)
	{
		head=head->next;
		head->back=NULL;
		free(last);
	}
	
	//如果删除的是其他结点，则正常操作执行
	else
	{
		previous->next=last->next;
		//如果被删除的不是尾结点 
		if(last->next!=NULL)
		{
			last->next->back=previous; 
		}
		
		free(last); 
	}
	printf("删除成功！当前成绩顺序输出为：\n");
	//由于后面的倒序输出，故顺序输出时不释放结点空间
	
	while(head!=NULL)
	{
		printf("%d\n",head->grade);
		previous=head;
		head=head->next;
	}
	
	printf("倒序输出为：\n");
	//执行完上个循环后，head已经指向NULL，为了能倒序输出，要先将它指向最后一个结点 
	head=previous;
	while(head!=NULL)
	{
		printf("%d\n",head->grade);
		previous=head;
		head=head->back;
		free(previous);
	 } 
} 





