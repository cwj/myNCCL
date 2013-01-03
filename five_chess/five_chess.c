#include<stdio.h>

int chessboard[15][15]={{0}};
int right_point,left_point,up_point,down_point,right_down_point,right_up_point,left_down_point,left_up_point;
int company_wight[15][15]={{0}};
int pepole_weight[15][15]={{0}};
int maxij[6]={0};
int globle=0;

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
				return counter;
				left_up_point=leftup_check[i-x][j-x];
				break;
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
				return counter;
				right_up_point=rightup_check[i-x][j+x];
				break;
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
				return counter;
				left_down_point=leftdown_check[i+x][j-x];
				break;
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
				return counter;
				right_down_point=rightdown_check[i+x][j+x];
				break;
			}
		x++;
	}
	
	return counter;
}


int check_right(int right_check[15][15],int i,int j,int k)
{
	int counter=0;
	int x;
	
	x=1;
	while(x<5 && j+x<15)
	{
		if (right_check[i][j+x]==k)
			{
				counter=counter+1;
			}
		else
			{
				return counter;
				right_point=right_check[i][j+x];
				break;
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
				return counter;
				left_point=left_check[i][j-x];
				break;
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
				return counter;
				up_point=up_check[i-y][j];//..............
				break;
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
				return counter;
				down_point=down_check[i+y][j];//..............
				break;
			}
		y++;
	}
	return counter;	
}

int calculate(int one_direction,int second_diection,int one_direction_score,int two_direction_score,int howmany)
{
	if(one_direction+second_diection>=4)
		{
			return 100000/howmany;//³É5
		}
	else if(one_direction+second_diection>=3)
		{
			if(one_direction_score==0 && two_direction_score==0)
				{
					return 20000/howmany;//»îËÄ
				}
			else if(one_direction_score==0 || two_direction_score==0 )
				{
					return 4000/howmany;
				}
		}
	else if(one_direction+second_diection>=2)
		{
			if(one_direction_score==0 && two_direction_score==0)
				{
					return 990/howmany;
				}
			else if(one_direction_score==0 || two_direction_score==0 )
				{
					return 200/howmany;
				}
		}
	else if(one_direction+second_diection>=1)
		{
			if(one_direction_score==0 && two_direction_score==0)
				{
					return 50/howmany;
				}
			else if(one_direction_score==0 || two_direction_score==0 )
				{
					return 10/howmany;
				}
		}
		
	return 0;
}

int weight_chess(int find_chess[15][15],int i,int j,int whoplay,int howmany)
//..........
{
	/*.................
	...........
		1...   ..10000
		1...   ..2000
		2...   ..400
		3...   ..99
		4...   ..20
		5...   ..5
		6...   ..1
	*/
	int right,left,up,down,right_down,right_up,left_down,left_up;
	//int four_direction[4];
	int weight_all=0;
	
	
	right=check_right(find_chess,i,j,whoplay);
	left=check_left(find_chess,i,j,whoplay);
	up=check_up(find_chess,i,j,whoplay);
	down=check_down(find_chess,i,j,whoplay);
	right_down=check_rightdown(find_chess,i,j,whoplay);
	left_down=check_leftdown(find_chess,i,j,whoplay);
	right_up=check_rightup(find_chess,i,j,whoplay);
	left_up=check_leftup(find_chess,i,j,whoplay);
	
	weight_all=weight_all+calculate(right,left,right_point,left_point,howmany);
	weight_all=weight_all+calculate(up,down,up_point,down_point,howmany);
	weight_all=weight_all+calculate(right_down,left_up,right_down_point,left_up_point,howmany);
	weight_all=weight_all+calculate(right_up,left_down,right_up_point,left_down_point,howmany);
	
	return weight_all;
}

void who_play(int analysis_chess[15][15],int whoplay,int howmany)
//whoplay 1.....2.....
{
	int i,j;	
	int max;
	int maxi,maxj;
	
	if(whoplay==2)
		{
			max=company_wight[0][0];//........
			for(i=0;i<15;i++)
			{
				for(j=0;j<15;j++)
					{
						if(analysis_chess[i][j] != 1 && analysis_chess[i][j] != 2)
							{
								//...............
								company_wight[i][j]=company_wight[i][j]+weight_chess(analysis_chess,i,j,whoplay,howmany);
								if(company_wight[i][j]>max)
									{
										max=company_wight[i][j];
										maxi=i;
										maxj=j;
									}
							}
					}
			}
		}
	else
		{
			max=pepole_weight[0][0];
			for(i=0;i<15;i++)
			{
				for(j=0;j<15;j++)
					{
						if(analysis_chess[i][j] != 1 && analysis_chess[i][j] != 2)
							{
								pepole_weight[i][j]=pepole_weight[i][j]+weight_chess(analysis_chess,i,j,whoplay,howmany);
								if(pepole_weight[i][j]>max)
									{
										max=pepole_weight[i][j];
										maxi=i;
										maxj=j;
									}
							}
					}
			}
		}

	printf("debug information %d,%d han shu li de weizhi\n",maxi,maxj);	
	analysis_chess[maxi][maxj]=whoplay;
	maxij[globle++]=maxi;
	maxij[globle++]=maxj;
	
}

