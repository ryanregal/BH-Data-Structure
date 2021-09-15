#include <stdio.h>
#include <stdlib.h>

//������Ϊ���ڵ�Ľṹ�� 
struct tree
{
	char data;
	struct tree *lchild;
	struct tree *rchild;
};

typedef struct tree T;//�������� 
typedef T*Tptr;

int main(void)
{
	Tptr head;
	Tptr pre_order_tree(Tptr t);//������ǰ�򹹽���������
	void mid_order_tree_travel(Tptr t);//������ǰ�������������
	
	head=pre_order_tree(head);
	mid_order_tree_travel(head);
	
	return 0; 
 }
 
 //������ǰ�򹹽���������ʵ��(�����ң� 
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

//�����������������ʵ�֣�����ң� 
void mid_order_tree_travel(Tptr t)
{
	//����ý��Ϊ��ֱ�ӷ���
	if(t==NULL)
	{
		return;
	}

	mid_order_tree_travel(t->lchild);
	printf("%c",t->data);
	mid_order_tree_travel(t->rchild);
}


