//��2����֮�������������1-100��������������Ҫ�������һ������ʵ�֡�
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
//�û������������֣����Ӹ�λ����ķ�ʽ���ҳ���2��������ͬλ�ô�����Ҳ��ͬ�ĸ�����
//���磺123 �� 5173 ��2�����֣�λ����ͬ����Ҳ��ͬ�ĸ����� 2

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