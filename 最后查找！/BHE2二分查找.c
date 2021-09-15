#include <stdio.h>
#define N 9
#define MAXSIZE 20

struct list
{
	int data[MAXSIZE];
	int length;
};

typedef struct list SeqList;

//二分查找算法
int BinarySearch(SeqList *seqList,int key)
{
	//初始下限
	int low=0;
	
	//初始上限
	int high=seqList->length-1;
	
	while(low<=high)
	{
		int middle=(low+high)/2;
		
		//判断中间记录是否与给定值相等
		if(seqList->data[middle]==key)
		{
			return middle;
		}
		else
		{
			if(seqList->data[middle]>key)
			{
				high=middle-1;//如果比key大，则去掉后一半，缩小上界 
			}
			
			else
			{
				low=middle+1; 
		 	} 
	 	} 
 	}
	 
	return -1;
}


void Display(SeqList *seqList)
{
	int i;
	printf("总元素内容：\n");
	
	for(i=0;i<seqList->length;i++)
	{
		printf("%d ",seqList->data[i]);
	}
	
	printf("\n");
}


int main(void)
{
	int i,j;
	SeqList seqList;
	
	//定义数组和初始化SeqList
	int d[N]={10,20,30,40,50,60,70,80,90};
	
	for(i=0;i<N;i++)
	{
		seqList.data[i]=d[i]; 
	}
	seqList.length=N; 

	Display(&seqList);
	
	//假设要找的是40 
	j=BinarySearch(&seqList,40);
	if(j!=-1)
	{
		printf("40在表中的位置是：%d\n",j);
	}
	else
	{
		printf("404 NOT FOUND"); 
	} 
	
	return 0;
}






