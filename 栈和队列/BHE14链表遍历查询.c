#include<stdio.h>
#include<stdlib.h>

struct Student
{
	int grade;
	struct Student*next;
};

typedef struct Student Node;
typedef struct Student* Ptr;

int main(void)
{
	Ptr head;
	Ptr CreatLinklist();
	void Search(Ptr head);
	head=CreatLinklist();
	Search(head);
	return 0;
}

Ptr CreatLinklist()
{
	Ptr head,previous,last;
	int num;
	
	//申请第一个结点
	head=(Ptr)malloc(sizeof(Node));
	if(head==NULL)
	{
		printf("wrong!");
		return NULL; 
	}
	
	last=head;
	scanf("%d",&num);
	
	//在用户输入0之前循环创建结点并进行结点之间的连接和结点赋值
	
	while(num!=0)
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
 
void Search(Ptr head)
{
	int i,num,flag;
	Ptr previous;
	i=1;
	flag=0;
	printf("请输入要查询的成绩");
	scanf("%d",&num);
	
	//遍历链表 
	while(head!=NULL)
	{
		if(head->grade==num)
		{
			printf("找到该成绩，位于第%d个结点\n",i);
			flag++;
		}
		
		previous=head;
		head=head->next;
		i++; 
		free(previous); //如果找到满足点就直接退出程序，该结点后面的所有结点都还没有被释放！ 
    }
    if (flag==0)
    {
    	printf("未找到！"); 
	}
}
 
