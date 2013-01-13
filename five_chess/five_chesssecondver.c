//http://wenku.baidu.com/view/f3020044336c1eb91a375d7d.html
#include<stdio.h>
//#include <unistd.h>

int chessboard[15][15]={{0}};
//int right_point,left_point,up_point,down_point,right_down_point,right_up_point,left_down_point,left_up_point;
int right_point[5],left_point[5],up_point[5],down_point[5],right_down_point[5],right_up_point[5],left_down_point[5],left_up_point[5];
int company_wight[15][15]={{0}};
//int pepole_weight[15][15]={{0}};
//int maxij[10]={0};
//int globle=0;

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
	int right,left,up,down,right_down,right_up,left_down,left_up;
	
	right=check_right(fivechess_line,i,j,k);
	left=check_left(fivechess_line,i,j,k);
	up=check_up(fivechess_line,i,j,k);
	down=check_down(fivechess_line,i,j,k);
	right_down=check_rightdown(fivechess_line,i,j,k);
	left_down=check_leftdown(fivechess_line,i,j,k);
	right_up=check_rightup(fivechess_line,i,j,k);
	left_up=check_leftup(fivechess_line,i,j,k);
	
	if(right+left>=4)
		{
			return 1;
		}
	else if(up+down>=4)
		{
			return 1;
		}
	else if(right_up+left_down>=4)
		{
			return 1;
		}
	else if(left_up+right_down>=4)
		{
			return 1;
		}
		
	return 0;
		
}


int check_leftup(int leftup_check[15][15],int i,int j,int k)
{
	int counter=0;
	int x;
	
	x=1;
	while(x<5 && j-x>=0 && i-x>=0)
	{
		if (leftup_check[i-x][j-x]==k)
			{
				counter=counter+1;
			}
		else
			{
				//return counter;
				//left_up_point=leftup_check[i-x][j-x];
				break;
			}
		x++;
	}
	
		x=1;
	//right_point
	while(x<5 && j-x>=0 && i-x>=0 && (leftup_check[i-x][j-x]==0 || leftup_check[i-x][j-x]==k) )
	{
		if (leftup_check[i-x][j-x]==0)
			{
				left_up_point[i-x][j-x]=0;
			}
		else if(leftup_check[i-x][j-x]==k && x>counter)
			{
				left_up_point[i-x][j-x]=k;
			}
			
		x++;
	}
	
	return counter;
}

int check_rightup(int rightup_check[15][15],int i,int j,int k)
{
	int counter=0;
	int x;
	
	x=1;
	while(x<5 && j+x<15 && i-x>=0)
	{
		if (rightup_check[i-x][j+x]==k)
			{
				counter=counter+1;
			}
		else
			{
				//return counter;
				//right_up_point=rightup_check[i-x][j+x];
				break;
			}
		x++;
	}
	
	x=1;
	//right_point
	while(x<5 && j+x<15 && i-x>=0 && (rightup_check[i-x][j+x]==0 || rightup_check[i-x][j+x]==k) )
	{
		if (rightup_check[i-x][j+x]==0)
			{
				right_up_point[i-x][j+x]=0;
			}
		else if(rightup_check[i-x][j+x]==k && x>counter)
			{
				right_up_point[i-x][j+x]=k;
			}
			
		x++;
	}
	
	return counter;
}

int check_leftdown(int leftdown_check[15][15],int i,int j,int k)
{
	int counter=0;
	int x;
	
	x=1;
	while(x<5 && j-x>=0 && i+x<15)
	{
		if (leftdown_check[i+x][j-x]==k)
			{
				counter=counter+1;
			}
		else
			{
				//return counter;
				//left_down_point=leftdown_check[i+x][j-x];
				break;
			}
		x++;
	}
	
	x=1;
	//right_point
	while(x<5 && j-x>=0 && i+x<15 && (leftdown_check[i+x][j-x]==0 || leftdown_check[i+x][j-x]==k))
	{
		if (leftdown_check[i+x][j-x]==0)
			{
				left_down_point[i+x][j-x]=0;
			}
		else if( leftdown_check[i+x][j-x]==k && x>counter)
			{
				left_down_point[i+x][j-x]=k;
			}
			
		x++;
	}
	
	return counter;
}


int check_rightdown(int rightdown_check[15][15],int i,int j,int k)
{
	int counter=0;
	int x;

	x=1;
	while(x<5 && j+x<15 && i+x<15)
	{
		if (rightdown_check[i+x][j+x]==k)
			{
				counter=counter+1;
			}
		else
			{
				//return counter;
				//right_down_point=rightdown_check[i+x][j+x];
				break;
			}
		x++;
	}
	
		x=1;
	//right_point
	while(x<5 && j+x<15 && i+x<15 && (rightdown_check[i+x][j+x]==0 || rightdown_check[i+x][j+x]==k))
	{
		if (rightdown_check[i+x][j+x]==0)
			{
				right_down_point[i+x][j+x]=0;
			}
		else if(rightdown_check[i+x][j+x]==k && x>counter)
			{
				right_down_point[i+x][j+x]=k;
			}
			
		x++;
	}
	
	return counter;
}


