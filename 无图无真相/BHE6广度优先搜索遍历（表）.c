#include <stdio.h>
#include <stdlib.h>
#define MAX 100

//声明作为顶点集元素的结构体 
struct graph_point 
{
	int point_num;//顶点值
	struct graph_line *next;//指向连通关系集的next指针
};

//声明作为连通关系集结点的结构体 
struct graph_line 
{
	int line_point;//与该顶点邻接的顶点的值
	struct graph_line *next;//next指针
};

struct queue//声明队列结点
{
	int num;
	struct queue *next;
}; 

int visited[MAX];//用于记录顶点是否被遍历过
int p_num;//用于记录顶点数 

typedef struct graph_point Gpoint;//声明别名
typedef struct graph_line Gline;
typedef struct queue Q; 

int main(void)
{
	Gpoint g1[MAX];
	int creat_graph(Gpoint *g);
	void BFS_travel(Gpoint *g);
	p_num=creat_graph(g1);
	printf("广度优先搜索遍历结果为：\n");
	BFS_travel(g1);
	printf("\n");
	return 0;
} 


int creat_graph(Gpoint *g)
{
	int p_num,l_num,i,h,l;
	Gline *p;//作为结点空间 
	printf("请输入顶点数：");
	scanf("%d",&p_num);
	
	for (i=0;i<p_num;i++)
	{
		printf("请输入第%d个顶点的值：",i+1);
		scanf("%d",&(g+i)->point_num);
		(g+i)->next=NULL;
	} 
	
	printf("请输入边数：");
	scanf("%d",&l_num);
	
	for(i=0;i<l_num;i++)
	{
		//对于有向图而言，<V1,V2>和<V2,V1>是两种连通关系 
		//将输入的两个顶点的信息分解开来，变成两个邻接表的结点 
		
		printf("请输入第%d条边连接的两个顶点（Vi，Vj):",i+1);
		scanf("%d %d",&h,&l);
		
		//申请结点空间，若失败则退出 
		p=(Gline*)malloc(sizeof(Gline));
		if(p==NULL)
		{
			printf("error!");
			return 0; 
		}
		
	//头插法 
			
		//将该结点的next指针指向当前顶点指向的地址
		p->next=g[h].next;
		
		//邻接序号为l(l是h的邻接序号~） 
		p->line_point=l; 
		
		//将当前顶点的next指针指向p 
		(g+h)->next=p;
		
		//重复上面步骤将另一结点插入到另一对应顶点集元素
		p=(Gline*)malloc(sizeof(Gline));
		if(p==NULL)
		{
			printf("error!");
			return 0;
		}
		
		p->next=g[l].next;
		p->line_point=h;
		(g+l)->next=p;
	}
	
	printf("图构建完成!图中顶点为：\n");
	
	for(i=0;i<p_num;i++)
	{
		printf("%d ",(g+i)->point_num);
	} 
	
	printf("\n");
	printf("图中的连通关系为：\n"); 
	
	for(i=0;i<p_num;i++)
	{
		printf("第%d个顶点的值为%d",i+1,(g+i)->point_num);
		
		//如果存在邻接的顶点，则输出 
		if((g+i)->next!=NULL)
		{
			printf("\n");
			printf("与它邻接的顶点为：");
			p=(g+i)->next;
			
			while(p!=NULL)
			{
				printf("%d ",p->line_point);//line_point即与该顶点邻接的顶点的值 
				p=p->next;
			}
			printf("\n"); 
	    }
		
		else
		{
			printf("\n");
		} 
	}
	
	return p_num;//返回顶点数 
}


void BFS_travel(Gpoint *g)
{
	int i,k;
	Gline *p;
	Q *queue;
	Q *DeQueue(Q *queue,int *k);//出队列函数
	Q *EnQueue(Q *queue,int n);//入对列函数
	queue=NULL;
	
	for(i=0;i<p_num;i++)
	{
		visited[i]=0;//将所有顶点标记为未被遍历过 
	}
	
	//开始深度优先遍历 
	for (i=0;i<p_num;i++)
	{
		if(visited[i]==0)//若找到没被遍历的顶点
		{
			visited[i]=1;
			printf("%d",(g+i)->point_num);//输出该顶点内容
			queue=EnQueue(queue,i);
			
			while(1)
			{
				//从队列取出要遍历其所有邻接顶点的顶点
				queue=DeQueue(queue,&k);//&k作为指针传入，传入的是k的地址 
				
				if(k==-1)//如果队列已空，跳出循环
				{
					break;
				}
				
				p=(g+i)->next;//开始遍历该顶点的所有邻接点
				while(p!=NULL)
				{
					if(visited[p->line_point]==0)
					{
						visited[p->line_point]=1;
						printf("%d",p->line_point);
						queue=EnQueue(queue,p->line_point);
					}
					p=p->next;
				} 
			}	 
	 	} 
	}
}


//入队列函数
Q *EnQueue(Q *queue,int n)
{
	Q *previous,*last;
	
	if(queue==NULL)//如果队列为空，申请空间并赋值 
	{
		queue=(Q*)malloc(sizeof(Q));
		if(queue==NULL)
		{
			printf("error!");
			return NULL;
		}
		
		queue->num=n;
		queue->next=NULL;
		return queue;//返回队列头地址
	}
	
	else//如果不是空的，找到队列尾申请空间并赋值
	{
		last=queue;
		//找到队列尾 
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
		
		//对申请到的队尾空间进行处理 
		last->num=n;
		last->next=NULL;
		previous->next=last;
		return queue;//返回队列头地址 
	}
} 


//出队列函数
Q *DeQueue(Q *queue,int *k)
{
	Q *t;
	if(queue==NULL)
	{
		*k=-1;//若队列为空，则将*k赋值-1 
		return NULL;
	}
	
	*k=queue->num;//将顶点下角标赋值给*k;
	t=queue;
	queue=queue->next;
	free(t);
	return queue;//返回队列的新首地址 
 } 





 


