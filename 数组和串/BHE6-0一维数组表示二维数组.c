#include<stdio.h>
int main(void)
{
	int a[3][3],b[9];
	int i,j,k,num1,num2,num3,real;
	printf("������3X3���������ݣ�\n");
	
	for (i=0;i<3;i++)//��ά���鸳ֵ
	{
		for(j=0;j<3;j++)
		{
			scanf("%d",(*(a+i)+j));	
			//(a+i)�൱��&a[i]����i�е�ַ����a[i]+j�൱��a[i]ƫ��j����λȡ����ȡֵ��&(a[i][j]) 
		}
    }
    
    printf("��ѡ��ת��������\n1.����Ϊ��\n2.����Ϊ��\n");
	scanf("%d",&num1);
	
	//����Ϊ�� 
	if(num1==1)
	{
		k=0;//��Ϊһλ������½Ǳ���ʼ
		
		for (i=0;i<3;i++)
		{
			for (j=0;j<3;j++)
			{
				*(b+k)=*(*(a+i)+j);
				//�Ѷ�ά�����ֵ����Ϊ����ֵ��һά����
				//b��һά����b[9]���׵�ַ��b+k��b[k]�ĵ�ַ��*(b+k)ȡb[k]ֵ 
				//k��ʼ0����ά�����ʼa[0][0] 
				k++;
			}
		}
		
	printf("������Ҫ��ѯ������");
	scanf("%d",&num2);
	printf("������Ҫ��ѯ������");
	scanf("%d",&num3);
	real=3*(num2-1)+num3-1;
	
	printf("��ѯ�����%d\n",*(b+real)); 
	//*(b+real)�൱��b[real] 
	} 
	
	else if(num1==2)
	{
		k==0;
		
		for (i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
				*(b+k)=*(*(a+j)+i);
				k++;
			}
		}
	
	printf("������Ҫ��ѯ������");
	scanf("%d",&num2);
	printf("������Ҫ��ѯ������");
	scanf("%d",&num3);
	real=3*(num3-1)+num2-1;
	
	printf("��ѯ�����%d\n",*(b+real)); 
	}
	
	return 0; 
 } 
