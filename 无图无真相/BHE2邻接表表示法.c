#include <stdio.h>
#include <stdlib.h>
#define MAX 100

//������Ϊ���㼯Ԫ�صĽṹ�� 
struct graph_point 
{
	int point_num;//����ֵ
	struct graph_line *next;//ָ����ͨ��ϵ����nextָ��
};

//������Ϊ��ͨ��ϵ�����Ľṹ�� 
struct graph_line 
{
	int line_point;//��ö����ڽӵĶ����ֵ
	struct graph_line *next;//nextָ��
};

typedef struct graph_point Gpoint;//��������
typedef struct graph_line Gline;

int main(void)
{
	Gpoint g1[MAX];
	void creat_graph(Gpoint *g);
	creat_graph(g1);
	return 0;
} 



void creat_graph(Gpoint *g)
{
	int p_num,l_num,i,h,l;
	Gline *p;//��Ϊ���ռ� 
	printf("�����붥������");
	scanf("%d",&p_num);
	
	for (i=0;i<p_num;i++)
	{
		printf("�������%d�������ֵ��",i+1);
		scanf("%d",&(g+i)->point_num);
		(g+i)->next=NULL;
	} 
	printf("�����������");
	scanf("%d",&l_num);
	
	for(i=0;i<l_num;i++)
	{
		//��������ͼ���ԣ�<V1,V2>��<V2,V1>��������ͨ��ϵ 
		//������������������Ϣ�ֽ⿪������������ڽӱ�Ľ�� 
		
		printf("�������%d�������ӵ��������㣨Vi��Vj):",i+1);
		scanf("%d %d",&h,&l);
		
		//������ռ䣬��ʧ�����˳� 
		p=(Gline*)malloc(sizeof(Gline));
		if(p==NULL)
		{
			printf("error!");
			return; 
		}
		
		//ͷ�巨 
		
		//���ý���nextָ��ָ��ǰ����ָ��ĵ�ַ
		p->next=g[h].next;
		//�ڽ����Ϊl(l��h���ڽ����~�� 
		p->line_point=l; 
		//����ǰ�����nextָ��ָ��p 
		(g+h)->next=p;
		
		//�ظ����沽�轫��һ�����뵽��һ��Ӧ���㼯Ԫ��
		p=(Gline*)malloc(sizeof(Gline));
		if(p==NULL)
		{
			printf("error!");
			return;
		}
		
		p->next=(g+l)->next;
		p->line_point=h;
		(g+l)->next=p;
	}
	
	printf("ͼ�������!ͼ�ж���Ϊ��\n");
	
	for(i=0;i<p_num;i++)
	{
		printf("%d ",(g+i)->point_num);
	} 
		printf("\n");
		printf("ͼ�е���ͨ��ϵΪ��\n"); 
	
	for(i=0;i<p_num;i++)
	{
		printf("��%d�������ֵΪ%d",i+1,(g+i)->point_num);
		
		//��������ڽӵĶ��㣬����� 
		if((g+i)->next!=NULL)
		{
			printf("\n");
			printf("�����ڽӵĶ���Ϊ��");
			p=(g+i)->next;
			
			while(p!=NULL)
			{
				printf("%d ",p->line_point);
				p=p->next;
			}
			printf("\n"); 
	    }
		
		else
		{
			printf("\n");
		} 
	}
}





































