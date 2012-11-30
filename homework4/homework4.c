//this program have some problem ,I set 0 to exit procedure.using string is better.
#include <stdio.h>
#include <time.h>
int main()
{int n=0;
int m=0;
srand(time(NULL));
n=rand()%100;
printf("the computer  number is from 0 to 100");
printf("if you input 0, you will exit the procedure \n");
do
{
  printf("inpute you own nuber: ");
    scanf("%d",&m);
	if (m==0)
	{
		printf("exit the procedure \n");	
		return 0;		
	}
	else if (m>n)
	{
		printf("you number is big than the computer number \n");
	}
	else if (m<n)
	{	
	printf("you number is small than the computer number \n");
	}
}
while (m!=n);

printf("you number is %d\n",m);	
	
	return 0;
}