main(void)
{
	int i,j,k,who;
	int total_count;
	//int count=0;
	int maxcompall,maxcompi,maxcompj,maxppall,maxppi,maxppj;
	
	chessboard[8][7]=1;
	chessboard[7][8]=2;
	printf_chessboard();
	
	
	printf("who play the first chess ,1=pp,2=cpmputer");
	scanf("%d",&who);
	
	if(who==1)
		//...
		{
			total_count=1;
		}
	else
		//....
		{
			total_count=2;
		}
	
	while(1)
	{
		if(total_count%2==1)
		{
			printf("pepole play:\n");
			//......
			printf("put the chess\n");	
			do
			{
				scanf("%d %d",&i,&j);
			}while(chessboard[i][j]==1 || chessboard[i][j]==2);
				
			chessboard[i][j]=1;
			
			printf_chessboard();
			
			if (whowin(chessboard,i,j,1)==1)
			{
				printf("pepole win");
				return 0;
			}
		}
		else
		{
			printf("computer play\n");
			//count=0;
			//while(count<3)
			//	{
			globle=0;
			who_play(chessboard,2,1);//.......,...1.........
			//globle=globle+1;
			who_play(chessboard,1,1);//...........1........
			//globle=globle+1;
			who_play(chessboard,2,2);//.......................
			//		count++;				
			//	}	

			maxcompall=0;//...........
			for(i=0;i<15;i++)
			{
				for(j=0;j<15;j++)
				{
					if(company_wight[i][j]>maxcompall)
						{
							maxcompall=company_wight[i][j];
							maxcompi=i;
							maxcompj=j;
						}
				}
			}
								
			maxppall=0;//.............
			for(i=0;i<15;i++)
			{
				for(j=0;j<15;j++)
				{
					if(pepole_weight[i][j]>maxppall)
						{
							maxppall=pepole_weight[i][j];
							maxppi=i;
							maxppj=j;
						}
				}
			}
			
		//	printf("debug information comp %d,%d\n",maxcompi,maxcompj);	
		//	printf("debug information pp   %d,%d\n",maxppi,maxppj);	
			printf("debug information comp %d,%d\n",maxij[0],maxij[1]);	
			printf("debug information pp   %d,%d\n",maxij[2],maxij[3]);
			printf("debug information pp   %d,%d\n",maxij[4],maxij[5]);
					
			if(maxcompall>=100000)
				{
					chessboard[maxij[0]][maxij[1]]=0;
					chessboard[maxij[2]][maxij[3]]=0;
					chessboard[maxij[4]][maxij[5]]=0;
					chessboard[maxcompi][maxcompj]=2;
				}
			else if(maxppall>=100000)
				{
					chessboard[maxij[0]][maxij[1]]=0;
					chessboard[maxij[2]][maxij[3]]=0;
					chessboard[maxij[4]][maxij[5]]=0;
					chessboard[maxppi][maxppj]=2;
				}
			else if(maxcompall>=20000)
				{
					chessboard[maxij[0]][maxij[1]]=0;
					chessboard[maxij[2]][maxij[3]]=0;
					chessboard[maxij[4]][maxij[5]]=0;
					chessboard[maxcompi][maxcompj]=2;
				}
			else if(maxppall>=20000)
				{
					chessboard[maxij[0]][maxij[1]]=0;
					chessboard[maxij[2]][maxij[3]]=0;
					chessboard[maxij[4]][maxij[5]]=0;
					chessboard[maxppi][maxppj]=2;
				}
			else
				{
					chessboard[maxij[0]][maxij[1]]=0;
					chessboard[maxij[2]][maxij[3]]=0;
					chessboard[maxij[4]][maxij[5]]=0;
					chessboard[maxcompi][maxcompj]=2;
				}
			
			printf_chessboard();
				
			for(i=0;i<6;i++)
			{
				maxij[i]=0;
			}
				
			//globle=0;
			
			for(i=0;i<15;i++)
			{
				for(j=0;j<15;j++)
				{
					pepole_weight[i][j]=0;
					company_wight[i][j]=0;
				}
			}	
				
			if (whowin(chessboard,i,j,2)==1)
			{
				printf("computer win");
				return 0;
			}
		}
					
		total_count++;
		
		if(total_count==224)
		{
			printf("no place to paly ,game over , draw");
			return 0;
		}
		
	}

}

