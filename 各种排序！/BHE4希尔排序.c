#include <stdio.h>

int main(void)
{
	int a[8]={1,4,6,8,5,7,3,2};
	void shellsort(int *a);
	shellsort(a);
	return 0;
}


void shellsort(int *a)
{
	int count,temp,i,j,k,t;
	
	t=count=8/2;//间隔
	while(count!=1)//在间隔等于1之前执行按集合排序的算法
	{
		while(t<8)//防止下标越界~ 
		{
			//对于偶数下角标集合的排序 
			if(*(a+t)>*(a+t*2))
			{
				temp=*(a+t);
				*(a+t)=*(a+t*2);
				*(a+t+2)=temp; 
			}
			
			//对于奇数下角标集合的排序
			if(*(a+1+t)>*(a+1+t*2)) 
			{
				temp=*(a+t+1);
				*(a+t+1)=*(a+1+t*2);
				*(a+1+t*2)=temp;
			}	
			t+=t;//辅助下角标移动 
		} 
		count/=2;//间隔减半,开始新的一轮~ 
		t=count; 
	}
	
	//间隔为1时执行全数组插入排序（由于t为int不能为1/2，故间隔为1另作情况）
	//先将前两个数据元素进行排序 
	if(*(a+0)>*(a+1))
	{
		temp=*(a+0);
		*(a+0)=*(a+1);
		*(a+1)=temp;
	}
	
	//对剩余元素进行插入 
	for(i=2;i<8;i++)
	{
		for(j=0;j<i;j++)
		{
			if(*(a+i)<*(a+j))
			{
				temp=*(a+i);//将要插入的值赋给temp
				
				for(k=i;k>j;k--)//腾出要插入的位置 
				{
					*(a+k)=*(a+k-1); 
				}
				
				*(a+j)=temp;//插入 
			}
		}
	}
	
	printf("排序完成~顺序为：\n");
	for(i=0;i<8;i++)
	{
		printf("%d",*(a+i));
	} 
} 
