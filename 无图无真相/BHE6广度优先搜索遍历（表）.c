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

struct queue//�������н��
{
	int num;
	struct queue *next;
}; 

int visited[MAX];//���ڼ�¼�����Ƿ񱻱�����
int p_num;//���ڼ�¼������ 

typedef struct graph_point Gpoint;//��������
typedef struct graph_line Gline;
typedef struct queue Q; 

int main(void)
{
	Gpoint g1[MAX];
	int creat_graph(Gpoint *g);
	void BFS_travel(Gpoint *g);
	p_num=creat_graph(g1);
	printf("������������������Ϊ��\n");
	BFS_travel(g1);
	printf("\n");
	return 0;
} 


int creat_graph(Gpoint *g)
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
			return 0; 
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
			return 0;
		}
		
		p->next=g[l].next;
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
				printf("%d ",p->line_point);//line_point����ö����ڽӵĶ����ֵ 
				p=p->next;
			}
			printf("\n"); 
	    }
		
		else
		{
			printf("\n");
		} 
	}
	
	return p_num;//���ض����� 
}


void BFS_travel(Gpoint *g)
{
	int i,k;
	Gline *p;
	Q *queue;
	Q *DeQueue(Q *queue,int *k);//�����к���
	Q *EnQueue(Q *queue,int n);//����к���
	queue=NULL;
	
	for(i=0;i<p_num;i++)
	{
		visited[i]=0;//�����ж�����Ϊδ�������� 
	}
	
	//��ʼ������ȱ��� 
	for (i=0;i<p_num;i++)
	{
		if(visited[i]==0)//���ҵ�û�������Ķ���
		{
			visited[i]=1;
			printf("%d",(g+i)->point_num);//����ö�������
			queue=EnQueue(queue,i);
			
			while(1)
			{
				//�Ӷ���ȡ��Ҫ�����������ڽӶ���Ķ���
				queue=DeQueue(queue,&k);//&k��Ϊָ�봫�룬�������k�ĵ�ַ 
				
				if(k==-1)//��������ѿգ�����ѭ��
				{
					break;
				}
				
				p=(g+i)->next;//��ʼ�����ö���������ڽӵ�
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


//����к���
Q *EnQueue(Q *queue,int n)
{
	Q *previous,*last;
	
	if(queue==NULL)//�������Ϊ�գ�����ռ䲢��ֵ 
	{
		queue=(Q*)malloc(sizeof(Q));
		if(queue==NULL)
		{
			printf("error!");
			return NULL;
		}
		
		queue->num=n;
		queue->next=NULL;
		return queue;//���ض���ͷ��ַ
	}
	
	else//������ǿյģ��ҵ�����β����ռ䲢��ֵ
	{
		last=queue;
		//�ҵ�����β 
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
		
		//�����뵽�Ķ�β�ռ���д��� 
		last->num=n;
		last->next=NULL;
		previous->next=last;
		return queue;//���ض���ͷ��ַ 
	}
} 


//�����к���
Q *DeQueue(Q *queue,int *k)
{
	Q *t;
	if(queue==NULL)
	{
		*k=-1;//������Ϊ�գ���*k��ֵ-1 
		return NULL;
	}
	
	*k=queue->num;//�������½Ǳ긳ֵ��*k;
	t=queue;
	queue=queue->next;
	free(t);
	return queue;//���ض��е����׵�ַ 
 } 





 


