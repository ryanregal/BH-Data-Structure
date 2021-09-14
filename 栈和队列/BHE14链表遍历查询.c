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
	
	//�����һ�����
	head=(Ptr)malloc(sizeof(Node));
	if(head==NULL)
	{
		printf("wrong!");
		return NULL; 
	}
	
	last=head;
	scanf("%d",&num);
	
	//���û�����0֮ǰѭ��������㲢���н��֮������Ӻͽ�㸳ֵ
	
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
	
	//�������ڶ�������nextָ�븳ֵ��NULL��Ϊ�ͷŵ����һ�������׼��
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
	printf("������Ҫ��ѯ�ĳɼ�");
	scanf("%d",&num);
	
	//�������� 
	while(head!=NULL)
	{
		if(head->grade==num)
		{
			printf("�ҵ��óɼ���λ�ڵ�%d�����\n",i);
			flag++;
		}
		
		previous=head;
		head=head->next;
		i++; 
		free(previous); //����ҵ�������ֱ���˳����򣬸ý���������н�㶼��û�б��ͷţ� 
    }
    if (flag==0)
    {
    	printf("δ�ҵ���"); 
	}
}
 
