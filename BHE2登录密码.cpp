#include <stdio.h>
#include <string.h>
#include <stdbool.h>
/* 方便使用布尔类型*/ 

int main(void)
{
	bool flag;
	char psw[8];
	
	flag=0;
	
	printf("please input password:\n");
	gets(psw);
	
	if(strcmp(psw,"mypx&k")==0)
	{
		flag=1;
	}
	
	if (flag)
	{
		printf("you are admin\n");
	}
	else
	{
		printf("wrong password!\n");
	}
	
	printf("&flag:%p\n",&flag);
	printf("&psw[0]:%p\n&psw[7]:%p\n",&psw[0],&psw[7]);
	return 0;	
}
