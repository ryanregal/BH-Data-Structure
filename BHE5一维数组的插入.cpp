#include<stdio.h>
#include<stdlib.h>

//����main���� 
int main(void)
{
	int num1,num2,num3,i,re,temp;
	//tempΪ��sizeof��num 
	int*p;
	int insert1(int num1,int num2,int num3,int *p);
	printf("������ѧ������");
	scanf("%d",&num1);
	temp=((num1/4)+1)*4;
	//������һ��ռ�
	p=(int*)malloc(temp*sizeof(int));
	//��̬����ռ䴴������
	
	if (p==NULL)
	{
		printf("wrong");
		return -1;
	 } 
	 
	for (i=0;i<num1;i++)
	{
		printf("��������Ϊ%d��ѧ���ĳɼ�",i+1);
		scanf("%d",p+i);
	}
	
	printf("������Ҫ�����ѧ����ţ�");
	scanf("%d",&num2);
	printf("������Ҫ�����ѧ���ĳɼ�:");
	scanf("%d",&num3);
	re=insert1(num1,num2,num3,p);
	num1=re;
	//���µ�ǰ���鳤�ȣ���ѧ��������
	
	printf("����ɹ�,ѧ�����Ϊ��\n");
	for (i=0;i<num1;i++)
	{
		printf("��%d��ѧ���ĳɼ�Ϊ%d\n",i+1,*(p+i));//p+i�Ǵ���ɼ��ĵ�ַ 
	} 
	 return 0;
 } 
 
 //����insert���� 
 int insert1(int num1,int num2,int num3,int*p)
 {
   int i,j,temp1,temp2;
   
   for(i=0;i<=num1;i++)
   {
   	if(i==num2-1)
   	{
   		temp1=*(p+i);//ͨ��temp1��ʱ����Ҫ����λ��ԭ��ֵ
		*(p+i)=num3;//���ݲ��� 
		
		//��������λ�ú��������������Ԫ�ض�����һλ
		for(j=i;j<num1+1;j++)
		{
			temp2=*(p+j+1);//temp2���汻����λ��һλ 
			*(p+j+1)=temp1;//��һλֵ��ǰһλȡ�� 
			temp1=temp2; //����ǰһλֵ������ֱ��j=num+1 
		} 
		break;
		//������ɣ���ǰ����forѭ�������ѭ��/switch�� 
	}
	} 
	return num1+1;//�������鳤�ȣ�����������һ��Ԫ�ر����� 
}
