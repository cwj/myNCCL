//找2个数之间最大素数。求1-100以内最大的素数，要求用设计一个函数实现。
#include <stdio.h>

int prime(int i)
{
	if (i%2==0)
	{
		return i;
	}
}


int main()
{
	int i,begin,end ,max;
	
	printf("input two number bigger than 0\n:");
	scanf("%d",&begin);
	scanf("%d",&end);
	
	if (begin>end)
	{
		begin=begin+end;
		end=begin-end;
		begin=begin-end;
	}
	
	max=0;
	for (i=begin ;i<=end ;i++ )
	{
		max=prime(i);
	}
	
	printf("the max prime is :%d\n ",max);
	
	return 0;
}
/*
input two number bigger than 0
:1
100
the max prime is :100
 [root@localhost nccl]# ./a.out
input two number bigger than 0
:1
55
the max prime is :54
*/


//***************************************************
//用户输入两个数字，按从个位对齐的方式，找出这2个数在相同位置处数字也相同的个数。
//例如：123 和 5173 这2个数字，位置相同数字也相同的个数是 2

#include <stdio.h>

int find(int i,int j)
{
	int m,n,count;

	count=0;
	do
	{
		m=i%10;
		n=j%10;
		if (m==n)
		{
			count++;
		}
		i=i/10;
		j=j/10;
	}
	while (i>0 && j>0);

	return count;
}

int main()
{
	int i,j,num;

	printf("input two number:\n");
	scanf("%d",&i);
	scanf("%d",&j);

	num=find(i,j);
  printf("have %d same number:\n",num);
	return 0;
}

/*
input two number:
123
1123
have 3 same number:
[root@localhost nccl]# ./a.out
input two number:
123
5173
have 2 same number:
[root@localhost nccl]#
*/