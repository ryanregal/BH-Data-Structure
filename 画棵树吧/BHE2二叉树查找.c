#include <stdio.h>
#include <stdlib.h>

//������Ϊ�����Ľṹ�� 
struct tree
{
	char data;
	struct tree *lchild;
	struct tree *rchild;
};

typedef struct tree T; 
typedef T *Tptr;

int main(void)
{
	Tptr head;
	char find;
	int num,num1;
	Tptr pre_order_tree(Tptr t);//������ǰ�򹹽���������
	int pre_order_tree_travel_find(Tptr t,int num,char find);
	void btreefind(Tptr t,int num1,char find); 
	
	num=0;
	num1=0;//���ڼ�¼�������Ľ�����
	find='7';//����Ҫ���ҵ�����Ϊ7 
	head=pre_order_tree(head);//ǰ�򹹽�������
	
	pre_order_tree_travel_find(head,num,find);//ǰ�����������
	btreefind(head,num1,find);//���������������
	
	return 0;
}
 
//������ǰ�򹹽���������ʵ��
Tptr pre_order_tree(Tptr t)
{
	char data;
	scanf("%c",&data);
	if (data=='#')
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
		return t;
	}
} 

//������ǰ��������Һ���ʵ��
int pre_order_tree_travel_find(Tptr t, int num,char find)
{
	if(t==NULL)//����ý��Ϊ����ֱ�ӷ���
	{
		return num;
	}
	
	if(t->data==find)
	{
		printf("�ҵ��˸ý�㣬�ܹ�������%d�����\n",num);
		return 0;	
	}
	
	else
	{
		num++;
		//ǰ������ý�����������
		num=pre_order_tree_travel_find(t->lchild,num,find);
		num=pre_order_tree_travel_find(t->rchild,num,find);
		return num; 
	}
}

//��������������� 
void btreefind(Tptr t,int num1,char find)
{
	while(t!=NULL)
	{
		if(t->data==find)
		{
			printf("�ҵ��˸ý�㣬�ܹ�������%d�����\n",num1);
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
}
