#include<stdio.h>
#include<stdlib.h>

//main���� 
int main(void)
{
	int num1,num2,i,re;
	//num1����ѧ������ 
	int*p;
	int search1(int num1,int num2,int*p);
	int search2(int num1,int num2,int*p);
	
	printf("������ѧ��������");
	scanf("%d",&num1);
	
	p=(int*)malloc(num1*sizeof(int));
	// ��̬����ռ䴴������
	
	if(p==NULL)
	{
		printf("wrong");
		return -1;
	}
	
	for (i=0;i<num1;i++)
	{
		printf("��������Ϊ%d��ѧ���ɼ�",i+1);
		scanf("%d",p+i);
	}
	
	printf("��ѡ��Ҫִ�еĲ�����\n1.����Ų�ɼ�\n2.���ɼ�����\n");
	//�û�ѡ�����
	scanf("%d",&num2);
	
	if (num2==1)
	{
		printf("������Ҫ��ѯ��ѧ�����");
		scanf("%d",&num2);
		re=search1(num1,num2,p);
		
		if(re==0)//�ж��Ƿ��ҵ� 
		{
			printf("û�в��ҵ���ѧ��~\n"); 
		} 
		else 
		{
			printf("�ҵ���ѧ�����ɼ�Ϊ��%d\n",re);
		}
	}
	
	else if(num2==2)
	//ִ��search2����
	{
		printf("����������ߣ�");
		scanf("%d",&num2);
		re=search2(num1,num2,p);
		if(re==0)//�ж��Ƿ��ҵ� 
		{
			printf("û�в��ҵ���ѧ��~\n"); 
		} 
		else 
		{
			printf("�ҵ���ѧ�����ɼ�Ϊ��%d\n",re);
		}
    }
	free(p);
	//�ͷ�����ռ�ÿռ�
	return 0; 
}

//search1���������ݱ�Ų�ɼ� 
int search1(int num1,int num2,int*p)
{
	int i;
	for (i=0;i<num1;i++);
	{
		if(i==num2-1)
		{
			return *(p+i);
			//���ҵ���ţ�ֱ�ӷ��ض�Ӧ�ɼ� 
		}
	}
	return 0;
} 

//search2���������ݳɼ����� 
int search2(int num1,int num2,int*p)
{
	int i;
	for (i=0;i<num1;i++);
	{
		if(*(p+i)==num2)
		{
			return i+1;
			//���ҵ��ɼ���ֱ�ӷ��ض�Ӧѧ����� 
		}
	}
	return 0;
 } 

