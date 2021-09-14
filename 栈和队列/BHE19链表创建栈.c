#include <stdio.h>
#include <stdlib.h>

struct Student
{
	int grade;
	struct Student*next;
};

typedef struct Student Node;
typedef Node*Ptr;

int main(void)
{
	Ptr top;
	Ptr CreatSteak();
	top=CreatSteak();
	void Show(Ptr top);
	Show(top);
	return 0;
}

//创建能够实现栈结构的链表
Ptr CreatSteak()
{
	Ptr top,previous,last;
	int num;
	
	//申请栈底结点的空间，失败则退出 
	top=(Ptr)malloc(sizeof(Node));
	if(top==NULL)
	{
		printf("wrong!");
		return NULL;
	}
	
	last=top;
	//将栈底结点的next指针赋值给NULL
	last->next=NULL;
	
	previous=last;
	
	scanf("%d",&num);
	while(num!=0) 
	{
		previous->grade=num;
		
		last=(Ptr)malloc(sizeof(Node));
	 
		if(top==NULL)
		{
			printf("wrong!");
			return NULL;
		}
		
		last->next=previous;
		//top指针指向最新一个已被赋值结点，以其作为栈顶结点 
		top=previous; 
		
		previous=last;
		scanf("%d",&num); 
	}
	//释放多余的存放0值结点 
	//当num=0时，前一个while循环已经读入了一个num，last=previous均指向一个无用结点，需将该结点释放~ 
	free(previous);
	return top; 
}

void Show(Ptr top)
{
	Ptr previous;
	printf("栈内数据位：\n");
	while(top!=NULL)
	{
		printf("%d\n",top->grade);
		previous=top;
		top=top->next;
		free(previous);
	}
} 
