#define MAX 10
#include<stdio.h>

int main(void)
{
	int queue[MAX];
	int *head,*end;//�����ͷָ���βָ�� 
	int size;//������¼�����п�ʹ�ÿռ�����ı��� 
	int Requeue(int *head,int *end,int *queue,int size);
	int Dequeue(int *head,int *end,int *queue,int size);
	head=(queue+0);
	end=(queue+0);
	size=MAX;
	size=Requeue(head,end,queue,size);
	size=Dequeue(head,end,queue,size);
}


//������ݵ���β�ĺ��� 
int Requeue(int *head,int *end,int *queue,int size)
{
	int i,num;
	printf("������Ҫ����е����ݸ�����");
	scanf("%d",&num);
	
	//���������ʣ��ռ��㹻��������ݣ�ִ�д˲��� 
	if(num<=size) 
	{
		for(i=0;i<num;i++)
		{
			//��ֹ�½Ǳ�Խ�磬�����ҪԽ�磬����ѭ����������ָ��ָ�������׵�ַ 
			if(end==(queue+MAX))
			{
				end=(queue+0);
			}
			printf("��������ӵĵ�%d�����ݣ�",i+1);
			scanf("%d",end); 
			end++; //endָ��ָ����һ���ռ�
			size--;//ʣ����ÿռ�-1 
		}
	}
	else
	{
		printf("�������г��ȣ�");
	}
	//�������µĿ��ÿռ���Ϣ 
	return size;
}

//ɾ���������ݵĺ��� 
int Dequeue(int *head,int *end,int *queue,int size)
{
	int num,i,s;
	printf("������Ҫ���е����ݸ�����");
	scanf("%d",&num);
	
	//��������������㹻���Ҫ��ĸ��� 
	if (num<=MAX-size) 
	{
		for(i=0;i<num;i++)
		{
			printf("����%d�ѳ���\n",*head);
			head++;
			size++;
			
			//��ֹ�½Ǳ�Խ�磬�����ҪԽ�磬����ѭ��������ָ��ָ�������׵�ַ 
			if(head==(queue+MAX))
			{
				head=(queue+0);
			}
		} 
	}

	else
	{
		printf("������Ԫ�ظ������㣡");
		return size; 
	}
	
	//s������¼��ǰ������ʣ���Ԫ�ظ��� 
	s=MAX-size;
	
	//�������ʣ�����ݣ����ʣ��������Ϣ 
	if(s!=0)
	{
		printf("���гɹ�����ǰ����ʣ��Ԫ������Ϊ��\n");
		while(s>0)
		{
			printf("%d",*head);
			head++;
			if(head==(queue+MAX))
			{
				head=(queue+0);
			}
			s--;
		 } 
	} 
	else
	{
		printf("���ӳɹ�����ǰ����Ϊ�ն��У�"); 
	}
	return size; 
}

