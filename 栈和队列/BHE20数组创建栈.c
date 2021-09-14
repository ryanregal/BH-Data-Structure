#define MAX 100
#include <stdio.h>

int main(void)
{
	int a[100];
	int top;
	int CreatSteak(int*a);
	top=CreatSteak(a); 
	void Show(int*a,int top);
	Show(a,top);
	return 0; 
}

int CreatSteak(int*a)
{
	int top,num;
	top=-1;
	scanf("%d",&num);
	while(num!=0)
	{
		if (top==MAX-1)
		{
			printf("栈已满");
			return MAX-1; 
		}
		top++;
		*(a+top)=num;
		scanf("%d",&num);
	}
	
	return top;
} 

void Show(int*a,int top)
{
	printf("栈内数据为：\n");
	while (top>=0)
	{
		printf("%d\n",*(a+top));
		top--;
	} 
}
