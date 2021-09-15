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
	int re,num,find;
	Tptr pre_order_tree(Tptr t);//������ǰ�򹹽���������
	void mid_order_tree_travel(Tptr t);
	int btreefind(Tptr t,int num1,int find); 
	Tptr insert(Tptr t,int find);
	
	num=0; 
	head=pre_order_tree(head);//ǰ�򹹽�������
	
	printf("������Ҫ���ҵ����ݣ�");
	scanf("%d",&find);
	
	re=btreefind(head,num,find);//���������������
	if(re==-1)
	{
		insert(head,find);
		printf("��ǰ��������Ϊ��\n");
		mid_order_tree_travel(head); 
	}
	
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


//��������������� 
int btreefind(Tptr t,int num1,int find)
{
	int flag=0;
	
	while(t!=NULL)
	{
		if(t->data==find)
		{
			printf("�ҵ��˸ý�㣬�ܹ�������%d�����\n",num1);
			flag++;
			break; 
		}
		
		//�����жϵ�ǰ���������Ҫ�ҵ�����˭��˭С 
		else
		{
			num1++;//��¼�����Ľ��+1
			
			if(find>t->data)
			{
				t=t->rchild;
			}
			
			else
			{
				t=t->lchild;
			}
	 	}
	}
	
	if(flag==0)//û���ҵ����
	{
		printf("δ�ҵ��ý�㣡\n");
		return -1; 
	}
	
	return 0;//�ҵ�����0 
}


//���뺯�� 
//�ݹ麯�� 
Tptr insert(Tptr t,int find)//������ڵ��ַ��Ҫ���ҵ�find 
{
	if(t==NULL)//�����ǰ�ڵ�Ϊ�գ�ִ�в������ 
	{
		t=(Tptr)malloc(sizeof(T));
		if(t==NULL)
		{
			printf("error!");
			return NULL;
		}
		
		t->lchild=t->rchild=NULL;
		t->data=find;
		printf("�ѳɹ��������ݲ��뵽���������~\n");
		return t;//���������ַ����
	}
	
	else if(find>t->data)
	{
		t->rchild=insert(t->rchild,find);
		return t;
	}
	
	else
	{
		t->lchild=insert(t->lchild,find);
		return t;
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


