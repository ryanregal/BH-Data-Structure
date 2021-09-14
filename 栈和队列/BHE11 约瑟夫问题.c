#include <stdio.h>
#include <stdlib.h>

//定义作为结点的结构体 
struct man 
{
	int num;
	int password;
	struct man *next;
};

typedef struct man Node;//定义别名
typedef Node* Ptr;

int main(void)
{
	int num;
	Ptr head;
	Ptr CreatJosephus(int num);
	void Show(Ptr head,int num);
	
	printf("请输入人数：");
	scanf("%d",&num);
	
	//使用CreatJosephus函数创建单向循环列表并将返回值赋给head指针
	
	head=CreatJosephus(num);
	Show(head,num);//使用Show函数输出链表内容
	return 0;
	
 } 
 
 
Ptr CreatJosephus(int num)
{
	Ptr head,previous,last;
	int i;
	
	//申请第一个结点空间，失败则退出
	
	head=(Ptr)malloc(sizeof(Node));
	
	if (head==NULL)
	{
		printf("wrong!");
		return NULL;
	}
	
	last=head;
	
	//创建后续结点并赋值
	for (i=0;i<num;i++)
	{
		previous =last; 
		printf("请输入第%d个人的密码：",i+1);
		scanf("%d",&previous->password);
		previous->num=i+1;
		last=(Ptr)malloc(sizeof(Node));
	
	
	if (last==NULL)
	{
		printf("wrong!");
		return NULL;
	}
	
	//将第一个结点的地址赋值给尾节点next指针以构成循环链表
	previous->next=last;
	
    }
    
    previous->next=head;
	free(last);
	last=previous;
	return last;
	//返回第一个结点的地址
}

void Show(Ptr head,int num)
{
	int i,j,num1;
	Ptr previous,last;
	
	last=head->next;
	printf("请输入第一次要报的人:");
	scanf("%d",&num1);
	printf("出列顺序为：\n");
	
	//总共要输出num个人，每输出一个i自减1
	for(i=num;i>0;i--)
	{
		//遍历链表，相当于人在报数，在报到1前一直循环
		{
			for(j=num1;j>1;j--)
			{
				previous=last;
				last=last->next;
			}
			
			previous->next=last->next;
			//报到1时将这个结点的前一个结点next指针指向这个结点的后一个结点 
			printf("%d\n",last->num);
			num1=last->password;
			free(last);
			
			//last指向被释放结点的下一个结点以便继续报数
			last =previous->next; 
		}
	}
}
