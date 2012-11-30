//one:print 10--->0
#include <stdio.h>
int main()
{
	int n;
	n=10;
	while (n>=0)
	{
		printf("the digit is %d\n",n);
		n--;
	}
	
	return 0;
}
/*
the digit is 10
the digit is 9
the digit is 8
the digit is 7
the digit is 6
the digit is 5
the digit is 4
the digit is 3
the digit is 2
the digit is 1
the digit is 0
*/

//two:print the sum number
#include <stdio.h>
int main()
{int n=1;
  int sum=0;
while (n<=10)
{
	sum=sum+n;
	n++;
}
printf("the sum is %d \n",sum);
	return 0;
}

//the sum is 55 


//three:
#include <stdio.h>
int main()
{int n=10;
  int sum=0;
  do
  {
	  printf("the digit is %d \n",n);
	  sum=sum+n;
	  n--;
  }
  while (n>=0);
printf("the sum is %d \n",sum);
	return 0;
}

/*
the digit is 10 
the digit is 9 
the digit is 8 
the digit is 7 
the digit is 6 
the digit is 5 
the digit is 4 
the digit is 3 
the digit is 2 
the digit is 1 
the digit is 0 
the sum is 55
*/

//four:printf the digit of a number
#include <stdio.h>
int main()
{int n=10;
  int m=0;
  printf("inpute you own nuber: \n");
  scanf("%d",&n);
  while (n/10>=0)
  {
	  m=n%10;
	  
	  if (n==0)
	  {
		return 0;
	  }
	  printf("the digt is %d \n",m);
	  n=n/10;
  }
  return 0;
}
