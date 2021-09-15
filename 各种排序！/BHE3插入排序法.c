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
	int temp,i,j,k;
	
	//先将前两个数据元素进行排序 
	if(*(a+0)>*(a+1))
	{
		temp=*(a+0);
		*(a+0)=*(a+1);
		*(a+1)=temp; 
	}
	
	//对剩余元素进行插入 
	for(i=2;i<6;i++)
	{
		for(j=0;j<i;j++)
		{ 
			//找到插入位置 
			if(*(a+i)<*(a+j))
			{
				temp=*(a+i);//将要插入的值赋值给temp
				for(k=i;k>j;k--)//腾出要插入的位置
				{
					*(a+k)=*(a+k-1); 
				}
				*(a+j)=temp;//插入 
			}
		}
	}
	
	printf("排序完成~顺序为：\n");
	for(i=0;i<6;i++)
	{
		printf("%d",*(a+i));
	}
}
