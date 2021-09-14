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
	Ptr CreatLinkList();
	Ptr Show1(Ptr head);
	void Show2(Ptr head);
	
	head=CreatLinkList();
	head=Show1(head);
	Show2(head);
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

Ptr Show1(Ptr head)
{
	Ptr previous;
	printf("正向输入：\n");
	
	while(head!=NULL)
	{
		printf("%d\n",head->grade);
		previous=head;
		head=head->next;
	}
	
	// 此时previous指针指向最后一个节点，head指向NULL，所以应该返回previous指针存储的地址
	return previous; 
}

void Show2(Ptr head)
{
	Ptr previous;
	printf("反向输出\n");
	
	while(head!=NULL)
	{
		printf("%d\n",head->grade);
		previous=head;
		head=head->back;
		free(previous);//释放已经输出的结点 
	}
} 









