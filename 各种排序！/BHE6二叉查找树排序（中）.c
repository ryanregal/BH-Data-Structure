#include <stdio.h>
#include <stdlib.h>

//声明作为树节点的结构体 
struct tree
{
	char data;
	struct tree *lchild;
	struct tree *rchild;
};

typedef struct tree T;//声明别名 
typedef T*Tptr;

int main(void)
{
	Tptr head;
	Tptr pre_order_tree(Tptr t);//二叉树前序构建函数声明
	void mid_order_tree_travel(Tptr t);//二叉树前序遍历函数声明
	
	head=pre_order_tree(head);
	mid_order_tree_travel(head);
	
	return 0; 
 }
 
 //二叉树前序构建函数具体实现(根左右） 
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

//二叉树中序遍历函数实现（左根右） 
void mid_order_tree_travel(Tptr t)
{
	//如果该结点为空直接返回
	if(t==NULL)
	{
		return;
	}

	mid_order_tree_travel(t->lchild);
	printf("%c",t->data);
	mid_order_tree_travel(t->rchild);
}


