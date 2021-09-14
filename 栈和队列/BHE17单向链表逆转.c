#include<stdio.h>
#include<stdlib.h>
//要用到malloc()和free()

//定义一个叫student的结构体，结构体最后有分号 
struct student
{
	int grade;
	struct student *next;
}; 

typedef struct student Node;
typedef Node*Ptr;
//Ptr为student型结构体指针

int main(void)
{
	Ptr CreatLinklist();
	Ptr head;
	void Invert(Ptr head); 
	head=CreatLinklist();
	printf("逆序输出为：\n");
	Invert(head); 
	return 0; 
}

Ptr CreatLinklist()
{
	Ptr head,previous,last;//定义三个结构体类型指针
	head=(Ptr)malloc(sizeof(Node));//申请第一个结点的空间
	
	if (head==NULL)
	{
		return NULL;
	} 
	
	scanf("%d",&head->grade);//head->grade:head结构体grade部分
	previous=head;
	
	while(1)
	{
		//last指针指向当前链表最后一个节点，所以每次都用last指针申请新节点的空间 
		last=(Ptr)malloc(sizeof(Node));	
		if(last==NULL)
		{
			return NULL;	
		}
	
		//结点连接,将last结点地址赋值给上一个结点的next指针 
		previous->next=last;
		
		//给last的数值域赋值 
		scanf("%d",&last->grade);
		
		//如果录入0，则释放掉这个结点的空间，将previous指针赋值NULL,跳出循环 
		if(last->grade==0)
		{
			free(last);
			previous->next=NULL; 
			break;
		}
		
		//如果录入非0，previous指针获得当前结点地址，last指针继续申请下一个结点空间
		previous=last; 
	} 
	return head;
}

void Invert(Ptr head)
{
	Ptr previous,last;
	last=NULL;
	
	while(head!=NULL)
	{
		previous=head;
		head=head->next;
		previous->next=last;
		last=previous;
	}
	
	head=previous;
	while(head!=NULL)
	{
		printf("%d\n",head->grade);
		previous=head;
		head=head->next;
		free(previous);//最后把0数值结点释放掉 
	}
}
