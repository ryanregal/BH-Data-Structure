#include<stdio.h>
#include<stdlib.h>
//求两字符串长度之和，动态申请一个新字符串数组，再进行赋值 


int main(void)
{
	int strlen1(char *c);
	//函数声明 
	void strclink(char *c1,char *c2,char *c3);
	char c1[1000],c2[1000];
	char *p;
	int s=0;	//记录字符串长度 
	
	printf("请输入第一个字符串：");
	gets(c1);
	s+=strlen1(c1);
	printf("请输入第二个字符串：");
	gets(c2);
	s+=strlen1(c2);
	
	//动态申请空间
	p=(char*)malloc((s+1)*sizeof(char));
	strclink(c1,c2,p);
	printf("连接之后的字符串是：");
	puts(p);
	free(p); //记得释放申请空间！！！ 
	return 0;
}

int strlen1(char *c)
{
	int i;
	for(i=0;*(c+i)!='\0';i++);
	//空循环，记录字符串长度 
	return i;
}

void strclink(char*c1,char*c2,char*c3)
{
	int i,t;
	//复制字符串 
	for(i=0;*(c1+i)!='\0';i++)
	{
		*(c3+i)=*(c1+i);
	}	
	
	t=i;//记住c3被赋值到的位置
	
	for(i=0;*(c1+i)!='\0';i++)//++ i 是先加后赋值；i ++ 是先赋值后加
	{
		*(c3+t+i)=*(c2+i);	
	} 
	 
	*(c3+t+i)='\0';
	
	
} 
