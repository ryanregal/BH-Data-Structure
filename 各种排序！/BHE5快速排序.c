//�ݹ���� 
#include<stdio.h>

int main(void)
{
	int a[8]={4,1,6,8,5,7,3,2}; 
	int count,i;
	
	void q_sort(int *a,int left,int right);
	void quick(int *a,int n);
	count=8;//������鳤��
	
	quick(a,count);//���ÿ��������� 
	
	printf("���ս����\n");
	
	for(i=0;i<8;i++)
	{
		printf("%d",*(a+i));
	}
	
	printf("\n");
	
	return 0; 
}


//��������
void quick(int *a,int n)
{
	void q_sort(int *a,int left,int right); 
	q_sort(a,0,n-1);//���÷ָ�� 
 } 
 

//�ָ�� 
//�����left��0��right��n-1 
void q_sort(int *a,int left,int right)
{
	int partition;//�ָ�Ԫ��
	int temp;
	int i,j,k; 
	
  if(left<right)//��ָ��С����ָ��������ָ� 
  { 
		i=left;//�ָ������
		j=right+1;//�ָ������
		partition=a[left];//ȡ��һ��Ԫ�� 
	
	
	do//һֱѭ��ֱ����ָ��i���ڻ������ָ��j 
	{
		do//��������(�ڶ���Ԫ�ؿ�ʼ����i=1����ֱ���ҵ�һ�����Ԫ�ش��ڵ���partition 
		{
			i++;
		}
		while(a[i]<partition);
		
		do//�ҵ��ȱ�׼ֵ��ĺ�ʼ���������� 
		{
			j--;
		}
		while(a[j]>partition); 
		
		if(i<j)//�������� 
		{
			temp=a[i];
			a[i]=a[j];
			a[j]=temp; 
		} 
	}
	while(i<j);
	
	//����ָ��i���ڵ�����ָ��j������һ��Ԫ��a[left]����ָ��Ԫ�ػ�λ
	temp=a[left];
	a[left]=a[j];
	a[j]=temp; 

	printf("������"); 
	
	//������������� 
	for(k=left;k<=right;k++)
	{
		printf("%d",a[k]);
	}
	printf("\n");
	
	q_sort(a,left,j-1);//����߽��п�������ݹ���� 
	q_sort(a,j+1,right);//���ұ߽��п�������ݹ���� 
  }
} 







 
