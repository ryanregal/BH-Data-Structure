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
	int num;
	Tptr pre_order_tree(Tptr t);//二叉树前序构建函数声明
	void mid_order_tree_travel(Tptr t);
	void t_delete(Tptr t,int num); 
	
	head=pre_order_tree(head);
	printf("当前树中内容为：\n"); 
	mid_order_tree_travel(head);
	printf("\n");
	
	printf("请输入要删除的内容");
	scanf("%d",&num);
	t_delete(head,num);
	
	printf("删除后树中的内容为：\n");
	mid_order_tree_travel(head); 
	
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


void t_delete(Tptr t,int num)
{
	Tptr previous1,previous2,temp;
	previous1=previous2=temp=NULL;
	
	//查找要删除的数据
	
	while(t!=NULL)
	{
		if(t->data==num)//如果找到，则结束查找
		{
			break;
		}
		
		else//否则判断当前结点数据与要找的数据谁大谁小
		{
			//如果要找的数据大，接下来找当前结点的右子树,当前结点用pre1暂存
			if(num>t->data)
			{
				previous1=t;
				t=t->rchild;
			}
			
			else//否则则找左子树
			{
				previous1=t;
				t=t->lchild;
			}
		}			
	}
	
	//如果要删除的是叶子结点
	if(t->rchild==NULL&&t->lchild==NULL)
	{
		//判断该结点是双亲结点的左孩子还是右孩子，是右孩子则将双亲结点的右孩子指针重新赋值
		if(previous1->rchild==t)
		{
			previous1->rchild=NULL;
			free(t);
		}
		
		else//否则就将双亲结点的左孩子指针重新赋值
		{
			previous1->lchild=NULL;
			free(t);
		}	
	}
	
	//如果要删除的结点只有左孩子
	else if(t->rchild==NULL)
	{
		//判断该结点是双亲结点的左孩子还是右孩子
		if(previous1->rchild==t)
		{
			previous1->rchild=t->lchild;
			free(t);
		}
		
		else//否则就将双亲结点的左孩子指针重新赋值
		{
			previous1->lchild=t->lchild;
			free(t);
		}	
	}
	
	//如果要删除的结点只有右孩子
	else if(t->lchild==NULL)
	{
		//判断该结点是双亲结点的左孩子还是右孩子
		if(previous1->rchild==t)
		{
			previous1->rchild=t->rchild;
			free(t);
		}
		
		else//否则就将双亲结点的左孩子指针重新赋值
		{
			previous1->lchild=t->rchild;
			free(t);
		}	
	}
	
	else//如果既有左孩子也有右孩子
	{
		temp=t->lchild;
		
		//查找左孩子子树有无最右的结点
		while(temp->rchild!=NULL)
		{
			previous2=temp;
			temp=temp->rchild;
		}
		
		//若无，则寻找其右孩子子树是否有最左结点
		if(temp=t->lchild) 
		{
			temp=t->rchild;
		
			//查找左孩子子树有无最右的结点
			while(temp->lchild!=NULL)
			{
				previous2=temp;
				temp=temp->lchild;
			}
		
		
			//如果还是没有，就直接将该结点右孩子作为最左结点进行替换
			if(temp==t->rchild)
			{
				t->rchild=t->rchild->rchild;
				t->data=t->rchild->data;
				free(temp); 
			} 
			
			//如果有最左结点，则用最左结点替换 
			else
			{
				previous2->lchild=NULL;
				t->data=temp->data;
				free(temp);
			}
		}
		
		else//如果有最右结点，直接替换
		{
			previous2->rchild=NULL;
			t->data=temp->data;
			free(temp); 
		}
	}
}
