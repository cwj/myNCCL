#include<stdio.h>

int chessboard[15][15]={{0}};
int one_direction[5]={3},two_direction[5]={3};
int weight_onechess;
int ppi,ppj;

void printf_chessboard()
{
	int i,j;
	for (i=0;i<15;i++)
	{
		for (j=0;j<15;j++)
		{
			printf("%d  ",chessboard[i][j]);
		}
		printf("\n");
	}
}

int whowin(int fivechess_line[15][15],int i,int j,int k)
{
	//int i,j;
	int one_count,two_count;
	
	one_count=check_one(defend_borad,i,j,0,1,k);
	two_count =check_two(defend_borad,i,j,0,-1,k);	
	if(one_count+two_count>=4)
		{
			return 1;
		}
		
	one_count=check_one(defend_borad,i,j,0,1,k);
	two_count =check_two(defend_borad,i,j,0,-1,k);
	if(one_count+two_count>=4)
		{
			return 1;
		}
		
	one_count=check_one(defend_borad,i,j,0,1,k);
	two_count =check_two(defend_borad,i,j,0,-1,k);
	if(one_count+two_count>=4)
		{
			return 1;
		}
		
	one_count=check_one(defend_borad,i,j,0,1,k);
	two_count =check_two(defend_borad,i,j,0,-1,k);
	if(one_count+two_count>=4)
		{
			return 1;
		}
	
	return 0;
		
}


int check_one(int all_check[15][15],int i,int j,int l,int r,int k)
{
	int counter=0;
	int coun=0;
		
	while(coun<5 && j+r<=15 && i+l<=15 && j+r>=0 && i+l>=0)
	{
		if (all_check[i+l][j+r]==k)
			{
				counter=counter+1;
			}
		else
			{
				//return counter;
				pointonei=i+l;
				pointonej=j+r;
				break;
			}
		coun++;
		l=l+l;
		r=r+r;
	}
	
	coun=0
	//right_point
	while(coun<5 && j+r<=15 && i+l<=15 && j+r>=0 && i+l>=0 && (all_check[i+l][j+r]==0 || all_check[i+l][j+r]==k))
	{
		if (all_check[i+l][j+r]==0)
			{
				one_direction[coun]=0;
			}
		else if(all_check[i+l][j+r]==k && coun>counter)
			{
				one_direction[coun]=k;
			}
			
		coun++;
		l=l+l;
		r=r+r;
	}
	
	return counter;
}

int check_two(int all_check[15][15],int i,int j,int l,int r,int k)
{
	int counter=0;
	int coun=0;
	
	
	while(coun<5 && j+r<=15 && i+l<=15 && j+r>=0 && i+l>=0)
	{
		if (all_check[i+l][j+r]==k)
			{
				counter=counter+1;
			}
		else
			{
				//return counter;
				pointtwoi=i+l;
				pointtwoj=j+r;
				break;
			}
		coun++;
		l=l+l;
		r=r+r;
	}
	
	coun=0
	//right_point
	while(coun<5 && j+r<=15 && i+l<=15 && j+r>=0 && i+l>=0 && (all_check[i+l][j+r]==0 || all_check[i+l][j+r]==k))
	{
		if (all_check[i+l][j+r]==0)
			{
				two_direction[coun]=0;
			}
		else if(all_check[i+l][j+r]==k && coun>counter)
			{
				two_direction[coun]=k;
			}
			
		coun++;
		l=l+l;
		r=r+r;
	}
	
	return counter;
}

int defend(int defend_borad[15][15],int i,int j)
{
	int one_count,two_count;
	int m;
	
	for(m=0;m<5;m++)
	{
		one_direction[m]=3;
		two_direction[m]=3;
	}
	//right left
	one_count=check_one(defend_borad,i,j,0,1,1);
	two_count =check_two(defend_borad,i,j,0,-1,1);
	flag=calculate(one_count,two_count,1,i,j,4);//4代表是做defend时候的传入
	if(flag==2)
		{
			return 2;
		}
	
	for(m=0;m<5;m++)
	{
		one_direction[m]=3;
		two_direction[m]=3;
	}
	one_count=check_one(defend_borad,i,j,0,1,1);
	two_count =check_two(defend_borad,i,j,0,-1,1);
	flag=calculate(one_count,two_count,1,i,j,4);
	if(flag==2)
		{
			return 2;
		}
		
	for(m=0;m<5;m++)
	{
		one_direction[m]=3;
		two_direction[m]=3;
	}
	one_count=check_one(defend_borad,i,j,0,1,1);
	two_count =check_two(defend_borad,i,j,0,-1,1);
	flag=calculate(one_count,two_count,1,i,j,4);
	if(flag==2)
		{
			return 2;
		}
	
	for(m=0;m<3;m++)
	{
		one_direction[m]=3;
		two_direction[m]=3;
	}
	one_count=check_one(defend_borad,i,j,0,1,1);
	two_count =check_two(defend_borad,i,j,0,-1,1);
	flag=calculate(one_count,two_count,1,i,j,4);
	if(flag==2)
		{
			return 2;
		}	
}

