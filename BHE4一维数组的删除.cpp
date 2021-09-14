#include <stdio.h>
#include <stdlib.h>

//main函数 
int main(void)
{
	int num1,num2,i,re;
	//num1定义学生人数 
	int*p;
	int delete1(int num1,int num2,int*p);
	//要提前定义delete1函数 
	
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
	
printf("请输入要删除的学生编号：");
//用户输入
scanf("%d",&num2);
re=delete1(num1,num2,p);
num1=re;
//更新当前数组长度
printf("删除成功！剩余学生编号及成绩为：\n");
for(i=0;i<num1;i++)
{
	printf("第%d个学生成绩为%d\n",i+1,*(p+i));
 } 
free(p);
return 0;
}

//定义delete函数
//1.覆盖数据
//2.更改长度 

int delete1(int num1,int num2,int*p)
{
	int i,j;
	for (i=0;i<num1;i++)
	{
		if (i==num2-1)
		{
			for(j=i;j<num1-1;j++)
			{
				*(p+j)=*(p+j+1);//覆盖数据 
			}
			break;//提前跳出for循环提高效率 
		}
	}
	return num1-1; 
}
