#include <stdio.h>

int main(void)
{
	int a[6]={1,3,5,6,4,2};
	void sort(int *a);
	
	sort(a);
	return 0;
}

void sort(int *a)
{
	int i,flag,temp;
	flag=1;//��Ϊ�ж������Ƿ���ɵı�ǩ

	//���flag��ǩ��Ϊ0��֤���������ƶ�������δ��ɣ����Լ�������
	while(flag!=0)
	{
		flag=0;
		
		for(i=0;i<5;i++)
		{
			//����������ƶ����ͽ�flag����1 
			if(*(a+i)>*(a+i+1))
			{
			 	temp=*(a+i);
				*(a+i)=*(a+i+1);
				*(a+i+1)=temp;
				flag++;
			}
		}
	} 
	
	printf("�������~˳��Ϊ��\n");
	for (i=0;i<6;i++)
	{
		printf("%d",*(a+i)); 
	}
}


 
