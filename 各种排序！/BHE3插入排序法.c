#include<stdio.h>

int main(void)
{
	int a[6]={1,3,5,6,4,2};
	
	void sort(int *a);
	sort(a);
	
	return 0;
}


void sort(int *a)
{
	int temp,i,j,k;
	
	//�Ƚ�ǰ��������Ԫ�ؽ������� 
	if(*(a+0)>*(a+1))
	{
		temp=*(a+0);
		*(a+0)=*(a+1);
		*(a+1)=temp; 
	}
	
	//��ʣ��Ԫ�ؽ��в��� 
	for(i=2;i<6;i++)
	{
		for(j=0;j<i;j++)
		{ 
			//�ҵ�����λ�� 
			if(*(a+i)<*(a+j))
			{
				temp=*(a+i);//��Ҫ�����ֵ��ֵ��temp
				for(k=i;k>j;k--)//�ڳ�Ҫ�����λ��
				{
					*(a+k)=*(a+k-1); 
				}
				*(a+j)=temp;//���� 
			}
		}
	}
	
	printf("�������~˳��Ϊ��\n");
	for(i=0;i<6;i++)
	{
		printf("%d",*(a+i));
	}
}
