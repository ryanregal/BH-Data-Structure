#include <stdio.h>
#include <stdlib.h>

//main���� 
int main(void)
{
	int num1,num2,i,re;
	//num1����ѧ������ 
	int*p;
	int delete1(int num1,int num2,int*p);
	//Ҫ��ǰ����delete1���� 
	
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
	
printf("������Ҫɾ����ѧ����ţ�");
//�û�����
scanf("%d",&num2);
re=delete1(num1,num2,p);
num1=re;
//���µ�ǰ���鳤��
printf("ɾ���ɹ���ʣ��ѧ����ż��ɼ�Ϊ��\n");
for(i=0;i<num1;i++)
{
	printf("��%d��ѧ���ɼ�Ϊ%d\n",i+1,*(p+i));
 } 
free(p);
return 0;
}

//����delete����
//1.��������
//2.���ĳ��� 

int delete1(int num1,int num2,int*p)
{
	int i,j;
	for (i=0;i<num1;i++)
	{
		if (i==num2-1)
		{
			for(j=i;j<num1-1;j++)
			{
				*(p+j)=*(p+j+1);//�������� 
			}
			break;//��ǰ����forѭ�����Ч�� 
		}
	}
	return num1-1; 
}
