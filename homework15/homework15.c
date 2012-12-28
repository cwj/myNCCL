/*
请写出可以进行位操作的 set_bit, get_bit 接口
        set_bit(int num, int pos, int v);
        get_bit(int num, int pos);
*/

int get_bit(int num,int pos)
{
	int re;
	return re = (num>>pos) & ox1;
}

int set_bit(int num,int pos,int v)
{
	 if(v==1)
	 	{
	 		return num | 0x1<<pos;
	 	}
	 else if (v==0)
	 	{
	 		return num & (~(0x1<<pos)); //num 与上00001向左移pos位取反，则为类似111101111
	 	}
}

main(void)        
{
	int num;
	int pos;
	int v;
	int getbit,setbit;
	
	prinft("input a number:\n");
	scanf("%d",&num);
	
	printf("input a number small than 32");
	scanf("%d",&pos);
	
	getbit=get_bit(num,pos);
	
	scanf("o or 1",&v);
	
	setbit=set_bit(num,pos,v);
	
}


/*=============================homework15-2.c===================*/
/*
用位运算实现字符的大小写转换 （两种方法：异或，测试后修改）
要求：输入大写的字符转为小写，输入小写的字符转为大写；
*/

#include<stdio.h>

main(void)
{
	char inputc;
	char  outputi;
	
	printf("input a character");
	scanf("%c",&inputc);
	
	if(inputc>='a' && inputc<='z')
		{
			outputi=(char)((int)inputc >> 5);
			printf("%c",outputi);
		}
	else if (inputc>='A' && inputc<='Z')
		{
			outputi=(char)((int)inputc << 5);
			printf("%c",outputi);
		}
		
	return 0;
}


/*=====================homework15-3.c=========================*/
/*
用位运算实现对一个无符号整型的二进制打印，八进制打印，十六进制打印
        要求：
        int print_bin(int a);
        int print_oct(int a);
        int print_hex(int a);

    a = 31
    二进制打印 0000 0000 ... 0001 1111
    八进制打印 0 0 0 ... 0 3 7
    十六进制打印 00 00 00 1F
*/

#include<stdio.h>

void print_bin(int a)
{
        int i;

        for(i=31;i>=0;i--)
        {
                printf("%d",((a>>i) & 0x1));
        }
}

void print_oct(int a)
{
        int i;

        for(i=10;i>=0;i--)
        {
                printf("%d",((a>>(3*i)) & 0x7));
        }
        printf("\n");
}

void print_hex(int a)
{
	int i;
	for(i=7;i>=0;i--)
	{      				
		if (((a>>(4*i)) & 0xf) >= 0 && ((a>>(4*i)) & 0xf) <=9)
    	printf("%d",((a>>(4*i)) & 0xf));
    else
    {
    	switch ((a>>(4*i)) & 0xf)
    	{
    	case 10:
    		printf("a");
        break;
			case 11:
				printf("b");
				break;
			case 12:
        printf("c");
        break;
			case 13:
				printf("d");
				break;
			case 14:
      	printf("e");
        break;
			case 15:
				printf("f");
				break;
			default :
				printf("debug");
				break;												             				
      }
     }
  }
        printf("\n");
}


main(viod)
{
        unsigned int i;

        scanf("%d\n",&i);

        print_bin(i);

        print_oct(i);

				print_hex(i);
	
	return 0;
}

/*================================================homework15-4.c=========================================*/
//用位域操作实现随机生成无重复的10个数字，要求不允许使用数组
//提示：随机数用 rand() 函数，用一个整型数的bit0-bit9来记录已经产生的数字 
//生成的数字I则将bit 0-9位中的第I位置为1

#include<stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

main(viod)
{
	int i;
	int store_num;
	int rand_num;
	
	store_num=0;
	i=0;
	while(i<N)
	{
		srand((int)time(NULL));
		rand_num=rand() % N;
		
		if(store_num & (1 << rand_num))
			{
				continue;
			}
		else
			{
				store_num = store_num | (1 << rand_num);
				printf("rand_num= %d\n",rand_num);
				i++;
			}	
	}
}

/*
rand_num= 3
rand_num= 4
rand_num= 1
rand_num= 0
rand_num= 2
rand_num= 9
rand_num= 8
rand_num= 7
rand_num= 5
rand_num= 6
*/
