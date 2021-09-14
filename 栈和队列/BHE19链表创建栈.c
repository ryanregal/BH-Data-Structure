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

//�����ܹ�ʵ��ջ�ṹ������
Ptr CreatSteak()
{
	Ptr top,previous,last;
	int num;
	
	//����ջ�׽��Ŀռ䣬ʧ�����˳� 
	top=(Ptr)malloc(sizeof(Node));
	if(top==NULL)
	{
		printf("wrong!");
		return NULL;
	}
	
	last=top;
	//��ջ�׽���nextָ�븳ֵ��NULL
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
		//topָ��ָ������һ���ѱ���ֵ��㣬������Ϊջ����� 
		top=previous; 
		
		previous=last;
		scanf("%d",&num); 
	}
	//�ͷŶ���Ĵ��0ֵ��� 
	//��num=0ʱ��ǰһ��whileѭ���Ѿ�������һ��num��last=previous��ָ��һ�����ý�㣬�轫�ý���ͷ�~ 
	free(previous);
	return top; 
}

void Show(Ptr top)
{
	Ptr previous;
	printf("ջ������λ��\n");
	while(top!=NULL)
	{
		printf("%d\n",top->grade);
		previous=top;
		top=top->next;
		free(previous);
	}
} 
