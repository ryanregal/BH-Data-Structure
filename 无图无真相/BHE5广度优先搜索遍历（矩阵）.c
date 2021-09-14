#include <stdlib.h> 
#include <stdio.h>
#define MAX 100

struct graph
{
	int point[MAX];//顶点表
	int line [MAX][MAX];//邻接矩阵，也称边表
	int point_num;//用于记录用户输入的顶点数
	int line_num;//用于记录用户输入的边数 
};


//声明队列结点 
struct queue
{
	int num;
	struct queue *next;
};

int visited[MAX];
typedef struct graph G;
typedef G* Gptr;
typedef struct queue Q;

int main(void)
{
	G g1;
	void creat_graph(Gptr g);
	void BFS_travel(Gptr g);
	creat_graph(&g1);
	
	printf("广度遍历顺序为：\n");
	BFS_travel(&g1); 
	printf("\n");
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


//广度优先搜索遍历函数 
void BFS_travel(Gptr g)
{
	int i,j,k;
	Q *queue;
	Q *DeQueue(Q *queue,int *k);//出队列函数 
	Q *EnQueue(Q *queue,int n);//入队列函数
	queue=NULL;
	
	//将所有顶点设为未被遍历过 
	for(i=0;i<g->point_num;i++)
	{
		visited[i]=0;
	}
	
	//开始遍历
	for(i=0;i<g->point_num;i++)
	{
		//找到没遍历过的顶点 
		if(visited[i]==0)
		{
			visited[i]=1;//设为已遍历
			printf("%d",g->point[i]);//输出内容
			queue=EnQueue(queue,i);//将其入队列
			
			//遍历它的所有邻接顶点 
			while(1) 
			{
				//从队列取出要遍历其所有邻接顶点的顶点
				queue=DeQueue(queue,&k);
				
				//如果队列已空，跳出循环(k是出队列函数的返回值） 
				if(k==-1) 
				{
					break;
				}
				
				for(j=0;j<g->point_num;j++)
				{
					if(g->line[k][j]==1 &&visited[j]==0)
					{
						visited[j]=1;
						printf("%d",g->point[j]);
						
						//遍历后将其入队列以便记录遍历层次 
					}
				}
	 		} 
		} 
	} 
} 


//入队列函数 
Q *EnQueue(Q *queue,int n)
{
	Q *previous,*last;
	
	//如果队列是空的，申请空间并赋值 
	if(queue==NULL)
	{
		queue=(Q*)malloc(sizeof(Q));
		if(queue==NULL)
		{
			printf("error!");
			return NULL;
		}
		
		queue->num=n;//n即是BFS函数传入的i
		queue->next=NULL;
		return queue;//返回队列头地址 
	} 
	
	//如果不是空的，找到队列尾申请空间并赋值 
	else 
	{
		last=queue;
		
		while(last!=NULL)
		{
			previous=last;
			last=last->next;
		}
		
		last=(Q*)malloc(sizeof(Q));
		if(last==NULL)
		{
			printf("error!");
			return NULL;
		}
		
		last->num=n;
		last->next=NULL; 
		previous->next=last;
		return queue;//返回队列头地址 
	} 
} 


//出队列函数,传入的k是初始值 
Q *DeQueue(Q *queue,int *k)	
{
	Q *t;
	
	//若队列为空，将*k赋值为-1 
	if (queue==NULL)
	{
		*k=-1;
		return NULL; 
	}
	
	*k=queue->num;//将顶点下角标值赋给*k
	t=queue;
	queue=queue->next;
	free(t);
	return queue;//返回队列的新首地址！！！	
} 
	
	
	
	
	
	
	
	
	
	
	
	 
