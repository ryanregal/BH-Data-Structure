#include <stdio.h>
#define N 9
#define MAXSIZE 20

struct list
{
	int data[MAXSIZE];
	int length;
};

typedef struct list SeqList;

//���ֲ����㷨
int BinarySearch(SeqList *seqList,int key)
{
	//��ʼ����
	int low=0;
	
	//��ʼ����
	int high=seqList->length-1;
	
	while(low<=high)
	{
		int middle=(low+high)/2;
		
		//�ж��м��¼�Ƿ������ֵ���
		if(seqList->data[middle]==key)
		{
			return middle;
		}
		else
		{
			if(seqList->data[middle]>key)
			{
				high=middle-1;//�����key����ȥ����һ�룬��С�Ͻ� 
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
	printf("��Ԫ�����ݣ�\n");
	
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
	
	//��������ͳ�ʼ��SeqList
	int d[N]={10,20,30,40,50,60,70,80,90};
	
	for(i=0;i<N;i++)
	{
		seqList.data[i]=d[i]; 
	}
	seqList.length=N; 

	Display(&seqList);
	
	//����Ҫ�ҵ���40 
	j=BinarySearch(&seqList,40);
	if(j!=-1)
	{
		printf("40�ڱ��е�λ���ǣ�%d\n",j);
	}
	else
	{
		printf("404 NOT FOUND"); 
	} 
	
	return 0;
}






