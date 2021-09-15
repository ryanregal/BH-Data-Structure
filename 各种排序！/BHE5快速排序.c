//递归调用 
#include<stdio.h>

int main(void)
{
	int a[8]={4,1,6,8,5,7,3,2}; 
	int count,i;
	
	void q_sort(int *a,int left,int right);
	void quick(int *a,int n);
	count=8;//标记数组长度
	
	quick(a,count);//调用快速排序函数 
	
	printf("最终结果：\n");
	
	for(i=0;i<8;i++)
	{
		printf("%d",*(a+i));
	}
	
	printf("\n");
	
	return 0; 
}


//快速排序法
void quick(int *a,int n)
{
	void q_sort(int *a,int left,int right); 
	q_sort(a,0,n-1);//调用分割函数 
 } 
 

//分割函数 
//最初的left是0，right是n-1 
void q_sort(int *a,int left,int right)
{
	int partition;//分割元素
	int temp;
	int i,j,k; 
	
  if(left<right)//左指针小于右指针则继续分割 
  { 
		i=left;//分割的最左
		j=right+1;//分割的最右
		partition=a[left];//取第一个元素 
	
	
	do//一直循环直到左指针i大于或等于右指针j 
	{
		do//从左往右(第二个元素开始，即i=1），直到找到一个左边元素大于等于partition 
		{
			i++;
		}
		while(a[i]<partition);
		
		do//找到比标准值大的后开始从右往左找 
		{
			j--;
		}
		while(a[j]>partition); 
		
		if(i<j)//交换数据 
		{
			temp=a[i];
			a[i]=a[j];
			a[j]=temp; 
		} 
	}
	while(i<j);
	
	//当左指针i大于等于右指针j，将第一个元素a[left]与右指针元素换位
	temp=a[left];
	a[left]=a[j];
	a[j]=temp; 

	printf("输出结果"); 
	
	//输出处理后的数组 
	for(k=left;k<=right;k++)
	{
		printf("%d",a[k]);
	}
	printf("\n");
	
	q_sort(a,left,j-1);//对左边进行快速排序递归调用 
	q_sort(a,j+1,right);//对右边进行快速排序递归调用 
  }
} 







 
