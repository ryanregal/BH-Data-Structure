#include <stdio.h>
#include <stdlib.h>

//声明作为树结点的结构体 
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
	Tptr pre_order_tree(Tptr t);//二叉树前序构建函数声明
	void mid_order_tree_travel(Tptr t);
	int btreefind(Tptr t,int num1,int find); 
	Tptr insert(Tptr t,int find);
	
	num=0; 
	head=pre_order_tree(head);//前序构建二叉树
	
	printf("请输入要查找的内容：");
	scanf("%d",&find);
	
	re=btreefind(head,num,find);//二叉查找树法查找
	if(re==-1)
	{
		insert(head,find);
		printf("当前该树内容为：\n");
		mid_order_tree_travel(head); 
	}
	
	return 0;
}
 
 
//二叉树前序构建函数具体实现
Tptr pre_order_tree(Tptr t)
{
	int data;
	
	scanf("%d",&data);
	if (data==0)
	{
		t=NULL;
		return t;
	}
	
	//否则为该结点申请空间并进行赋值和递归构建 
	else
	{
		t=(Tptr)malloc(sizeof(T));
		if(t==NULL)
		{
			printf("error!");
			return NULL;
		}
		
		t->data=data;//赋值
		t->lchild=pre_order_tree(t->lchild);
		t->rchild=pre_order_tree(t->rchild);

		return t;//返回结点地址 
	}
} 


//二叉查找树函数！ 
int btreefind(Tptr t,int num1,int find)
{
	int flag=0;
	
	while(t!=NULL)
	{
		if(t->data==find)
		{
			printf("找到了该结点，总共遍历了%d个结点\n",num1);
			flag++;
			break; 
		}
		
		//否则判断当前结点数据与要找的数据谁大谁小 
		else
		{
			num1++;//记录遍历的结点+1
			
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
	
	if(flag==0)//没有找到结点
	{
		printf("未找到该结点！\n");
		return -1; 
	}
	
	return 0;//找到返回0 
}


//插入函数 
//递归函数 
Tptr insert(Tptr t,int find)//传入根节点地址和要查找的find 
{
	if(t==NULL)//如果当前节点为空，执行插入操作 
	{
		t=(Tptr)malloc(sizeof(T));
		if(t==NULL)
		{
			printf("error!");
			return NULL;
		}
		
		t->lchild=t->rchild=NULL;
		t->data=find;
		printf("已成功将该数据插入到二叉查找树~\n");
		return t;//将插入结点地址返回
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


//二叉树中序遍历函数实现（左根右） 
void mid_order_tree_travel(Tptr t)
{
	//如果该结点为空直接返回
	if(t==NULL)
	{
		return;
	}

	mid_order_tree_travel(t->lchild);
	printf("%d ",t->data);
	mid_order_tree_travel(t->rchild);
}


