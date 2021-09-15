#include <stdio.h>
#define MAXSIZE 100
#define N 9

struct list
{
	int data[MAXSIZE];
	int length;
}; 

typedef struct list SeqList; 


//�������ѣ�parent�³����� 
void HeapAdjust(SeqList *seqList,int parent,int length)
{
	int temp,leftChild;
	temp=seqList->data[parent];//temp���游�ڵ�ֵ���������ֵ 
	leftChild=2*parent+1;//�����е������Ǵ�0��ʼ�ģ�����Ҫ+1 
	
	while(leftChild<length)
	{
		if(leftChild+1<length &&seqList->data[leftChild]<seqList->data[leftChild+1])//�Һ��Ӳ�Խ�����Һ��Ӵ������ӵ�ֵ 
		{
			leftChild++; //��λ���Һ��� 
		}
		
		if(temp>=seqList->data[leftChild])//�����ĸ���������ӽ�㣬������ɣ��˳� 
		{
			break;
		}
		
		//����ֵ����λ���� 
		seqList->data[parent]=seqList->data[leftChild];
		
		parent=leftChild;
		
		leftChild=2*parent+1;
	}
	
	seqList->data[parent]=temp;//���leftchild��ֵΪ�����parent 
} 

 
//����Ԫ��
void Swap(SeqList *seqList,int top,int last)
{
	int temp=seqList->data[top];
	seqList->data[top]=seqList->data[last];
	seqList->data[last]=temp;
} 


//�������㷨
void HeapSort(SeqList *seqList)
{
	int i;
	for(i=seqList->length/2-1;i>=0;i--)//���м俪ʼ�����������鹹���ɶ���� 
	{
		HeapAdjust(seqList,i,seqList->length);//���ù�������Ѻ��� 
	}
	
	for(i=seqList->length-1;i>0;i--)//ѭ��ɾ���Ѷ�Ԫ�أ��Ƶ�����β�������ڶѲ����µĶѶ� 
	{
		Swap(seqList,0,i);//���һ��Ԫ�غ͵�һ������ 
		HeapAdjust(seqList,0,i); //�³��������� 
	}
} 


//��ӡ���
void Display(SeqList *seqList)
{
	int i;
	printf("\n*****************չʾ���******************\n");
	
	for(i=0;i<seqList->length;i++)
	{
		printf("%d ",seqList->data[i]);
	}
	
	printf("\n************չʾ���************\n"); 
}



int main(void)
{
	int i,j;
	SeqList seqList;
	
	//��������ͳ�ʼ��SeqList
	int d[N]={50,10,90,30,70,40,80,60,20}; 
	
	for(i=0;i<N;i++)
	{
		seqList.data[i]=d[i];
	}
	
	seqList.length=N;
	
	printf("����ǰ��");
	Display(&seqList);//��ӡ���
	
	HeapSort(&seqList);//�������㷨 
	printf("\n�����");
	Display(&seqList); 
	
	return 0; 
} 
 
