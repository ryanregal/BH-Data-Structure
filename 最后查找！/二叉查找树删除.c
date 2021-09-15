#include <stdio.h>
#include <stdlib.h>

//������Ϊ�����Ľṹ�� 
struct tree
{
	int data;
	struct tree *lchild;
	struct tree *rchild;
};

typedef struct tree T; 
typedef T *Tptr;

int main(void)
{
	Tptr head;
	int num;
	Tptr pre_order_tree(Tptr t);//������ǰ�򹹽���������
	void mid_order_tree_travel(Tptr t);
	void t_delete(Tptr t,int num); 
	
	head=pre_order_tree(head);
	printf("��ǰ��������Ϊ��\n"); 
	mid_order_tree_travel(head);
	printf("\n");
	
	printf("������Ҫɾ��������");
	scanf("%d",&num);
	t_delete(head,num);
	
	printf("ɾ�������е�����Ϊ��\n");
	mid_order_tree_travel(head); 
	
	return 0;
}
 
 
//������ǰ�򹹽���������ʵ��
Tptr pre_order_tree(Tptr t)
{
	int data;
	
	scanf("%d",&data);

	if (data==0)
	{
		t=NULL;
		return t;
	}
	
	//����Ϊ�ý������ռ䲢���и�ֵ�͵ݹ鹹�� 
	else
	{
		t=(Tptr)malloc(sizeof(T));

		if(t==NULL)
		{
			printf("error!");
			return NULL;
		}
		
		t->data=data;//��ֵ
		t->lchild=pre_order_tree(t->lchild);
		t->rchild=pre_order_tree(t->rchild);

		return t;//���ؽ���ַ 
	}
} 


//�����������������ʵ�֣�����ң� 
void mid_order_tree_travel(Tptr t)
{
	//����ý��Ϊ��ֱ�ӷ���
	if(t==NULL)
	{
		return;
	}

	mid_order_tree_travel(t->lchild);
	printf("%d ",t->data);
	mid_order_tree_travel(t->rchild);
}


void t_delete(Tptr t,int num)
{
	Tptr previous1,previous2,temp;
	previous1=previous2=temp=NULL;
	
	//����Ҫɾ��������
	
	while(t!=NULL)
	{
		if(t->data==num)//����ҵ������������
		{
			break;
		}
		
		else//�����жϵ�ǰ���������Ҫ�ҵ�����˭��˭С
		{
			//���Ҫ�ҵ����ݴ󣬽������ҵ�ǰ����������,��ǰ�����pre1�ݴ�
			if(num>t->data)
			{
				previous1=t;
				t=t->rchild;
			}
			
			else//��������������
			{
				previous1=t;
				t=t->lchild;
			}
		}			
	}
	
	//���Ҫɾ������Ҷ�ӽ��
	if(t->rchild==NULL&&t->lchild==NULL)
	{
		//�жϸý����˫�׽������ӻ����Һ��ӣ����Һ�����˫�׽����Һ���ָ�����¸�ֵ
		if(previous1->rchild==t)
		{
			previous1->rchild=NULL;
			free(t);
		}
		
		else//����ͽ�˫�׽�������ָ�����¸�ֵ
		{
			previous1->lchild=NULL;
			free(t);
		}	
	}
	
	//���Ҫɾ���Ľ��ֻ������
	else if(t->rchild==NULL)
	{
		//�жϸý����˫�׽������ӻ����Һ���
		if(previous1->rchild==t)
		{
			previous1->rchild=t->lchild;
			free(t);
		}
		
		else//����ͽ�˫�׽�������ָ�����¸�ֵ
		{
			previous1->lchild=t->lchild;
			free(t);
		}	
	}
	
	//���Ҫɾ���Ľ��ֻ���Һ���
	else if(t->lchild==NULL)
	{
		//�жϸý����˫�׽������ӻ����Һ���
		if(previous1->rchild==t)
		{
			previous1->rchild=t->rchild;
			free(t);
		}
		
		else//����ͽ�˫�׽�������ָ�����¸�ֵ
		{
			previous1->lchild=t->rchild;
			free(t);
		}	
	}
	
	else//�����������Ҳ���Һ���
	{
		temp=t->lchild;
		
		//�������������������ҵĽ��
		while(temp->rchild!=NULL)
		{
			previous2=temp;
			temp=temp->rchild;
		}
		
		//���ޣ���Ѱ�����Һ��������Ƿ���������
		if(temp=t->lchild) 
		{
			temp=t->rchild;
		
			//�������������������ҵĽ��
			while(temp->lchild!=NULL)
			{
				previous2=temp;
				temp=temp->lchild;
			}
		
		
			//�������û�У���ֱ�ӽ��ý���Һ�����Ϊ����������滻
			if(temp==t->rchild)
			{
				t->rchild=t->rchild->rchild;
				t->data=t->rchild->data;
				free(temp); 
			} 
			
			//����������㣬�����������滻 
			else
			{
				previous2->lchild=NULL;
				t->data=temp->data;
				free(temp);
			}
		}
		
		else//��������ҽ�㣬ֱ���滻
		{
			previous2->rchild=NULL;
			t->data=temp->data;
			free(temp); 
		}
	}
}
