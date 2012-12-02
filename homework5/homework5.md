##homework5
##one:print average number. 
	#include <stdio.h>
	
	int main()
	{
	    int a[4];
	    int i;
	    int sum=0;
	    float average;
	
	    printf("input five number");
	
	    for (i=0;i<5 ;i++ )
	    {
		scanf("%d",&a[i]);
	    }
	
	    for (i=0;i<5 ;i++ )
	    {
		sum=sum+a[i];
	    }
		
	    average=sum/5;
	    printf("the average is %f \n",average);
		
	    return 0;
	}


##two:print max number. 
	#include <stdio.h>
	
	int main()
	{
	    int a[4];
	    int i;
	    int sum=0;
		
	
	    printf("input five number");
	
	    for (i=0;i<5 ;i++ )
	    {
		   scanf("%d",a[i]);
	    }
	
	    sum=a[0];
	
	    for (i=1;i<5 ;i++ )
	    {
		   if (a[i]>sum)
		     {
		      sum=a[i];
		     }
	    }
		
		
	   printf("the max is %d",sum);
		
	   return 0;
	}

##three:print the November

	#include <stdio.h>
	
	int main()
	{
	    int i;
		/*
	    for (i=0;i<7 ;i++ )
	    {
			switch (i)
			{
			case 0:printf("�� "); break;
			case 1:printf("�� "); break;
			case 2:printf("�� "); break;
			case 3:printf("�� "); break;
			case 4:printf("�� "); break;
			case 5:printf("�� "); break;
			case 6:printf("һ "); break;
			default:break;
			}
	    }
	    printf("\n");
		*/
	
	    printf("日 一 二 三 四 五 六 \n");
	
	    for (i=1;i<=34 ;i++ )
	    {
		   if (i<=4)
		    {
			    printf("   ");
		    }
	     else if (i<14)
		    {
			    printf("%d  ",i-4);
		    }
		   else
	        printf("%d ",i-4);
	
		   if (i%7==0)
		    {
			    printf("\n");
		    }
	    }
		return 0;
	}
	
	/*
	日 一 二 三 四 五 六 
	            1  2  3  
	4  5  6  7  8  9  10 
	11 12 13 14 15 16 17 
	18 19 20 21 22 23 24 
	25 26 27 28 29 30 
	*/

##练习
	#include <stdio.h>
	#define DPRINTF(x) printf("debug-->line-%d " #x "=%d \n",__LINE__,x)
	int main()
	{
	    int i=10;
	    DPRINTF(i);
		
	    return 0;
	}
	
	//debug-->line-7 i=10 
	
	or
	vi homework5.c
	
	#include <stdio.h>
	//#define DPRINTF(x) printf("debug-->line-%d " #x "=%d \n",__LINE__,x)
	int main()
	{
		int i=10;
	//	DPRINTF(i);
	  printf("debug-->line-%d,i=%d ",__LINE__,i); 
		
		return 0;
	}
	
	//在有debug字符的行前加//
	sed -i '/debug/s/^/\/\/&/g' homework5.c 
	//将有debug字符的行的行首//去掉
	sed -i '/debug/s/\/\///g' homework5.c