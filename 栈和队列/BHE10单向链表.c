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
	void Show(Ptr head);
	Ptr head;
	head=CreatLinklist();
	Show(head);
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

void Show(Ptr head)
{
	int i;
	Ptr previous;
	for(i=0;head!=NULL;i++)
	//当尾结点成为链表的头结点时，head指针指向head->next指针指向的内容，获得赋值NULL，跳出循环。 
	{
		printf("第%d个学生的成绩为：%d\n",i+1,head->grade);
		previous=head;
		//将输出后的结点地址赋值给previous指针，准备释放该空间。
		head=head->next;
		//头指针指向下一结点，下一结点称为第一节点
		free(previous);
		//释放已经输出完内容的结点 
	}
} 