int check_right(int right_check[15][15],int i,int j,int k)
{
	int counter=0;
	//int right_point[5]={3};
	int x;	
	
	x=1;
	while( x<5 && j+x<15)
	{
		if (right_check[i][j+x]==k)
			{
				counter++;
			}
		else if(right_check[i][j+x]==0)
			{
				//return counter;
				//right_point=right_check[i][j+x];
				break;
			}
		x++;	
	}
	
	x=1;
	//right_point
	while(x<5 && j+x<15 && (right_check[i][j+x]==0 ||right_check[i][j+x]==k) )
	{
		if (right_check[i][j+x]==0)
			{
				right_point[i][j+x]=0;
			}
		else if( right_check[i][j+x]==k && x>=counter)
			{
				right_point[i][j+x]=k;
			}
			
		x++;
	}
	
	return counter;
}

int check_left(int left_check[15][15],int i,int j,int k)
{
	int counter=0;
	int x;
	
	x=1;
	while(x<5 && j-x>=0)
	{
		if (left_check[i][j-x]==k)
			{
				counter=counter+1;
			}
		else
			{
				//return counter;
				//left_point=left_check[i][j-x];
				break;
			}
		x++;
	}
	
	x=1;
	//right_point
	while(x<5 && j-x>=0 && (left_check[i][j-x]==0 || left_check[i][j-x]==k) )
	{
		if(right_check[i][j-x]==0)
			{
				right_check[i][j-x]==0
			}
			else if(right_check[i][j-x]==k && x>counter)
				{
					left_point[i][j-x]=k;
				}		
		x++;
	}
	
	return counter;
}

int check_up(int up_check[15][15],int i,int j,int k)
{
	int counter=0;
	int y;
	
	y=1;
	while(y<5 && i-y>=0)
	{
		if (up_check[i-y][j]==k)
			{
				counter=counter+1;
			}
		else
			{
				//return counter;
				//up_point=up_check[i-y][j];//..............
				break;
			}
		y++;
	}
	
	y=1;
	//right_point
	while(y<5 && i-y>=0 && (up_check[i-y][j]==0 || up_check[i-y][j]==k) )
	{
		if(up_check[i-y][j]==0)
			{
				up_point[i-y][j]=0;
			}
		else if(up_check[i-y][j]==k && y>counter)
			{
				up_point[i-y][j]=k;
			}
			
		y++;
	}
	
	return counter;

}



int check_down(int down_check[15][15],int i,int j,int k)
{
	int counter=0;
	int y;
	
	y=1;
	while(y<5 && i+y<15)
	{
		if (down_check[i+y][j]==k)
			{
				counter=counter+1;
			}
		else
			{
				//down_point=down_check[i+y][j];//..............
				break;
			}
		y++;
	}
	
	y=1;
	while(y<5 && i+y<15 && (down_check[i+y][j]==0 || down_check[i+y][j]==k) )
	{
		if(down_check[i+y][j]==0)
			{
				down_point[i+y][j]=0;
			}
			else if(down_check[i+y][j]==k && y>counter)
				{
					down_point[i+y][j]=k;
				}
		y++;
	}
	
	return counter;
}

int calculate(int one_direction,int second_diection,int one_direction_score[5],int two_direction_score[5],int k)
{
	int x=0;
	
	if(one_direction+second_diection==3)
		{
			if (one_direction_score[0]==0 && two_direction_score[0]==0)
				{// _****_
					return 200;
				}
				else if(one_direction_score[0]==0 || two_direction_score[0]!=0)
					{//_****$
						return 198;
					}
		}
		
	if(one_direction+second_diection==2)
		{
			if(one_direction_score[0]==0 && two_direction_score[0]==0)
				{//_***_
					return 200;
				}
			else if(one_direction_score[0]==0 && two_direction_score[0]!=0)
				{//_***#
					if(one_direction_score[1]==0)
						{//_ _ * * * #
							return 100;
						}
						else if(one_direction_score[1]==k)
							{//*_***#
								return 200;
							}
				}
			else if(two_direction_score[0]==0 && one_direction_score[0]!=0)
				{//_***#
					if(two_direction_score[1]==0)
						{//_ _ * * * #
							return 100;
						}
						else if(two_direction_score[1]==k)
							{//*_***#
								return 200;
							}
				}
			else
				{//#***#
					return 1;
				}
				
		if(one_direction+second_diection==1)	
			{//**
				if(one_direction_score[0]==0 && two_direction_score[0]==0)
					{//*_**_*
						if(one_direction_score[1]==k && two_direction_score[1]==k)
							{
								return 
							}
					}
			}
				
		
		}
	
	
	//
	if(one_direction+second_diection==3)
		return 200;//成5
	else if(one_direction+second_diection==3)
		{
			if(one_direction_score==0 && two_direction_score==0)
				return 90;//活四
			else if((one_direction_score==0 && two_direction_score!=0) || (two_direction_score==0 && one_direction_score!=0) )
				return 15;//死四
		}
	else if(one_direction+second_diection==2)
		{
			if(one_direction_score==0 && two_direction_score==0)
				return 40;//活三				
			else if((one_direction_score==0 && two_direction_score!=0) || (two_direction_score==0 && one_direction_score!=0) )
				return 13;//死三
		}
	else if(one_direction+second_diection==1)
		{
			if(one_direction_score==0 && two_direction_score==0)
				return 8;//活二
			else if((one_direction_score==0 && two_direction_score!=0) || (two_direction_score==0 && one_direction_score!=0))
				return 2;//死二
		}
		
	return 0;
}



