#include <stdio.h>
#include <stdlib.h>

//声明作为树结点的结构体 
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
	Tptr pre_order_tree(Tptr t);//二叉树前序构建函数声明
	int pre_order_tree_travel_find(Tptr t,int num,char find);
	void btreefind(Tptr t,int num1,char find); 
	
	num=0;
	num1=0;//用于记录遍历过的结点个数
	find='7';//假设要查找的数据为7 
	head=pre_order_tree(head);//前序构建二叉树
	
	pre_order_tree_travel_find(head,num,find);//前序遍历法查找
	btreefind(head,num1,find);//二叉查找树法查找
	
	return 0;
}
 
//二叉树前序构建函数具体实现
Tptr pre_order_tree(Tptr t)
{
	char data;
	scanf("%c",&data);
	if (data=='#')
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
		return t;
	}
} 

//二叉树前序遍历查找函数实现
int pre_order_tree_travel_find(Tptr t, int num,char find)
{
	if(t==NULL)//如果该结点为空则直接返回
	{
		return num;
	}
	
	if(t->data==find)
	{
		printf("找到了该结点，总共遍历了%d个结点\n",num);
		return 0;	
	}
	
	else
	{
		num++;
		//前序遍历该结点的左右子树
		num=pre_order_tree_travel_find(t->lchild,num,find);
		num=pre_order_tree_travel_find(t->rchild,num,find);
		return num; 
	}
}

//二叉查找树函数！ 
void btreefind(Tptr t,int num1,char find)
{
	while(t!=NULL)
	{
		if(t->data==find)
		{
			printf("找到了该结点，总共遍历了%d个结点\n",num1);
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
}
