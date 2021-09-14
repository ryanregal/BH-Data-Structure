#include<stdio.h>
#define MAX 100

struct graph
{
	int point[MAX];//顶点表
	int line[MAX][MAX];//邻接矩阵，也称边表
	int point_num;//用于记录用户输入的顶点数
	int line_num;//用于记录用户输入的边数 
};

int visited[MAX];//用于记录各顶点是否被遍历过

typedef struct graph G;//声明别名
typedef G* Gptr;


int main(void)
{
	G g1;
	void creat_graph(Gptr g);
	void DFS_travel(Gptr g);
	void DFS(Gptr g,int i);
	creat_graph(&g1);
	printf("深度遍历顺序为：\n");
	DFS_travel(&g1); 
	printf("\n");
	return 0; 
}


void creat_graph(Gptr g)
{
	int i,j,h,l;
	printf("请输入顶点数：");
	scanf("%d",&g->point_num);
	printf("请输入边数：");
	scanf("%d",&g->line_num);
	
	for(i=0;i<g->point_num;i++)
	{
		printf("请输入第%d个顶点的值",i+1);
		scanf("%d",&g->point[i]);	
	}
	
	
	//将要用到的邻接矩阵初始化
	for (i=0;i<g->point_num;i++)
	{
		for(j=0;j<g->point_num;j++)
		{
			g->line[i][j]=0;
		}
	}
	
	for(i=0;i<g->line_num;i++) 
	{
		printf("请输入第%d条边连接的两个顶点（Vi，Vj）：",i+1);
		scanf("%d %d",&h,&l);
		//将邻接矩阵对应位置从0改为1
		g->line[h][l]=g->line[l][h]=1; 
	}
	
	printf("图构建完成！图中顶点为：\n");
	
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
	
	//开始遍历 
	for(i=0;i<g->point_num;i++)
	{
		//如果当前顶点没被遍历过，则执行DFS函数进行深度优先递归遍历
		if(visited[i]==0)
		{
			DFS(g,i);
		}
	}
}


void DFS(Gptr g,int i)
{
	int j;
	//将该顶点标记为已遍历 
	visited[i]=1;
	//输出其内容 
	printf("%d",g->point[i]); 
	
	//寻找与其邻接的顶点 
	for(j=0;j<g->point_num;j++)
	{
		//若存在邻接顶点且没被遍历过
		if(g->line[i][j]==1&&visited[j]==0)
		{
			//对其进行递归遍历！ 
			DFS(g,j);
		} 
	} 
}
	
	

