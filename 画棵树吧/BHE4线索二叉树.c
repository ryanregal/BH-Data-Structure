#include <stdio.h>
#include <stdlib.h>

//������Ϊ�����������Ľ��Ľṹ�� 
struct ltree 
{
	char data;
	int ltag;
	int rtag;
	struct ltree *lchild;
	struct ltree *rchild;
};

typedef struct ltree T;//��������
typedef T* Tptr;

//����ȫ�ֱ�������ָ�����ڼ�¼��ǰ�������Ľ�����һ�����ĵ�ַ
Tptr previous;


int main(void)
{
	Tptr head;
	Tptr pre_order_ltree(Tptr t);//������������������
	//����������������ǰ���ͺ�̵���Ϣֻ���ڱ����ö�����ʱ���ܵõ��������������Ĺ��̾����ڱ����Ĺ������޸Ŀ�ָ��Ĺ��̣�
	void pre_order_ltree_travel_link(Tptr t);
	Tptr pre_order_ltree_travel(Tptr t);//ǰ���������
	
	previous=NULL;
	head=pre_order_ltree(head);
	pre_order_ltree_travel_link(head);
	
	printf("��������������ϣ�����������������Ϊ��\n");
	pre_order_ltree_travel(head);
	
	return 0; 
} 


//������ǰ�򹹽���������ʵ��
Tptr pre_order_ltree(Tptr t)
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
		
		//��ǰ��������ָ����������������Ը�ֵ0
		t->ltag=t->rtag=0;
		
		//ǰ�򹹽���ǰ����������� 
		t->lchild=pre_order_ltree(t->lchild);
		t->rchild=pre_order_ltree(t->rchild);
		return t;
	}
} 


void pre_order_ltree_travel_link(Tptr t)
{
	//�����ָ��Ϊ�գ����� 
	if(t==(NULL))
	{
		return;
	}
	
	//�����жϸý���lchildָ���Ƿ�Ϊ�� 
	if(t->lchild==NULL)
	{
		//Ϊ������һ���������Ľ���ַ���Ƹ�lchildָ�루���tָ��previous��t��ǰ��������
		t->lchild=previous;
		//�����ý���ltag��ǩ��ֵ1����ʾ��������ָ����һ������ 
		t->ltag=1; 
	}


	//�ж��Ƿ�����һ���������Ľ��
	if(previous!=NULL)
	{
		//���жϸý���������ָ���Ƿ�Ϊ��
		if(previous->rchild==NULL)
		{
			//Ϊ���򽫸ý��rtag��ֵ1����ʾʱ����
			previous->rtag=1;
			//����ǰ�������Ľ��ĵ�ַ���Ƹ����������ָ��(���previousָ��t��previous�ĺ�������� 
			previous->rchild=t; 
		} 
	}
	
	//����ǰ����ַ��ֵ��previousָ�룬��Ϊ������һ�����ʱ��ǰһ������ַ 
	previous=t; 
	
	//����ý��������ָ�벻��������ǰ��ݹ���� 
	if(t->ltag==0) 
	{
		pre_order_ltree_travel_link(t->lchild);
	}
	
	//����ý��������ָ�벻��������ǰ��ݹ����
	{
		pre_order_ltree_travel_link(t->rchild);
	}
}


//ǰ��������������������
Tptr pre_order_ltree_travel(Tptr t) 
{ 
	if(t==NULL)
	{
		return NULL;
	}
	
	printf("��ǰ�������Ϊ��%c\n",t->data);
	
	//�����ǰ���������ָ���������������һ��������Ϣ
	if(t->ltag==1)
	{
		printf("������һ����������ǣ�");
		
		if(t->lchild==NULL)
		{
			printf("�ý�����Ǹ��ڵ�"); 
		} 
		
		else
		{
			printf("%c\n",t->lchild->data); 
	    }
    } 
	
	//�����ǰ����������ָ���������������һ��������Ϣ
	if (t->rtag==1)
	{
		printf("������һ����������ǣ�");
		
		if(t->rchild==NULL)
		{
			printf("�ý����������Ҷ�ӽڵ�"); 
		} 
		
		else
		{
			printf("%c\n",t->rchild->data); 
	    }
	}
	
	//�����ǰ����������ָ�벻�������������������ݹ����
	if(t->ltag==0)
	{
		pre_order_ltree_travel(t->lchild);
	}
	
	//�����ǰ����������ָ�벻�������������������ݹ����
	if(t->rtag==0)
	{
		pre_order_ltree_travel(t->rchild);
	}
} 
