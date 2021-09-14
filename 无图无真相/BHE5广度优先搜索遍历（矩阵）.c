#include <stdlib.h> 
#include <stdio.h>
#define MAX 100

struct graph
{
	int point[MAX];//�����
	int line [MAX][MAX];//�ڽӾ���Ҳ�Ʊ߱�
	int point_num;//���ڼ�¼�û�����Ķ�����
	int line_num;//���ڼ�¼�û�����ı��� 
};


//�������н�� 
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
	
	printf("��ȱ���˳��Ϊ��\n");
	BFS_travel(&g1); 
	printf("\n");
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


//������������������� 
void BFS_travel(Gptr g)
{
	int i,j,k;
	Q *queue;
	Q *DeQueue(Q *queue,int *k);//�����к��� 
	Q *EnQueue(Q *queue,int n);//����к���
	queue=NULL;
	
	//�����ж�����Ϊδ�������� 
	for(i=0;i<g->point_num;i++)
	{
		visited[i]=0;
	}
	
	//��ʼ����
	for(i=0;i<g->point_num;i++)
	{
		//�ҵ�û�������Ķ��� 
		if(visited[i]==0)
		{
			visited[i]=1;//��Ϊ�ѱ���
			printf("%d",g->point[i]);//�������
			queue=EnQueue(queue,i);//���������
			
			//�������������ڽӶ��� 
			while(1) 
			{
				//�Ӷ���ȡ��Ҫ�����������ڽӶ���Ķ���
				queue=DeQueue(queue,&k);
				
				//��������ѿգ�����ѭ��(k�ǳ����к����ķ���ֵ�� 
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
						
						//��������������Ա��¼������� 
					}
				}
	 		} 
		} 
	} 
} 


//����к��� 
Q *EnQueue(Q *queue,int n)
{
	Q *previous,*last;
	
	//��������ǿյģ�����ռ䲢��ֵ 
	if(queue==NULL)
	{
		queue=(Q*)malloc(sizeof(Q));
		if(queue==NULL)
		{
			printf("error!");
			return NULL;
		}
		
		queue->num=n;//n����BFS���������i
		queue->next=NULL;
		return queue;//���ض���ͷ��ַ 
	} 
	
	//������ǿյģ��ҵ�����β����ռ䲢��ֵ 
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
		return queue;//���ض���ͷ��ַ 
	} 
} 


//�����к���,�����k�ǳ�ʼֵ 
Q *DeQueue(Q *queue,int *k)	
{
	Q *t;
	
	//������Ϊ�գ���*k��ֵΪ-1 
	if (queue==NULL)
	{
		*k=-1;
		return NULL; 
	}
	
	*k=queue->num;//�������½Ǳ�ֵ����*k
	t=queue;
	queue=queue->next;
	free(t);
	return queue;//���ض��е����׵�ַ������	
} 
	
	
	
	
	
	
	
	
	
	
	
	 
