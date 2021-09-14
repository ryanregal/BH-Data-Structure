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
	void Show(Ptr head);
	Ptr head;
	head=CreatLinklist();
	Show(head);
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

void Show(Ptr head)
{
	int i;
	Ptr previous;
	for(i=0;head!=NULL;i++)
	//��β����Ϊ�����ͷ���ʱ��headָ��ָ��head->nextָ��ָ������ݣ���ø�ֵNULL������ѭ���� 
	{
		printf("��%d��ѧ���ĳɼ�Ϊ��%d\n",i+1,head->grade);
		previous=head;
		//�������Ľ���ַ��ֵ��previousָ�룬׼���ͷŸÿռ䡣
		head=head->next;
		//ͷָ��ָ����һ��㣬��һ����Ϊ��һ�ڵ�
		free(previous);
		//�ͷ��Ѿ���������ݵĽ�� 
	}
} 
