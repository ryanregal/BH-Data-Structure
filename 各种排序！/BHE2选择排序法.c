#include<stdio.h>

int main(void)
{
	int a[6]={1,3,5,6,4,2};
	void sort(int *a);
	sort(a);
	return 0;
}

void sort(int *a)
{
	int flag,i,temp;
	flag=0;//作为记录当前进行排序的元素下角标的标签
	
	//当尚未排完所有元素，循环排序 
	while(flag<6)
	{
		for(i=flag;i<6;i++)
		{
			//如果当前要排序元素的值比后面的其他元素大，互换位置
			if(*(a+flag)>*(a+i))
			{
				temp=*(a+flag);
				*(a+flag)=*(a+i);
				*(a+i)=temp; 
			}
		}
		flag++; 
	}
	
	printf("排序完成！顺序为：\n");
	for(i=0;i<6;i++)
	{
		printf("%d",*(a+i));
	} 	
} 
