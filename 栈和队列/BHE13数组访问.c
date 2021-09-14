#include<stdio.h>
#include<stdlib.h>

//main函数 
int main(void)
{
	int num1,num2,i,re;
	//num1定义学生人数 
	int*p;
	int search1(int num1,int num2,int*p);
	int search2(int num1,int num2,int*p);
	
	printf("请输入学生人数：");
	scanf("%d",&num1);
	
	p=(int*)malloc(num1*sizeof(int));
	// 动态申请空间创建数组
	
	if(p==NULL)
	{
		printf("wrong");
		return -1;
	}
	
	for (i=0;i<num1;i++)
	{
		printf("请输入编号为%d的学生成绩",i+1);
		scanf("%d",p+i);
	}
	
	printf("请选择要执行的操作：\n1.按编号查成绩\n2.按成绩查编号\n");
	//用户选择操作
	scanf("%d",&num2);
	
	if (num2==1)
	{
		printf("请输入要查询的学生编号");
		scanf("%d",&num2);
		re=search1(num1,num2,p);
		
		if(re==0)//判断是否找到 
		{
			printf("没有查找到该学生~\n"); 
		} 
		else 
		{
			printf("找到该学生，成绩为：%d\n",re);
		}
	}
	
	else if(num2==2)
	//执行search2函数
	{
		printf("请输入分数线：");
		scanf("%d",&num2);
		re=search2(num1,num2,p);
		if(re==0)//判断是否找到 
		{
			printf("没有查找到该学生~\n"); 
		} 
		else 
		{
			printf("找到该学生，成绩为：%d\n",re);
		}
    }
	free(p);
	//释放数组占用空间
	return 0; 
}

//search1函数，根据编号查成绩 
int search1(int num1,int num2,int*p)
{
	int i;
	for (i=0;i<num1;i++);
	{
		if(i==num2-1)
		{
			return *(p+i);
			//如找到编号，直接返回对应成绩 
		}
	}
	return 0;
} 

//search2函数，根据成绩查编号 
int search2(int num1,int num2,int*p)
{
	int i;
	for (i=0;i<num1;i++);
	{
		if(*(p+i)==num2)
		{
			return i+1;
			//如找到成绩，直接返回对应学生编号 
		}
	}
	return 0;
 } 

