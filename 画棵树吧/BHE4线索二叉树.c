#include <stdio.h>
#include <stdlib.h>

//声明作为线索二叉树的结点的结构体 
struct ltree 
{
	char data;
	int ltag;
	int rtag;
	struct ltree *lchild;
	struct ltree *rchild;
};

typedef struct ltree T;//声明别名
typedef T* Tptr;

//定义全局变量，该指针用于记录当前被遍历的结点的上一个结点的地址
Tptr previous;


int main(void)
{
	Tptr head;
	Tptr pre_order_ltree(Tptr t);//线索二叉树构建函数
	//线索化函数，由于前驱和后继的信息只有在遍历该二叉树时才能得到，所以线索化的过程就是在遍历的过程中修改空指针的过程！
	void pre_order_ltree_travel_link(Tptr t);
	Tptr pre_order_ltree_travel(Tptr t);//前序遍历函数
	
	previous=NULL;
	head=pre_order_ltree(head);
	pre_order_ltree_travel_link(head);
	
	printf("二叉树线索化完毕！该线索二叉树内容为：\n");
	pre_order_ltree_travel(head);
	
	return 0; 
} 


//二叉树前序构建函数具体实现
Tptr pre_order_ltree(Tptr t)
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
		
		//当前左右子树指针均不是线索，所以赋值0
		t->ltag=t->rtag=0;
		
		//前序构建当前结点左右子树 
		t->lchild=pre_order_ltree(t->lchild);
		t->rchild=pre_order_ltree(t->rchild);
		return t;
	}
} 


void pre_order_ltree_travel_link(Tptr t)
{
	//如果该指针为空，返回 
	if(t==(NULL))
	{
		return;
	}
	
	//否则判断该结点的lchild指针是否为空 
	if(t->lchild==NULL)
	{
		//为空则将上一个被遍历的结点地址复制给lchild指针（完成t指向previous，t的前驱线索）
		t->lchild=previous;
		//并将该结点的ltag标签赋值1，表示该左子树指针是一条线索 
		t->ltag=1; 
	}


	//判断是否有上一个被遍历的结点
	if(previous!=NULL)
	{
		//再判断该结点的右子树指针是否为空
		if(previous->rchild==NULL)
		{
			//为空则将该结点rtag赋值1，表示时线索
			previous->rtag=1;
			//将当前被遍历的结点的地址复制给这个右子树指针(完成previous指向t，previous的后继线索） 
			previous->rchild=t; 
		} 
	}
	
	//将当前结点地址赋值给previous指针，作为遍历下一个结点时的前一个结点地址 
	previous=t; 
	
	//如果该结点左子树指针不是线索，前序递归遍历 
	if(t->ltag==0) 
	{
		pre_order_ltree_travel_link(t->lchild);
	}
	
	//如果该结点右子树指针不是线索，前序递归遍历
	{
		pre_order_ltree_travel_link(t->rchild);
	}
}


//前序线索二叉树遍历函数
Tptr pre_order_ltree_travel(Tptr t) 
{ 
	if(t==NULL)
	{
		return NULL;
	}
	
	printf("当前结点内容为：%c\n",t->data);
	
	//如果当前结点左子树指针是线索，输出上一个结点的信息
	if(t->ltag==1)
	{
		printf("它的上一个结点内容是：");
		
		if(t->lchild==NULL)
		{
			printf("该结点已是根节点"); 
		} 
		
		else
		{
			printf("%c\n",t->lchild->data); 
	    }
    } 
	
	//如果当前结点的右子树指针是线索，输出上一个结点的信息
	if (t->rtag==1)
	{
		printf("它的下一个结点内容是：");
		
		if(t->rchild==NULL)
		{
			printf("该结点已是最后的叶子节点"); 
		} 
		
		else
		{
			printf("%c\n",t->rchild->data); 
	    }
	}
	
	//如果当前结点的左子树指针不是线索，就正常继续递归遍历
	if(t->ltag==0)
	{
		pre_order_ltree_travel(t->lchild);
	}
	
	//如果当前结点的右子树指针不是线索，就正常继续递归遍历
	if(t->rtag==0)
	{
		pre_order_ltree_travel(t->rchild);
	}
} 
