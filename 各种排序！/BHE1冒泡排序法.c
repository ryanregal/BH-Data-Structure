#include <stdio.h>

int main(void)
{
	int a[6]={1,3,5,6,4,2};
	void sort(int *a);
	
	sort(a);
	return 0;
}

void sort(int *a)
{
	int i,flag,temp;
	flag=1;//作为判断排序是否完成的标签

	//如果flag标签不为0，证明有数据移动排序尚未完成，所以继续排序
	while(flag!=0)
	{
		flag=0;
		
		for(i=0;i<5;i++)
		{
			//如果有数据移动，就将flag自增1 
			if(*(a+i)>*(a+i+1))
			{
			 	temp=*(a+i);
				*(a+i)=*(a+i+1);
				*(a+i+1)=temp;
				flag++;
			}
		}
	} 
	
	printf("排序完成~顺序为：\n");
	for (i=0;i<6;i++)
	{
		printf("%d",*(a+i)); 
	}
}


 
