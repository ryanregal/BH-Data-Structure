#include <stdio.h>
#include <stdlib.h>

struct tree//������Ϊ�����Ľṹ��
{
	char data;
	struct tree *lchild;
	struct tree *rchild;
};

typedef struct tree T;
typedef T *Tptr;

int main(void)
{
	Tptr head1,head2;
	Tptr pre_order_tree(Tptr t);//����ǰ�򹹽�����������
	Tptr btree_copy(Tptr t);//�������������ƺ���
	void pre_order_tree_travel(Tptr t);//����ǰ���������������
	
	head1=pre_order_tree(head1);
	printf("ԭ���������ݣ�\n");
	pre_order_tree_travel(head1);
	printf("\n");
	
	head2=btree_copy(head1);
	printf("���ƵĶ��������ݣ�");
	pre_order_tree_travel(head2);
	printf("\n");
	return 0;
}


//������ǰ�򹹽���������ʵ��
 Tptr pre_order_tree(Tptr t)
 {
 	char data;
	scanf("%c",&data);//����Ļ��ȡ�ַ�
	
	if(data=='#')
	{
		t=NULL;
		return t;//���ص�ַ 
	}
	
	else//����Ϊ�ý������ռ䲢���и�ֵ�͵ݹ鹹��
	{
		t=(Tptr)malloc(sizeof(T));
		if(t==NULL)
		{
			printf("error!");
			return NULL;
		}
		
		t->data=data;//��ֵ
		//�������������������еݹ鹹��
		t->lchild=pre_order_tree(t->lchild);
		t->rchild=pre_order_tree(t->rchild);
		return t;//���ؽ���ַ
	}
}

//���������ƺ���
Tptr btree_copy(Tptr t)
{
	Tptr t1;
	if(t==NULL)
	{
		return NULL;
	}
	else
	{
		t1=(Tptr)malloc(sizeof(T));
		if(t1==NULL)
		{
			printf("error!!!!!!");
			return NULL;
		}
		
		//��ʼ���� 
		t1->data=t->data;
		t1->lchild=btree_copy(t->lchild);
		t1->rchild=btree_copy(t->rchild);
		return t1;
	} 
}

//������ǰ���������ʵ��
void pre_order_tree_travel(Tptr t)
{
	//����ý��Ϊ��ֱ�ӷ���
	if(t==NULL)
	{
		return;
	}
	printf("%c",t->data);
	pre_order_tree_travel(t->lchild);
	pre_order_tree_travel(t->rchild);
}

