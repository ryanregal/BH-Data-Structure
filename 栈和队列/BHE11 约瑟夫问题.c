#include <stdio.h>
#include <stdlib.h>

//������Ϊ���Ľṹ�� 
struct man 
{
	int num;
	int password;
	struct man *next;
};

typedef struct man Node;//�������
typedef Node* Ptr;

int main(void)
{
	int num;
	Ptr head;
	Ptr CreatJosephus(int num);
	void Show(Ptr head,int num);
	
	printf("������������");
	scanf("%d",&num);
	
	//ʹ��CreatJosephus������������ѭ���б�������ֵ����headָ��
	
	head=CreatJosephus(num);
	Show(head,num);//ʹ��Show���������������
	return 0;
	
 } 
 
 
Ptr CreatJosephus(int num)
{
	Ptr head,previous,last;
	int i;
	
	//�����һ�����ռ䣬ʧ�����˳�
	
	head=(Ptr)malloc(sizeof(Node));
	
	if (head==NULL)
	{
		printf("wrong!");
		return NULL;
	}
	
	last=head;
	
	//����������㲢��ֵ
	for (i=0;i<num;i++)
	{
		previous =last; 
		printf("�������%d���˵����룺",i+1);
		scanf("%d",&previous->password);
		previous->num=i+1;
		last=(Ptr)malloc(sizeof(Node));
	
	
	if (last==NULL)
	{
		printf("wrong!");
		return NULL;
	}
	
	//����һ�����ĵ�ַ��ֵ��β�ڵ�nextָ���Թ���ѭ������
	previous->next=last;
	
    }
    
    previous->next=head;
	free(last);
	last=previous;
	return last;
	//���ص�һ�����ĵ�ַ
}

void Show(Ptr head,int num)
{
	int i,j,num1;
	Ptr previous,last;
	
	last=head->next;
	printf("�������һ��Ҫ������:");
	scanf("%d",&num1);
	printf("����˳��Ϊ��\n");
	
	//�ܹ�Ҫ���num���ˣ�ÿ���һ��i�Լ�1
	for(i=num;i>0;i--)
	{
		//���������൱�����ڱ������ڱ���1ǰһֱѭ��
		{
			for(j=num1;j>1;j--)
			{
				previous=last;
				last=last->next;
			}
			
			previous->next=last->next;
			//����1ʱ���������ǰһ�����nextָ��ָ��������ĺ�һ����� 
			printf("%d\n",last->num);
			num1=last->password;
			free(last);
			
			//lastָ���ͷŽ�����һ������Ա��������
			last =previous->next; 
		}
	}
}
