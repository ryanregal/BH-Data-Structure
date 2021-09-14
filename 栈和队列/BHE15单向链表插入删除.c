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
	printf("please input your option��\n1��insert\n2��delete");
	
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
	
	//���û�����0֮ǰѭ��������㲢���н�����Ӻͽ�㸳ֵ
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
	
	//�������ڶ�������nextָ�븳ֵ��NULL��Ϊ�ͷŵ����һ�������׼�� 
	previous->next=NULL;
	free(last);
	return head; 
}

void Insert(Ptr head)
{
	Ptr previous,last,temp;
	int num,num1,i;
	last=head;
	printf("������Ҫ����ĳɼ���");
	scanf("%d",&num);
	printf("������Ҫ�����λ�ã�");
	scanf("%d",&num1);
	
	//����Ҫ����λ�õĽ��ռ䣬���ʧ�����˳�
	temp=(Ptr)malloc(sizeof(Node));
	if(temp==NULL)
	{
		printf("wrong!");
		return;
	}
	
	temp->grade=num;
	
	//���������ڵ�һ�����֮ǰ����headָ��ָ���½�㣬���½���Ϊ��һ����� 
	if(num==1)
	{
		temp->next=head;
		head=temp; 
	}
	
	else
	{
		for(i=num1;i>1;i--)
		{
			previous=last;//�ʼ��last��head������ 
			last=last->next;
		}
		
		previous->next=temp;
		temp->next=last;
	} 
	
	printf("����ɹ�����ǰ�ɼ�Ϊ��\n");
	
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
	printf("������Ҫɾ���ĳɼ�");
	scanf("%d",&num);
	
	//ƥ������ɼ� 
	while(last->grade!=num) 
	{
		previous=last;
		last=last->next;
	}
	
	//�жϱ�ɾ�����ǲ��ǵ�һ���ڵ㣬������Ǿ�ִ������ɾ�������� 
	if (previous!=NULL)
	{
		previous->next=last->next;
		free(last);
	}
	
	//�����ɾ�����ǵ�һ����㣬��headָ��ָ��ڶ��������ͷŵ�һ�����ռ�
	{
		head=last->next;
		free(last);
	}
	
	printf("ɾ���ɹ�����ǰ�ɼ�Ϊ��\n");
	
	while(head!=NULL)//ѭ�����
	{
		printf("%d\n",head->grade);
		previous=head;
		head=head->next;
		free(previous);
	}
}
