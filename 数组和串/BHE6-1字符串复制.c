#include<stdio.h>

int main(void)
{
	char c1[16]="Hello World~";
	char c2[16];
	void strcpy1(char *p1,char *p2);//��������
	strcpy1(c1,c2);
	//��c1��c2���ַ�ָ�����ʽ���뺯�� 
	puts(c1);
	printf("%s",c2);
	return 0; 
	 
}

void strcpy1(char *p1,char *p2)
{
	int i;
	//ִ�и��ƹ��� 
	for(i=0;*(p1+i)!='\0';i++)
	{
		*(p2+i)=*(p1+i);
	}
	//���ƺ����ַ��������"\0" 
	*(p2+i)='\0';
}
