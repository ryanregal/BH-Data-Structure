#include <stdio.h>
#define MAX 100

struct graph
{
	int point[MAX];//顶点表
	int line [MAX][MAX];//邻接矩阵，也称边表
	int point_num;//用于记录用户输入的顶点数
	int line_num;//用于记录用户输入的边数 
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
	
	printf("请输入顶点数");
	scanf("%d",&g->point_num); 
	printf("请输入边数：");
	scanf("%d",&g->line_num);
	
	//顶点表值输入 
	for(i=0;i<g->point_num;i++)
	{
		printf("请输入第%d个顶点的值",i+1);
		scanf("%d",&g->point[i]); 
	}
	
	//邻接矩阵初始化赋值
	for(i=0;i<g->point_num;i++)
	{
		for (j=0;j<g->point_num;j++)
		{
			g->line[i][j]=0;
		}
	}
	
	for (i=0;i<g->line_num;i++)
	{
		printf("请输入第%d条边连接的两个顶点（Vi,Vj):",i+1);
		scanf("%d %d",&h,&l);
		
		//将邻接矩阵中对应值从0改为1 
		g->line[h][l]=g->line[l][h]=1; 
	
	}
		printf("图构建完成！图中顶点为：\n");
		
		//输出一维数组 
		for(i=0;i<g->point_num;i++)
		{	
			printf("%d",g->point[i]);
		} 
		
		printf("\n");
		printf("它们在图中的连通关系为：\n");
		
		for(i=0;i<g->point_num;i++)
		{
			for(j=0;j<g->point_num;j++)
			{
				printf("%d",g->line[i][j]);
			}
			printf("\n");
		} 
} 

