#include <stdio.h>
#define MAXSIZE 20
#define N 9

struct list
{
	int data[MAXSIZE];
	int length;
}; 

typedef struct list SeqList;


//顺序查找算法
int SequenceSearch(SeqList *seqList,int key)
{
	int i;
	
	//遍历顺序表
	for(i=0;i<seqList->length;i++)
	{
		//找到该元素，返回其位置
		if(seqList->data[i]==key)
		{
			return i;
		}
	}	
		//没有找到，返回-1
		return -1; 
	
}


//打印结果
void Display(SeqList *seqList)
{
	int i;
	printf("总元素内容为");
	
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
	int d[N]={50,10,90,30,70,70,80,60,20};
	
	for(i=0;i<N;i++)
	{
		seqList.data[i]=d[i];
	}
	
	seqList.length=N;
	
	Display(&seqList);
	j=SequenceSearch(&seqList,70);//假设要找的数是70
	
	if(j!=-1)
	{
		printf("70在列表中的位置是：%d\n",j);
	}
	else
	{
		printf("404NOTFOUND!");
	}
	return 0; 
 } 
