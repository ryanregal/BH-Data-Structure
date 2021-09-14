#include <stdio.h>
#include <stdlib.h>

struct tree//声明作为树结点的结构体
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
	Tptr pre_order_tree(Tptr t);//声明前序构建二叉树函数
	Tptr btree_copy(Tptr t);//声明二叉树复制函数
	void pre_order_tree_travel(Tptr t);//声明前序遍历二叉树函数
	
	head1=pre_order_tree(head1);
	printf("原二叉树内容：\n");
	pre_order_tree_travel(head1);
	printf("\n");
	
	head2=btree_copy(head1);
	printf("复制的二叉树内容：");
	pre_order_tree_travel(head2);
	printf("\n");
	return 0;
}


//二叉树前序构建函数具体实现
 Tptr pre_order_tree(Tptr t)
 {
 	char data;
	scanf("%c",&data);//从屏幕获取字符
	
	if(data=='#')
	{
		t=NULL;
		return t;//返回地址 
	}
	
	else//否则为该结点申请空间并进行赋值和递归构建
	{
		t=(Tptr)malloc(sizeof(T));
		if(t==NULL)
		{
			printf("error!");
			return NULL;
		}
		
		t->data=data;//赋值
		//对其左右子树继续进行递归构建
		t->lchild=pre_order_tree(t->lchild);
		t->rchild=pre_order_tree(t->rchild);
		return t;//返回结点地址
	}
}

//二叉树复制函数
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
		
		//开始复制 
		t1->data=t->data;
		t1->lchild=btree_copy(t->lchild);
		t1->rchild=btree_copy(t->rchild);
		return t1;
	} 
}

//二叉树前序遍历函数实现
void pre_order_tree_travel(Tptr t)
{
	//如果该结点为空直接返回
	if(t==NULL)
	{
		return;
	}
	printf("%c",t->data);
	pre_order_tree_travel(t->lchild);
	pre_order_tree_travel(t->rchild);
}

