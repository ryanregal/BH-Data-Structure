#include <stdio.h>

int main(void)
{
	char c[100];
	void sword(char *c);
	sword(c);
	return 0;
}

void sword(char *c)
{
	char ic;
	int i=0;
	
	//���û����벻Ϊ�س�ʱ���е�ѭ������
	while ((ic=getchar())!='\n')
	{
		*(c+i)=ic;//��ֵ
		i++;
		
		if(ic=='#') //����������#�����˸�
		{
			i-=3; //���������ģ�һ������2���ַ�����������������������������������������������������������������ŶŶŶ������ 
		} 
		else if(ic=='@')
		{
			i=0;
		}
	}
	
	//�ڽ�β���Ͻ�����־ 
	*(c+i)='\0';
	puts(c);	
 } 
