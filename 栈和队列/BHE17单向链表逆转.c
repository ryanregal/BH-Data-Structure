#include<stdio.h>
#include<stdlib.h>
//Ҫ�õ�malloc()��free()

//����һ����student�Ľṹ�壬�ṹ������зֺ� 
struct student
{
	int grade;
	struct student *next;
}; 

typedef struct student Node;
typedef Node*Ptr;
//PtrΪstudent�ͽṹ��ָ��

int main(void)
{
	Ptr CreatLinklist();
	Ptr head;
	void Invert(Ptr head); 
	head=CreatLinklist();
	printf("�������Ϊ��\n");
	Invert(head); 
	return 0; 
}

Ptr CreatLinklist()
{
	Ptr head,previous,last;//���������ṹ������ָ��
	head=(Ptr)malloc(sizeof(Node));//�����һ�����Ŀռ�
	
	if (head==NULL)
	{
		return NULL;
	} 
	
	scanf("%d",&head->grade);//head->grade:head�ṹ��grade����
	previous=head;
	
	while(1)
	{
		//lastָ��ָ��ǰ�������һ���ڵ㣬����ÿ�ζ���lastָ�������½ڵ�Ŀռ� 
		last=(Ptr)malloc(sizeof(Node));	
		if(last==NULL)
		{
			return NULL;	
		}
	
		//�������,��last����ַ��ֵ����һ������nextָ�� 
		previous->next=last;
		
		//��last����ֵ��ֵ 
		scanf("%d",&last->grade);
		
		//���¼��0�����ͷŵ�������Ŀռ䣬��previousָ�븳ֵNULL,����ѭ�� 
		if(last->grade==0)
		{
			free(last);
			previous->next=NULL; 
			break;
		}
		
		//���¼���0��previousָ���õ�ǰ����ַ��lastָ�����������һ�����ռ�
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
		free(previous);//����0��ֵ����ͷŵ� 
	}
}
