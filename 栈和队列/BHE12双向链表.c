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
	
	//�����һ���ڵ�ռ䣬���ʧ�����˳�
	head=(Ptr)malloc(sizeof(Node));
	if (head==NULL)
	{
		printf("wrong!");
		return NULL;
	}
	
	head->back=NULL;//��һ���ڵ��backָ�븳ֵNULL
	previous=head;
	scanf("%d",&num);//��ȡ�û���һ������ĳɼ� 
	
	while(num!=0)//�ڳɼ���Ϊ0ʱѭ��������㼰����˫������ 
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
	
	//�Ƚ�previousָ��ָ�����ڶ������ 
	previous=previous->back;
	previous->next=NULL;//�������ڶ������nextָ����ΪNULL
	free(last);
	return head; 
}

Ptr Show1(Ptr head)
{
	Ptr previous;
	printf("�������룺\n");
	
	while(head!=NULL)
	{
		printf("%d\n",head->grade);
		previous=head;
		head=head->next;
	}
	
	// ��ʱpreviousָ��ָ�����һ���ڵ㣬headָ��NULL������Ӧ�÷���previousָ��洢�ĵ�ַ
	return previous; 
}

void Show2(Ptr head)
{
	Ptr previous;
	printf("�������\n");
	
	while(head!=NULL)
	{
		printf("%d\n",head->grade);
		previous=head;
		head=head->back;
		free(previous);//�ͷ��Ѿ�����Ľ�� 
	}
} 









