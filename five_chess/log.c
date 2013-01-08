#include<stdio.h>
#include<unistd.h>

int main(viod)
{
	int x,y;
	int step;
	int oldx=-1;
	int oldy=-1;
	char buf[20];
	
	while(1)
	{
		scanf("%s %d:%d %d",buf, &step, &x,&y);
		if(strcmp(buf,"step")!=0)
			continue;
		
		fprintf(stderr,"{pipe:<%d> %d %d}\n",getpid(),x,y);
		fflush(stderr);
		
		if(x==oldx && y==oldy)
			break;
		
		printf("%d %d\n",x,y);
		fflush(stdout);
		
		oldx=x;
		oldy=y;
		
		sleep(3);
	}
	
	return 0 ;
	
}