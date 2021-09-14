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
	
	//当用户输入不为回车时进行的循环操作
	while ((ic=getchar())!='\n')
	{
		*(c+i)=ic;//赋值
		i++;
		
		if(ic=='#') //如果输入的是#进行退格
		{
			i-=3; //适用于中文！一个中文2个字符噢噢噢噢噢噢噢噢噢噢噢噢噢噢噢噢噢噢噢噢噢噢噢噢噢噢噢噢噢噢噢噢哦哦哦！！！ 
		} 
		else if(ic=='@')
		{
			i=0;
		}
	}
	
	//在结尾加上结束标志 
	*(c+i)='\0';
	puts(c);	
 } 
