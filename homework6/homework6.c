#include <stdio.h>

int main()
{
    int i,j;
    int x=0,y=0;

    for (i=0 ;i<5 ;i++ )
    {
        for (j=0 ;j<5 ;j++ )
        {
            printf("0 ");
        }

        printf("\n");
    }
   
    printf("where do you want to move in chess.");

    do
    {
        printf("the two number must small than 5");
        scanf("%d",&x);
        scanf("%d",&y);
    }
    while (x>=5 && y>=5);

    for (i=0 ;i<5 ;i++ )
    {
        for (j=0 ;j<5 ;j++ )
        {
            if (i==x && j==y)
                printf("1 ");
            else
                printf("0 ");
        }

        printf("\n");
    }
   
    return 0;
}

/*
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
where do you want to move in chess.the two number must small than 5
1
3
0 0 0 0 0
0 0 0 1 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
*/


#include <stdio.h>

int main()
{
    int i,j,sum;

    for (i=1 ;i<=1000 ;i++ )
    {
        sum=0;
        for (j=1 ;j<i ;j++ )
        {
            if (i%j==0)
            {
                //printf("%d",j);
                sum=sum+j;
            }
        }

        if (sum==i)
        {
            printf("the Perfect number is %d",i);
        }
    }

    return 0;
}

/*
the perfect number  is 6
the perfect number  is 28
the perfect number  is 496
*/

#include <stdio.h>

int main()
{
    int i,j,power,k,m,count,sum;

    for (i=100 ;i<=999 ;i++ )
    {
		count=0;
		k=i;
		while (k!=0)
		{
			k=k/10;
			count++;
		}

		power=i;
		k=i;
		sum=0;
		while (k!=0)
		{
			power=k%10;
			k=k/10;			
			m=1;
			for (j=1 ;j<=count ;j++ )
			{
				m=m*power;
			}
			sum=sum+m;
		}

		if (sum==i)
		{
			printf("the number is %d\n",i);
		}
		
    }

    return 0;
}

/*
the number is 153
the number is 370
the number is 371
the number is 407
*/