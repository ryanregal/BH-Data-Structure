#include <stdio.h>
#define MAX 100

struct graph
{
	int point[MAX];//�����
	int line [MAX][MAX];//�ڽӾ���Ҳ�Ʊ߱�
	int point_num;//���ڼ�¼�û�����Ķ�����
	int line_num;//���ڼ�¼�û�����ı��� 
};

typedef struct graph G;
typedef G* Gptr;

int main(void)
{
	G g1;
	void creat_graph(Gptr g);
	creat_graph(&g1);
	return 0; 
}

void creat_graph(Gptr g)
{
	int i,j,h,l;
	
	printf("�����붥����");
	scanf("%d",&g->point_num); 
	printf("�����������");
	scanf("%d",&g->line_num);
	
	//�����ֵ���� 
	for(i=0;i<g->point_num;i++)
	{
		printf("�������%d�������ֵ",i+1);
		scanf("%d",&g->point[i]); 
	}
	
	//�ڽӾ����ʼ����ֵ
	for(i=0;i<g->point_num;i++)
	{
		for (j=0;j<g->point_num;j++)
		{
			g->line[i][j]=0;
		}
	}
	
	for (i=0;i<g->line_num;i++)
	{
		printf("�������%d�������ӵ��������㣨Vi,Vj):",i+1);
		scanf("%d %d",&h,&l);
		
		//���ڽӾ����ж�Ӧֵ��0��Ϊ1 
		g->line[h][l]=g->line[l][h]=1; 
	
	}
		printf("ͼ������ɣ�ͼ�ж���Ϊ��\n");
		
		//���һά���� 
		for(i=0;i<g->point_num;i++)
		{	
			printf("%d",g->point[i]);
		} 
		
		printf("\n");
		printf("������ͼ�е���ͨ��ϵΪ��\n");
		
		for(i=0;i<g->point_num;i++)
		{
			for(j=0;j<g->point_num;j++)
			{
				printf("%d",g->line[i][j]);
			}
			printf("\n");
		} 
} 

