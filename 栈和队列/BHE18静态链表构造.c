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
	//�ṹ������ĵ�һ��Ԫ��һֱ����������̬���������������㸳ֵ�����ӣ��ָ���������������
	//���������ǲ��������ݵģ������ܱ����������������
	int i;
	for(i=1;i<MAX;i++)
	{
		scanf("%d",&(link_list[0].value));//������ֵ(MAX-1)�� 
		link_list[link_list[0].next].value=link_list[0].value;
		link_list[link_list[0].next].next=i+1;
		link_list[0].next=i+1; 
	}
	link_list[MAX-1].next=-1;//-1���������һ�����ָ��NULL 
	link_list[0].next=1;
	printf("��̬�������ɹ��������ڸ��������Ϊ��\n");
	

	while(link_list[0].next!=-1)
	{
		link_list[0].value=link_list[link_list[0].next].value;
		link_list[0].next=link_list[link_list[0].next].next;
		printf("%d\n",link_list[0].value);
	} 
}
