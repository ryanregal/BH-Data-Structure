# include<stdio.h>
//此方法构造的字符串没有"\0"标志结束 
int main(void)
{
	char c[100]; 
	//定义一个足够大的字符型数组
	char ch;
	//定义一个字符串 
	int i;
	for (i=1;(ch=getchar())!='\n';i++)
	//字符串数组赋值
	//从c[1]开始，c[0]空出以储存字符串长度
	//c语言中，char类型和int类型在不产生数据溢出的情况下是互通的 
	
	{
		*(c+i)=ch; 
    }
    
    *(c+0)=i-1;
	//i-1即字符串长度，赋值给c[0] 
	 
	for (i=1;i<=*(c+0);i++)//输出字符串 
	{
		printf("%c",*(c+i)); 
	}
	printf("\n");
	return 0;
	
}
    
