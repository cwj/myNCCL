//编写一个程序，统计各个数字，空白字符和其他所有字符出现的次数，以及行数。
//分析一条格式化打印语句中，打印整数%d，字符%c，字符串%s，地址%p 
//各自出现的次数。

#include <stdio.h>

void countstr(char ch)
{
	int a[37];
}

int main(void)
{
	int i;
	char str[100];

	printf("input a string");
	scanf("%s",str);
	
	i=0;
	while (str[i]!='\0')
	{
		countstr(str[i]);
	}

	return 0;
}

