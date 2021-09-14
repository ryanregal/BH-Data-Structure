#include <stdio.h>

//将二维数组定义为了全局变量，函数调用就不用指针调用啦 
int maze[7][10]=
{
	1,1,1,1,1,1,1,1,1,1, 
	1,0,1,0,1,0,0,0,0,1,
	1,0,1,0,1,0,1,1,0,1,
	1,0,1,0,1,1,1,0,0,1,
	1,0,1,0,0,0,0,0,1,1,
	1,0,0,0,1,1,1,0,0,1,
	1,1,1,1,1,1,1,1,1,1
}; 

int main(void)
{
	int i,j;
	int find(int x,int y);
	find(1,1);
	printf("迷宫走法如下：\n");
	
	for(i=1;i<6;i++)
	{
		for(j=1;j<9;j++)
		{
			printf("%d",*(*(maze+i)+j));
		}
		printf("\n");
	}
	return 0; 
}

int find(int x,int y)
{
	//判断是否终点 
	if(x==5&&y==8)
	{
		*(*(maze+x)+y)=2;
		return 1;
	}
	
	//判断该位置是否是落脚点，如果是障碍物则返回
	else if(*(*(maze+x)+y)==0)
	{
		*(*(maze+x)+y)=2;
		
		if(find(x-1,y)+find(x+1,y)+find(x,y-1)+find(x,y+1)>0)//利用了栈的递归 
		{
			return 1;
		}
		
		//如果该位置的上下左右都不能走，返回0 
		else
		{
			*(*(maze+x)+y)=0;
			return 0; 
		}
	} 
	
	//判断是否为障碍
	
	 
	else
	{
		return 0;
	}
} 
