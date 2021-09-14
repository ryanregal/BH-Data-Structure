#define MAX 10
#include<stdio.h>

int main(void)
{
	int queue[MAX];
	int *head,*end;//定义队头指针对尾指针 
	int size;//用来记录队列中可使用空间个数的变量 
	int Requeue(int *head,int *end,int *queue,int size);
	int Dequeue(int *head,int *end,int *queue,int size);
	head=(queue+0);
	end=(queue+0);
	size=MAX;
	size=Requeue(head,end,queue,size);
	size=Dequeue(head,end,queue,size);
}


//添加数据到对尾的函数 
int Requeue(int *head,int *end,int *queue,int size)
{
	int i,num;
	printf("请输入要入队列的数据个数：");
	scanf("%d",&num);
	
	//如果队列内剩余空间足够存放新数据，执行此操作 
	if(num<=size) 
	{
		for(i=0;i<num;i++)
		{
			//防止下角标越界，如果将要越界，进行循环操作，将指针指向数组首地址 
			if(end==(queue+MAX))
			{
				end=(queue+0);
			}
			printf("请输入入队的第%d个数据：",i+1);
			scanf("%d",end); 
			end++; //end指针指向下一个空间
			size--;//剩余可用空间-1 
		}
	}
	else
	{
		printf("超过队列长度！");
	}
	//返回最新的可用空间信息 
	return size;
}

//删除队列数据的函数 
int Dequeue(int *head,int *end,int *queue,int size)
{
	int num,i,s;
	printf("请输入要出列的数据个数：");
	scanf("%d",&num);
	
	//如果队列内数据足够输出要求的个数 
	if (num<=MAX-size) 
	{
		for(i=0;i<num;i++)
		{
			printf("数据%d已出列\n",*head);
			head++;
			size++;
			
			//防止下角标越界，如果将要越界，进行循环操作将指针指向数组首地址 
			if(head==(queue+MAX))
			{
				head=(queue+0);
			}
		} 
	}

	else
	{
		printf("队列中元素个数不足！");
		return size; 
	}
	
	//s用来记录当前队列中剩余的元素个数 
	s=MAX-size;
	
	//如果还有剩余数据，输出剩余数据信息 
	if(s!=0)
	{
		printf("出列成功，当前队列剩余元素依次为：\n");
		while(s>0)
		{
			printf("%d",*head);
			head++;
			if(head==(queue+MAX))
			{
				head=(queue+0);
			}
			s--;
		 } 
	} 
	else
	{
		printf("出队成功，当前队列为空队列！"); 
	}
	return size; 
}

