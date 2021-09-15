#include <stdio.h>
#define MAXSIZE 20
#define N 9

struct list
{
	int data[MAXSIZE];
	int length;
}; 

typedef struct list SeqList;


//˳������㷨
int SequenceSearch(SeqList *seqList,int key)
{
	int i;
	
	//����˳���
	for(i=0;i<seqList->length;i++)
	{
		//�ҵ���Ԫ�أ�������λ��
		if(seqList->data[i]==key)
		{
			return i;
		}
	}	
		//û���ҵ�������-1
		return -1; 
	
}


//��ӡ���
void Display(SeqList *seqList)
{
	int i;
	printf("��Ԫ������Ϊ");
	
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
	int d[N]={50,10,90,30,70,70,80,60,20};
	
	for(i=0;i<N;i++)
	{
		seqList.data[i]=d[i];
	}
	
	seqList.length=N;
	
	Display(&seqList);
	j=SequenceSearch(&seqList,70);//����Ҫ�ҵ�����70
	
	if(j!=-1)
	{
		printf("70���б��е�λ���ǣ�%d\n",j);
	}
	else
	{
		printf("404NOTFOUND!");
	}
	return 0; 
 } 
