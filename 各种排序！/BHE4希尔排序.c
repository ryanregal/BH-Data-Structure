#include <stdio.h>

int main(void)
{
	int a[8]={1,4,6,8,5,7,3,2};
	void shellsort(int *a);
	shellsort(a);
	return 0;
}


void shellsort(int *a)
{
	int count,temp,i,j,k,t;
	
	t=count=8/2;//���
	while(count!=1)//�ڼ������1֮ǰִ�а�����������㷨
	{
		while(t<8)//��ֹ�±�Խ��~ 
		{
			//����ż���½Ǳ꼯�ϵ����� 
			if(*(a+t)>*(a+t*2))
			{
				temp=*(a+t);
				*(a+t)=*(a+t*2);
				*(a+t+2)=temp; 
			}
			
			//���������½Ǳ꼯�ϵ�����
			if(*(a+1+t)>*(a+1+t*2)) 
			{
				temp=*(a+t+1);
				*(a+t+1)=*(a+1+t*2);
				*(a+1+t*2)=temp;
			}	
			t+=t;//�����½Ǳ��ƶ� 
		} 
		count/=2;//�������,��ʼ�µ�һ��~ 
		t=count; 
	}
	
	//���Ϊ1ʱִ��ȫ���������������tΪint����Ϊ1/2���ʼ��Ϊ1���������
	//�Ƚ�ǰ��������Ԫ�ؽ������� 
	if(*(a+0)>*(a+1))
	{
		temp=*(a+0);
		*(a+0)=*(a+1);
		*(a+1)=temp;
	}
	
	//��ʣ��Ԫ�ؽ��в��� 
	for(i=2;i<8;i++)
	{
		for(j=0;j<i;j++)
		{
			if(*(a+i)<*(a+j))
			{
				temp=*(a+i);//��Ҫ�����ֵ����temp
				
				for(k=i;k>j;k--)//�ڳ�Ҫ�����λ�� 
				{
					*(a+k)=*(a+k-1); 
				}
				
				*(a+j)=temp;//���� 
			}
		}
	}
	
	printf("�������~˳��Ϊ��\n");
	for(i=0;i<8;i++)
	{
		printf("%d",*(a+i));
	} 
} 
