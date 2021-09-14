#define MAX 10
#include <stdio.h>

struct arr
{
	int next;
	int value;
};

typedef struct arr Link;
typedef Link*Lptr;

int main(void)
{
	Link link_list[MAX];
	void creat_link(Lptr link_list);
	link_list[0].next=1;
	creat_link(link_list);
	return 0;
} 

void creat_link(Lptr link_list)
{
	//结构体数组的第一个元素一直帮助构建静态链表。既用来给各点赋值和连接，又负责输出各结点内容
	//但它本身是不保存数据的，即不能被当做正常结点来用
	int i;
	for(i=1;i<MAX;i++)
	{
		scanf("%d",&(link_list[0].value));//读入数值(MAX-1)次 
		link_list[link_list[0].next].value=link_list[0].value;
		link_list[link_list[0].next].next=i+1;
		link_list[0].next=i+1; 
	}
	link_list[MAX-1].next=-1;//-1即代表最后一个结点指向NULL 
	link_list[0].next=1;
	printf("静态链表创建成功！链表内各结点数据为：\n");
	

	while(link_list[0].next!=-1)
	{
		link_list[0].value=link_list[link_list[0].next].value;
		link_list[0].next=link_list[link_list[0].next].next;
		printf("%d\n",link_list[0].value);
	} 
}
