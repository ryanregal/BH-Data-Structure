#include<stdio.h>
#define MAX 100

struct graph
{
	int point[MAX];//�����
	int line[MAX][MAX];//�ڽӾ���Ҳ�Ʊ߱�
	int point_num;//���ڼ�¼�û�����Ķ�����
	int line_num;//���ڼ�¼�û�����ı��� 
};

int visited[MAX];//���ڼ�¼�������Ƿ񱻱�����

typedef struct graph G;//��������
typedef G* Gptr;


int main(void)
{
	G g1;
	void creat_graph(Gptr g);
	void DFS_travel(Gptr g);
	void DFS(Gptr g,int i);
	creat_graph(&g1);
	printf("��ȱ���˳��Ϊ��\n");
	DFS_travel(&g1); 
	printf("\n");
	return 0; 
}


void creat_graph(Gptr g)
{
	int i,j,h,l;
	printf("�����붥������");
	scanf("%d",&g->point_num);
	printf("�����������");
	scanf("%d",&g->line_num);
	
	for(i=0;i<g->point_num;i++)
	{
		printf("�������%d�������ֵ",i+1);
		scanf("%d",&g->point[i]);	
	}
	
	
	//��Ҫ�õ����ڽӾ����ʼ��
	for (i=0;i<g->point_num;i++)
	{
		for(j=0;j<g->point_num;j++)
		{
			g->line[i][j]=0;
		}
	}
	
	for(i=0;i<g->line_num;i++) 
	{
		printf("�������%d�������ӵ��������㣨Vi��Vj����",i+1);
		scanf("%d %d",&h,&l);
		//���ڽӾ����Ӧλ�ô�0��Ϊ1
		g->line[h][l]=g->line[l][h]=1; 
	}
	
	printf("ͼ������ɣ�ͼ�ж���Ϊ��\n");
	
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
			printf("%d ",g->line[i][j]);
		}
		
		printf("\n");
	}
}
	
	
void DFS_travel(Gptr g)
{
	int i;
	void DFS(Gptr g,int i);
	
	for (i=0;i<g->point_num;i++)
	{
		visited[i]=0;	
	}
	
	//��ʼ���� 
	for(i=0;i<g->point_num;i++)
	{
		//�����ǰ����û������������ִ��DFS��������������ȵݹ����
		if(visited[i]==0)
		{
			DFS(g,i);
		}
	}
}


void DFS(Gptr g,int i)
{
	int j;
	//���ö�����Ϊ�ѱ��� 
	visited[i]=1;
	//��������� 
	printf("%d",g->point[i]); 
	
	//Ѱ�������ڽӵĶ��� 
	for(j=0;j<g->point_num;j++)
	{
		//�������ڽӶ�����û��������
		if(g->line[i][j]==1&&visited[j]==0)
		{
			//������еݹ������ 
			DFS(g,j);
		} 
	} 
}
	
	