int calculate(int one_direction_count,int second_diection_count,int k,int i,int j,int which)
{
	if(one_direction_count+second_diection_count==3)
		{//****
			if(one_direction[0]==0 && two_direction[0]!=0)
				{
					weight_onechess=weight_onechess+200;
				}
				
			if(one_direction[0]==0 || two_direction_score[0]!=0)
				{//_****$
					weight_onechess=weight_onechess+10;
					if(which==4)
						{
							chessboard[pointonei][pointonej]=2;
							flag= 2;
						}
				}
			else if(two_direction_score[0]==0 || one_direction[0]!=0)
				{//_****$
					weight_onechess=weight_onechess+10;
					if(which==4)
						{
						chessboard[pointtwoi][pointtwoj]=2;
						flag= 2;
						}
				}
		}
	
	if(one_direction_count+second_diection_count==2)
		{
			if(one_direction[0]==0 && two_direction_score[0]==0)
				{//_***_
					if(one_direction[1]==k)
						{//_***_*
							weight_onechess=weight_onechess+10;
							if(which==4)
							{
								chessboard[pointonei][pointonej]=2;
								flag= 2;
							}
						}
					else(two_direction_score[1]==k)
						{
							weight_onechess=weight_onechess+10;
							if(which==4)
								{
								chessboard[pointtwoi][pointtwoj]=2;
								flag= 2;
								}
						}
				}
		}
	if(one_direction_count+second_diection_count==1)						
		{//_**_
			if(one_direction[0]==0 && two_direction[1]==k)
				{//*_**__
					weight_onechess=weight_onechess+10;
					if(which==4)
						{
							chessboard[pointonei][pointonej]=2;
							flag= 2;
						}
				}
				else if(two_direction[0]==0 && one_direction[1]==k)
					{
						weight_onechess=weight_onechess+10;
						if(which==4)
							{
								chessboard[pointtwoi][pointtwoj]=2;
								flag= 2;
							}
					}
			}
		else
			{
				weight_onechess=weight_onechess+0;
				return weight_onechess;
			}
			
		return weight_onechess;
			
}

int weight_chess(int find_chess[15][15],int i,int j,int whoplay)
{
	int one_count,two_count;
	int weight_onechess=0;

	weight_onechess=0;	
	//right=check_one(find_chess,i,j,0,1,whoplay);
	//left =check_two(find_chess,i,j,0,-1,whoplay);
	one_count=check_one(find_chess,i,j,0,1,whoplay);
	two_count =check_two(find_chess,i,j,0,-1,whoplay);
	weight_onechess=calculate(one_count,two_count,whoplay,i,j,5);
	//up down
	one_count=check_one(find_chess,i,j,1,0,whoplay);
	two_count =check_two(find_chess,i,j,-1,0,whoplay);
	weight_onechess=weight_onechess+calculate(one_count,two_count,whoplay,i,j,5);
	//
	one_count=check_one(find_chess,i,j,-1,1,whoplay);
	two_count =check_two(find_chess,i,j,1,-1,whoplay);
	weight_onechess=weight_onechess+calculate(one_count,two_count,whoplay,i,j,5);
	
	one_count=check_one(find_chess,i,j,-1,-1,whoplay);
	two_count =check_two(find_chess,i,j,1,1,whoplay);
	weight_onechess=weight_onechess+calculate(one_count,two_count,whoplay,i,j,5);
	
	return weight_onechess;
}

