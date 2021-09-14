#include<stdio.h>
void Swap(int a,int b)
{
	int temp;
	
	temp=a;
	a=b;
	b=temp;
	printf("a=%d b=%d\n",a,b);
}

int main(void)
{
	int a,b;
	void Swap(int a,int b);
	
	scanf("%d%d",&a,&b);
	Swap(a,b);
	printf("a=%d b=%d\n",a,b);
	
	return 0;
	
}
