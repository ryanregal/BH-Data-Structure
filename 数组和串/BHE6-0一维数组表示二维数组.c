#include<stdio.h>
int main(void)
{
	int a[3][3],b[9];
	int i,j,k,num1,num2,num3,real;
	printf("请输入3X3的数组内容：\n");
	
	for (i=0;i<3;i++)//二维数组赋值
	{
		for(j=0;j<3;j++)
		{
			scanf("%d",(*(a+i)+j));	
			//(a+i)相当于&a[i]（第i行地址），a[i]+j相当于a[i]偏移j个单位取引用取值得&(a[i][j]) 
		}
    }
    
    printf("请选择转换方法：\n1.以行为主\n2.以列为主\n");
	scanf("%d",&num1);
	
	//以行为主 
	if(num1==1)
	{
		k=0;//作为一位数组的下角标起始
		
		for (i=0;i<3;i++)
		{
			for (j=0;j<3;j++)
			{
				*(b+k)=*(*(a+i)+j);
				//把二维数组的值以行为主赋值给一维数组
				//b是一维数组b[9]的首地址，b+k即b[k]的地址，*(b+k)取b[k]值 
				//k初始0，二维数组初始a[0][0] 
				k++;
			}
		}
		
	printf("请输入要查询行数：");
	scanf("%d",&num2);
	printf("请输入要查询列数：");
	scanf("%d",&num3);
	real=3*(num2-1)+num3-1;
	
	printf("查询结果：%d\n",*(b+real)); 
	//*(b+real)相当于b[real] 
	} 
	
	else if(num1==2)
	{
		k==0;
		
		for (i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
				*(b+k)=*(*(a+j)+i);
				k++;
			}
		}
	
	printf("请输入要查询行数：");
	scanf("%d",&num2);
	printf("请输入要查询列数：");
	scanf("%d",&num3);
	real=3*(num3-1)+num2-1;
	
	printf("查询结果：%d\n",*(b+real)); 
	}
	
	return 0; 
 } 
