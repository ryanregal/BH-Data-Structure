#include<stdio.h>

int main(void)
{
	char c1[16]="Hello World~";
	char c2[16];
	void strcpy1(char *p1,char *p2);//函数声明
	strcpy1(c1,c2);
	//将c1，c2以字符指针的形式传入函数 
	puts(c1);
	printf("%s",c2);
	return 0; 
	 
}

void strcpy1(char *p1,char *p2)
{
	int i;
	//执行复制过程 
	for(i=0;*(p1+i)!='\0';i++)
	{
		*(p2+i)=*(p1+i);
	}
	//复制后在字符串后加上"\0" 
	*(p2+i)='\0';
}
