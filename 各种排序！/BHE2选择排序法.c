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
	int flag,i,temp;
	flag=0;//��Ϊ��¼��ǰ���������Ԫ���½Ǳ�ı�ǩ
	
	//����δ��������Ԫ�أ�ѭ������ 
	while(flag<6)
	{
		for(i=flag;i<6;i++)
		{
			//�����ǰҪ����Ԫ�ص�ֵ�Ⱥ��������Ԫ�ش󣬻���λ��
			if(*(a+flag)>*(a+i))
			{
				temp=*(a+flag);
				*(a+flag)=*(a+i);
				*(a+i)=temp; 
			}
		}
		flag++; 
	}
	
	printf("������ɣ�˳��Ϊ��\n");
	for(i=0;i<6;i++)
	{
		printf("%d",*(a+i));
	} 	
} 
