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
	printf("������Ҫִ�еĲ�����\n1������\n2��ɾ��\n"); 
	
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

void Insert(Ptr head)
{
	Ptr previous,last,temp;
	int num,num1,i;
	last=head;
	
	//����Ҫ����Ľ��ռ䣬ʧ�����˳�
	temp=(Ptr)malloc(sizeof(Node));
	if(temp==NULL)
	{
		printf("wrong!");
		return;
	}
	
	printf("������Ҫ����ĳɼ���");
	scanf("%d",&num);
	printf("������Ҫ�����λ�ã�");
	scanf("%d",&num1);
	
	temp->grade=num;
	
	//��������λ��Ϊ1������һ������λ�ã���headָ��ָ���½�㣬��������Ӧָ�� 
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
		
		//�������λ�ò���β��㣬ִ��������� 
		if(last!=NULL)
		{
			last->back=temp; 
		}
		temp->next=last;
	}
	printf("����ɹ���˳�����Ϊ��");
	
	//��Ϊ���滹Ҫ�����������Ҫ�õ���Щ��㣬����˳�����ʱ���ͷŽ��ռ� 
	while(head!=NULL)
	{
		printf("%d\n",head->grade);
		previous=head;
		head=head->next; 
	} 
	
	printf("�������Ϊ��\n:");
	head=previous;
	while(head!=NULL)
	{
		printf("%d\n",head->grade);
		previous=head;
		head=head->back;
		free(previous);//�ͷŽ��ռ� 
	}  
}

void Delete(Ptr head)
{
	Ptr previous,last;
	int num;
	last=head;
	previous=NULL;
	
	printf("������Ҫɾ���ĳɼ���");
	scanf("%d",&num);
	while(last->grade!=num)
	{
		previous=last;
		last=last->next;
	} 
	
	//���ɾ�����ǵ�һ�����
	if(previous==NULL)
	{
		head=head->next;
		head->back=NULL;
		free(last);
	}
	
	//���ɾ������������㣬����������ִ��
	else
	{
		previous->next=last->next;
		//�����ɾ���Ĳ���β��� 
		if(last->next!=NULL)
		{
			last->next->back=previous; 
		}
		
		free(last); 
	}
	printf("ɾ���ɹ�����ǰ�ɼ�˳�����Ϊ��\n");
	//���ں���ĵ����������˳�����ʱ���ͷŽ��ռ�
	
	while(head!=NULL)
	{
		printf("%d\n",head->grade);
		previous=head;
		head=head->next;
	}
	
	printf("�������Ϊ��\n");
	//ִ�����ϸ�ѭ����head�Ѿ�ָ��NULL��Ϊ���ܵ��������Ҫ�Ƚ���ָ�����һ����� 
	head=previous;
	while(head!=NULL)
	{
		printf("%d\n",head->grade);
		previous=head;
		head=head->back;
		free(previous);
	 } 
} 





