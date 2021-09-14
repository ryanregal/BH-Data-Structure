#include<stdio.h>
#include<stdlib.h>

//定义main函数 
int main(void)
{
	int num1,num2,num3,i,re,temp;
	//temp为乘sizeof的num 
	int*p;
	int insert1(int num1,int num2,int num3,int *p);
	printf("请输入学生人数");
	scanf("%d",&num1);
	temp=((num1/4)+1)*4;
	//多申请一点空间
	p=(int*)malloc(temp*sizeof(int));
	//动态申请空间创建数组
	
	if (p==NULL)
	{
		printf("wrong");
		return -1;
	 } 
	 
	for (i=0;i<num1;i++)
	{
		printf("请输入编号为%d的学生的成绩",i+1);
		scanf("%d",p+i);
	}
	
	printf("请输入要插入的学生编号：");
	scanf("%d",&num2);
	printf("请输入要插入的学生的成绩:");
	scanf("%d",&num3);
	re=insert1(num1,num2,num3,p);
	num1=re;
	//更新当前数组长度（即学生人数）
	
	printf("插入成功,学生编号为；\n");
	for (i=0;i<num1;i++)
	{
		printf("第%d个学生的成绩为%d\n",i+1,*(p+i));//p+i是储存成绩的地址 
	} 
	 return 0;
 } 
 
 //定义insert函数 
 int insert1(int num1,int num2,int num3,int*p)
 {
   int i,j,temp1,temp2;
   
   for(i=0;i<=num1;i++)
   {
   	if(i==num2-1)
   	{
   		temp1=*(p+i);//通过temp1暂时储存要插入位置原来值
		*(p+i)=num3;//数据插入 
		
		//将被插入位置后面的所有数组中元素都后移一位
		for(j=i;j<num1+1;j++)
		{
			temp2=*(p+j+1);//temp2储存被插入位后一位 
			*(p+j+1)=temp1;//后一位值被前一位取代 
			temp1=temp2; //更新前一位值，继续直到j=num+1 
		} 
		break;
		//操作完成，提前跳出for循环（最近循环/switch） 
	}
	} 
	return num1+1;//返回数组长度，避免遍历最后一个元素被忽略 
}