int weight_chess(int find_chess[15][15],int i,int j,int whoplay)
{
	int right,left,up,down,right_down,right_up,left_down,left_up;
	int weight_all=0;
	
//	right=found_right(find_chess,i,j,whoplay);	
	right=check_right(find_chess,i,j,whoplay);
	left=check_left(find_chess,i,j,whoplay);
	up=check_up(find_chess,i,j,whoplay);
	down=check_down(find_chess,i,j,whoplay);
	right_down=check_rightdown(find_chess,i,j,whoplay);
	left_down=check_leftdown(find_chess,i,j,whoplay);
	right_up=check_rightup(find_chess,i,j,whoplay);
	left_up=check_leftup(find_chess,i,j,whoplay);
	//顺着4个方向到为对方的棋子为止或者5步
	weight_all1=weight_all+calculate(right,left,right_point,left_point,whoplay,i,j);//此子横着的棋型得分
	weight_all2=weight_all+calculate(up,down,up_point,down_point,whoplay,i,j);//此子竖线的棋型得分
	weight_all3=weight_all+calculate(right_down,left_up,right_down_point,left_up_point,whoplay);//此子右上方棋型得分
	weight_all4=weight_all+calculate(right_up,left_down,right_up_point,left_down_point,whoplay);//此子右下方棋型得分
	
	return weight_all;
}

void who_play(int analysis_chess[15][15])
{
	int i,j;
	int m,n;	
	int ppwight,computerwight;
	int max;
	int maxi,maxj;
	FILE *fp;
	
	    ppwight=0;
			computerwight=0;
			for(i=0;i<15;i++)
			{
				for(j=0;j<15;j++)
					{
						if(analysis_chess[i][j]==0)
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
										if(analysis_chess[m][n] == 1 && analysis_chess[m-1][n]!=1 && analysis_chess[m][n-1] != 1 && analysis_chess[m-1][n-1] != 1 && analysis_chess[m+1][n-1] != 1)
											{
												ppwight=ppwight+weight_chess(analysis_chess,m,n,1);
												
												fp=fopen("/opt/test/log.txt","a+");
												if(fp!=NULL)
													{
														fprintf(fp,"debug information m=%d,n=%d, ppwight=%d\n",m,n,ppwight);
													}
												fclose(fp);
												
											}
										if(analysis_chess[m][n] == 2 && analysis_chess[m-1][n]!=2 && analysis_chess[m][n-1] != 2 && analysis_chess[m-1][n-1] != 2 && analysis_chess[m+1][n-1] != 2)
											{
												computerwight=computerwight+weight_chess(analysis_chess,m,n,2);
												fp=fopen("/opt/test/log.txt","a+");
												if(fp!=NULL)
													{
														fprintf(fp,"debug information m=%d,n=%d, computerwight=%d\n",m,n,computerwight);
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
//==========================================================================================================
int defend(int defend_borad[15][15],int i,int j)
{
	int right,left;
	right=check_right(find_chess,i,j,1);
	left=check_left(find_chess,i,j,1);
	
	if(one_direction+second_diection==3)
		{
			if(one_direction_score[i][j]==0 || two_direction_score[0][]!=0)
				{//_****$
					one_direction_score[i][j]=2;
				}
			if(one_direction_score[0][]==0 || two_direction_score[0][]!=0)
				{//_****$
					two_direction_score[i][j]=2;
				}
		}
	
	if(right+left==2)
		{
			if(one_direction_score[0]==0 && two_direction_score[0]==0)
				{//_***_					
					if(one_direction_score[1]==1)
						{//_***_*
							one_direction_score[i][j]==2;
							return 2;							
						}
					if(one_direction_score[1]==1)
						{//_***_*
							two_direction_score[i][j]==2;
							return 2;							
						}									
				}
			else if(one_direction_score[0]==0 && two_direction_score[0]!=0)
				{//_***#
						if(one_direction_score[1]==1)
							{//*_***#
								one_direction_score[i][j]==2;
								return 2; 
							}
				}
			else if(two_direction_score[0]==0 && one_direction_score[0]!=0)
				{//_***#
					if(two_direction_score[1]==1)
							{//*_***#
								two_direction_score[i][j]==2;
								return 2; 
							}
				}
			else
				{//#***#
					return 1;
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
			
			//防守
			flag=defend(chessboard,i,j);
				
			//进攻
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