void who_play(int analysis_chess[15][15])
{
	int i,j;
	int m,n;	
	int ppwight,computerwight;
	int max;
	int maxi,maxj;
	int flag=1;
	FILE *fp;
	
	ppwight=0;
	computerwight=0;
	for(i=0;i<15;i++)
		{
			for(j=0;j<15;j++)
				{
					if(analysis_chess[i][j]==0)
						{
							flag=1;
							analysis_chess[i][j]=2;//在此点下子
								
							one_count=check_one(chessboard,i,j,0,1,2);
							two_count =check_two(chessboard,i,j,0,-1,2);
							if(one_count+two_count==4)
								{
									printf_chessboard();
									printf("pepole win\n");
									exit 0;
								}
									
							one_count=check_one(chessboard,i,j,1,0,2);
							two_count =check_two(chessboard,i,j,-1,0,2);
							if(one_count+two_count==4)
								{
									printf_chessboard();
									printf("pepole win\n");
									exit 0;
								}
							one_count=check_one(chessboard,i,j,-1,1,2);
							two_count =check_two(chessboard,i,j,1,-1,2);
							if(one_count+two_count==4)
								{
									printf_chessboard();
									printf("pepole win\n");
									exit 0;
								}
							
							one_count=check_one(chessboard,i,j,-1,-1,2);
							two_count =check_two(chessboard,i,j,1,1,2);
							if(one_count+two_count==4)
								{
									printf_chessboard();
									printf("pepole win\n");
									exit 0;
								}		
								
							analysis_chess[i][j]=0;
							flag=defend(analysis_chess,ppi,ppj);
								
						if(flag==1)
							{
								analysis_chess[i][j]=2;
								ppwight=0;
								computerwight=0;
								//计算所有棋子的得分
								for(m=0;m<15;m++)
								{
									for(n=0;n<15;n++)
									{
										//判断这个子的权重
										if(analysis_chess[m][n] == 2 && analysis_chess[m-1][n]!=2 && analysis_chess[m][n-1] != 2 && analysis_chess[m-1][n-1] != 2 && analysis_chess[m+1][n-1] != 2)
											{
												computerwight=weight_chess(analysis_chess,m,n,2);
												fp=fopen("/opt/test/log.txt","a+");
												if(fp!=NULL)
													{
														fprintf(fp,"debug information m=%d,n=%d, computerwight=%d\n",m,n,computerwight);
													}
												fclose(fp);											
											}
										
										if(analysis_chess[m][n] == 1 && analysis_chess[m-1][n]!=1 && analysis_chess[m][n-1] != 1 && analysis_chess[m-1][n-1] != 1 && analysis_chess[m+1][n-1] != 1)
											{
												ppwight=weight_chess(analysis_chess,m,n,1);
												
												fp=fopen("/opt/test/log.txt","a+");
												if(fp!=NULL)
													{
														fprintf(fp,"debug information m=%d,n=%d, ppwight=%d\n",m,n,ppwight);
													}
												fclose(fp);
												
											}
										
									}
								}
								
									analysis_chess[i][j]=0;
									company_wight[i][j]=computerwight-ppwight;
									fp=fopen("/opt/test/log.txt","a+");
									if(fp!=NULL)
										{
											fprintf(fp,"debug information i=%d,j=%d, company_wight[i][j]=%d\n",i,j,company_wight[i][j]);
										}
								fclose(fp);
							}	
						}		
					}
					
					max=company_wight[0][0];
					for(i=0;i<15;i++)
					{
						for(j=0;j<15;j++)
						{
							if(company_wight[i][j]>=max)
								{
									max=company_wight[i][j];
									maxi=i;
									maxj=j;
									printf("debug information maxi=%d,maxj=%d, max=%d\n",i,j,max);
								}
						}
					}
					
		analysis_chess[maxi][maxj]=2;	
		if (whowin(chessboard,maxi,maxj,2)==1)
			{
				printf("compter win\n");
				exit(0) ;
			}
		}
}

int main(void)
{
	int i,j,k,who;
	int total_count;
	int maxcompall,maxcompi,maxcompj,maxppall,maxppi,maxppj;
	

	chessboard[8][7]=1;
	chessboard[8][6]=2;
	printf_chessboard();

	printf("who play the first chess ,1=pp,2=cpmputer");
	scanf("%d",&who);
	printf("who= %d\n",who);
	if(who==1)
			total_count=3;
	else
			total_count=2;
	
	printf("debug information %d,%d\n",total_count,total_count%2);
	while(1)
	{
		if(total_count%2==1)
		{
			printf("pepole play:\n");	
			do
			{
				printf("pepole input\n");
				scanf("%d %d",&i,&j);
				
			}while(chessboard[i][j]==1 || chessboard[i][j]==2);
				
			chessboard[i][j]=1;
			//ppwight[0]=weight_chess(chessboard,i,j,1);//这个点的八个方向的权重，包含**__*等情况
			ppi=i;
			ppj=j;
			
			printf_chessboard();
			
			if (whowin(chessboard,i,j,1)==1)
			{
				printf("pepole win\n");
				return 0;
			}
		}
		else
		{
			printf("computer play\n");
			
			who_play(chessboard);
			printf_chessboard();

		}
		total_count++;
		
		if(total_count==224)
		{
			printf("no place to paly ,game over , draw");
			return 0;
		}
		//sleep(3);
	}

}




/*判断会不会成5
for(i=0;i<15;i++)
			{
				for(j=0;j<15;j++)
				{
					chessboard[i][j]=2;
					one_count=check_one(chessboard,i,j,0,1,2);
					two_count =check_two(chessboard,i,j,0,-1,2);
					if(one_count+two_count==4)
						{
							printf_chessboard();
							printf("pepole win\n");
							flag=2;
							return 0;
						}
						else
							{
								  chessboard[i][j]=0; 
								  flag=1;   
							}
							
					one_count=check_one(chessboard,i,j,1,0,2);
					two_count =check_two(chessboard,i,j,-1,0,2);
					if(one_count+two_count==4)
						{
							printf_chessboard();
							printf("pepole win\n");
							flag=2;
							return 0;
						}
						else
							{
								  chessboard[i][j]=0; 
								  flag=1;   
							}
							
					one_count=check_one(chessboard,i,j,-1,1,2);
					two_count =check_two(chessboard,i,j,1,-1,2);
					if(one_count+two_count==4)
						{
							printf_chessboard();
							printf("pepole win\n");
							flag=2;
							return 0;
						}
						else
							{
								  chessboard[i][j]=0; 
								  flag=1;   
							}
							
					one_count=check_one(chessboard,i,j,-1,-1,2);
					two_count =check_two(chessboard,i,j,1,1,2);
					if(one_count+two_count==4)
						{
							printf_chessboard();
							printf("pepole win\n");
							flag=2;
							return 0;
						}			
				}
			}
*/			