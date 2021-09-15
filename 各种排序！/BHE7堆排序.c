#include <stdio.h>
#define MAXSIZE 100
#define N 9

struct list
{
	int data[MAXSIZE];
	int length;
}; 

typedef struct list SeqList; 


//构造大根堆，parent下沉调整 
void HeapAdjust(SeqList *seqList,int parent,int length)
{
	int temp,leftChild;
	temp=seqList->data[parent];//temp保存父节点值，用于最后赋值 
	leftChild=2*parent+1;//数组中的排序是从0开始的！所以要+1 
	
	while(leftChild<length)
	{
		if(leftChild+1<length &&seqList->data[leftChild]<seqList->data[leftChild+1])//右孩子不越界且右孩子大于左孩子的值 
		{
			leftChild++; //则定位到右孩子 
		}
		
		if(temp>=seqList->data[leftChild])//如果父母结点大于左孩子结点，排序完成，退出 
		{
			break;
		}
		
		//单向赋值，定位下移 
		seqList->data[parent]=seqList->data[leftChild];
		
		parent=leftChild;
		
		leftChild=2*parent+1;
	}
	
	seqList->data[parent]=temp;//最后将leftchild赋值为最初的parent 
} 

 
//交换元素
void Swap(SeqList *seqList,int top,int last)
{
	int temp=seqList->data[top];
	seqList->data[top]=seqList->data[last];
	seqList->data[last]=temp;
} 


//堆排序算法
void HeapSort(SeqList *seqList)
{
	int i;
	for(i=seqList->length/2-1;i>=0;i--)//从中间开始，将无序数组构建成二叉堆 
	{
		HeapAdjust(seqList,i,seqList->length);//调用构建大根堆函数 
	}
	
	for(i=seqList->length-1;i>0;i--)//循环删除堆顶元素，移到集合尾部，调节堆产生新的堆顶 
	{
		Swap(seqList,0,i);//最后一个元素和第一个互换 
		HeapAdjust(seqList,0,i); //下沉调整最大堆 
	}
} 


//打印结果
void Display(SeqList *seqList)
{
	int i;
	printf("\n*****************展示结果******************\n");
	
	for(i=0;i<seqList->length;i++)
	{
		printf("%d ",seqList->data[i]);
	}
	
	printf("\n************展示完毕************\n"); 
}



int main(void)
{
	int i,j;
	SeqList seqList;
	
	//定义数组和初始化SeqList
	int d[N]={50,10,90,30,70,40,80,60,20}; 
	
	for(i=0;i<N;i++)
	{
		seqList.data[i]=d[i];
	}
	
	seqList.length=N;
	
	printf("排序前：");
	Display(&seqList);//打印结果
	
	HeapSort(&seqList);//堆排序算法 
	printf("\n排序后：");
	Display(&seqList); 
	
	return 0; 
} 
 
