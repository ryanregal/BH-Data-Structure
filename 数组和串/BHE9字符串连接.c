#include<stdio.h>
#include<stdlib.h>
//�����ַ�������֮�ͣ���̬����һ�����ַ������飬�ٽ��и�ֵ 


int main(void)
{
	int strlen1(char *c);
	//�������� 
	void strclink(char *c1,char *c2,char *c3);
	char c1[1000],c2[1000];
	char *p;
	int s=0;	//��¼�ַ������� 
	
	printf("�������һ���ַ�����");
	gets(c1);
	s+=strlen1(c1);
	printf("������ڶ����ַ�����");
	gets(c2);
	s+=strlen1(c2);
	
	//��̬����ռ�
	p=(char*)malloc((s+1)*sizeof(char));
	strclink(c1,c2,p);
	printf("����֮����ַ����ǣ�");
	puts(p);
	free(p); //�ǵ��ͷ�����ռ䣡���� 
	return 0;
}

int strlen1(char *c)
{
	int i;
	for(i=0;*(c+i)!='\0';i++);
	//��ѭ������¼�ַ������� 
	return i;
}

void strclink(char*c1,char*c2,char*c3)
{
	int i,t;
	//�����ַ��� 
	for(i=0;*(c1+i)!='\0';i++)
	{
		*(c3+i)=*(c1+i);
	}	
	
	t=i;//��סc3����ֵ����λ��
	
	for(i=0;*(c1+i)!='\0';i++)//++ i ���ȼӺ�ֵ��i ++ ���ȸ�ֵ���
	{
		*(c3+t+i)=*(c2+i);	
	} 
	 
	*(c3+t+i)='\0';
	
	
} 
