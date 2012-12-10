//用户任意输入一个字符串，
//判断这个字符串是否为“回文”(回文即按正反顺序读都一样)。
//例如 “abcba” 就是回文。
#include <stdio.h>

int main()
{
	char str[];
	int i,j,len;
	
	printf("input a string: ");
	scanf("%s",str);
	
	i=0;
	while(str[i]!='\0')
	{
		i++;
  }
	
	len=i-1;
	j=0;
	//len=sizeof(str);
	//j=len;
	for (i=0 ;i<len/2 ;i++ )
	{
		if (str[i]!=str[len])
		{
			printf("not palindromic number \n");
			j=1;
			break;
		}
		j--;
	}

	if(j==0)
	printf("palindromic number \n");
	
	return 0;
}


//使用字符数组实现基于数字字符串的加减法。
//例如"123" + "45" = "168" , "456"-"13"="443"。


#include <stdio.h>
//做字符串的反转
void reverser(char sum[],int i)
{
	int len;

	len = i;
    for (i = 0; i < len/2; i++)
    {
        char tmp;
        tmp = sum[i];
        sum[i] = sum[len-i-1];
        sum[len-i-1] = tmp;
    }

    return;
}

//做2个数的减法
void subtraction(char big[],int i,char small[],int j)
{
	char sub[100];
    int k=0,m;
	//printf("%s\n,%s",big,small);
	while (i>0)
       {
		if(j>0)
          {
            m=big[i-1]-'0'-(small[j-1]-'0');
            if (m<0 && i-1>=0)
             {
                 big[i-1]=big[i-1]-1;
                 m=small[j-1]-'0'-(big[i-1]-'0');
             }

             sub[k++]=m+'0';
             i--;
             j--;
          }
        else
          {
             m=big[i-1]-'0';
             sub[k++]=m+'0';
             i--;
          }
  }
  sub[k]='\0';

  reverser(sub,k);
  printf("two string number subtraction = %s\n", sub);

}



//做2个数的加法

void add(char numone[],int i,char numtwo[],int j)
{
    int n,k,m;
    char sum[100];
    
    k=0;
    
    while (i>0 || j>0)
    {
    	if (i<=0)
           {
				i=1;
				numone[i-1]='0';//在这里发生了变化
           }
		if(j<=0)
		   {
				j=1;
				numtwo[j-1]='0';
		   }

      m=numone[i-1]-'0'+numtwo[j-1]-'0';

      if (m>9)
          {
             n=1;
             m=m%10;
          }
      else
          n=0;

      sum[k]=m+n+'0';
      k=k+1;
      i--;
      j--;
    }

    sum[k]='\0';

    reverser(sum,k);
    printf("two string number add = %s\n", sum);
}



int main()
{
        char a[100],b[100];
        int i=0, j=0,ai,bj;

        printf("input two number ");

        scanf("%s",a);

        while(a[i]!='\0')
        {
                i++;
        }
        scanf("%s",b);
        while(b[j]!='\0')
        {
                j++;
        }
    //    printf("input number is over i j %d,%d\n",i,j);

	if (i>j)
        {
                subtraction(a,i,b,j);
        }
        else if (i<j)
        {
                subtraction(b,j,a,i);
        }
        else if (i=j)
        {
			      ai=i;
			      bj=j;
            while (i>=0)
            {
                if (a[i]-'0'>b[j]-'0')
                   {
                        subtraction(a,ai,b,bj);
                        break;
                   }
                else
                   {
                        subtraction(b,bj,a,ai);
                        break;
                   }
                i--;
                j--;
            }
        }
        
	   add(a,i,b,j);//在add函数这里对b数组里的数据变更了。
	

        return 0;
}

/*
input two number
 1234
234
two string number subtraction = 1000
two string number add = 1468
[root@localhost nccl]# ./a.out
input two number
 34567
234
two string number subtraction = 34333
two string number add = 34792
*/

//编写一个去字符串多余空格的的程序，将连
//续的多个空格用一个空格代替。例如输入"abc___ab_a__c"，输出"abc ab a c"。

#include <stdio.h>

int main()
{
        char str[40];
        int i,j,m,n;

        scanf("%s",str);
        printf("%s\n",str);


        for (i=0,j=0 ;str[i]!='\0' ;i++ )
        {
                if (str[i]=='_')
                {
                        j=i;
                        m=i;
                        n=0;
                        while (str[j]=='_')
                        {
                                j++;
                                n++;
                        }

                        while (str[j]!='\0')
                        {
                                str[m+1]=str[j];
                                m++;
                                j++;
                        }
                str[j-n+1]='\0';
                printf("debug information %s\n",str);
                }

        }

        printf("%s\n",str);

        return 0;
}
/*
[root@cem test]# ./a.out
dwdw_______ssd__sd_sd
dwdw_______ssd__sd_sd
debug information dwdw_ssd__sd_sd
debug information dwdw_ssd_sd_sd
debug information dwdw_ssd_sd_sd
dwdw_ssd_sd_sd
/*