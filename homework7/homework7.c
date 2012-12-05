//homework7
//one:range of two chess

#include <stdio.h>

int main()
{
	int i,j;
	int x,y;
	int m,n;

	for (i=0 ;i<5 ;i++ )
	{
		for (j=0 ;j<5 ;j++ )
		{
			printf("0 ");
		}

		printf("\n");
	}
	
	printf("where do you want to move in chess\n");
	
	do
	{
		printf("the two number must small than 5\n");
		scanf("%d",&x);
		scanf("%d",&y);
	}
	while (x>=5 && y>=5);
	
	do
	{
		printf("the two number must small than 5:\n");
		scanf("%d",&m);
		scanf("%d",&n);
	}
	while (n>=5 && m>=5);

	if (m>x)
	{
		printf("between the two number have %d chess \n",4-y+(m-x-1)*5+n);
	}
	else if (m=x && n>y)
	{
		printf("between the two number have %d chess\n",n-y);
	}
	else if (m=x && n<y)
	{
		printf("between the two number have %d chess\n",y-n);
	}
	else if (x>m)
	{
		printf("between the two number have %d chess\n",4-n+(x-m-1)*5+y);
	}
		
	return 0;
}
/*
0 0 0 0 0 
0 0 0 0 0 
0 0 0 0 0 
0 0 0 0 0 
0 0 0 0 0 
where do you want to move in chess.the two number must small than 51
1
the two number must small than 53
3
between the two number have 11 chess 

*/

//two:Eight Queens Problem
#include <stdio.h>

int main()
{
	int i,j,m,n;
	int a[5][5];

	for (i=0 ;i<5 ;i++ )
	{
		for (j=0 ;j<5 ;j++ )
		{
			a[i][j]=0;
		}
	}

	
	do
	{
		printf("the two number must small than 4:\n");
		scanf("%d",&i);
		scanf("%d",&j);
	}
	while (i>=5 && j>=5);

	for (m=0 ;m<5 ;m++ )
	{
		a[i][m]=1;
		a[m][j]=1;
	}

	m=i;
	n=j;
	while (m>=0 && n>=0)
	{
		a[m][n]=1;
		m--;
		n--;
	}
	
	m=i;
	n=j;
	while (m<=4 && n<=4)
	{
		a[m][n]=1;
		m++;
		n++;
	}
    
	m=i;
	n=j;
	while (m>=0 && n>=0 && m<=4 && n<=4)
	{
		a[m][n]=1;
		m--;
		n++;
	}

	m=i;
	n=j;
	while (m>=0 && n>=0 && m<=4 && n<=4)
	{
		a[m][n]=1;
		m++;
		n--;
	}

	a[i][j]=2;

	for (i=0 ;i<5 ;i++ )
	{
		for (j=0 ;j<5 ;j++ )
		{
			if (a[i][j]==1)
			{
				printf("%d ",a[i][j]);
			}
		}
		printf("\n");
	}


	return 0;
}

/*
the two number must small than 4:
2
3
0 1 0 1 0
0 0 1 1 1
1 1 1 0 1
0 0 1 1 1
0 1 0 1 0
*/