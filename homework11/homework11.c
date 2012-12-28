/*
����һ���ṹ�� point_t �����飬�����һ����У���ԭ�������Զ���Ǹ��㡣   
*/

#include <stdio.h>
#include <math.h>

struct point
{
    int x;
    int y;
};

double calc_distance(point p1)
{
	return sqrt((double)(p1.x)*(p1.x)+(p1.y)+(p1.y));
}

int main(void)
{
	int i,j;
	double 	distance,max_distance;
	point point_t[5];

	for (i=0 ;i<5 ;i++ )
	{
		scanf("%d,%d",&(point_t[i].x),&(point_t[i].y));
	}
	
	max_distance=0;
	for (i=0 ;i<5 ;i++ )
	{
		distance=calc_distance(point_t[i]);

		if (distance>max_distance)
		{
			max_distance=distance;
		}
	}
	
	return 0;
}

//���������һ����У�������Զ��2�����Լ�����֮��ľ��롣

#include <stdio.h>
#include <math.h>

struct point
{
	int x;
	int y;
};


int calc_distance(point p1)
{
	int dx = p1.x - p2.x;
    int dy = p1.y - p2.y;

    return sqrt(dx * dx + dy * dy);

}

int main(void)
{
	int i,j
	double 	distance,max_distance;
	point point_t[5];

	for (i=0 ;i<5 ;i++ )
	{
		scanf("%d,%d",&(point_t[i].x),&(point_t[i].y));
	}
	
	max_distance=0;
	for (i=0 ;i<5 ;i++ )
	{
		for (j=0 ;j<5 ;j++ )
		{
			distance=calc_distance(point_t[i],point_t[j]);
			if (distance>max_distance)
			{
				max_distance=distance;
				printf("%d,%d and %d,%d",point_t[i].x,point_t[i].y,point_t[j].x,point_t[j].y);
			}
		}
	}

	return 0;
}


//��5��ѧ����ÿ��ѧ����3�ſεĳɼ����û������������ݣ�����ѧ�ţ�������
//���ſγɼ�(������)��������ÿλѧ�����ֺܷ�ƽ���ɼ�����֧���û�ͨ��ѧ�ź��������в�ѯ��

#include <stdio.h>
#include <math.h>

struct student
{
	int studentid;
	char name[10];
	double chinese;
	double math;
	double english;
	double allscore;
	double avgscore;

};

void cal_allscore (student p1)
{
	p1.allscore=p1.chinese+p1.math+p1.english
	p1.avgscore=(p1.chinese+p1.math+p1.english)/3;
}

int main(void)
{
	int i,j,searchid;
	char searchname[10];
	student student_t[5];

	for (i=0 ;i<5 ;i++ )
	{
		printf("input %d student id\n",i+1);
		scanf("%d",student_t[i].studentid);
		printf("input %d student name\n",i+1);
		gets(student_t[i].name);
		printf("input %d student chinese score:\n",i+1);
		scanf("%d",student_t[i].chinese);
		printf("input %d student math score:\n",i+1);
		scanf("%d",student_t[i].math);
		printf("input %d student english score:\n",i+1);
		scanf("%d",student_t[i].english);
	}
	
	for (i=0 ;i<5 ;i++ )
	{
		cal_allscore(student_t[i]);
	}

	printf("input the student id or name to search student\n");
	printf("searchid: ");
	scanf("%d",&searchid);
	printf("searchname: ");
	gets(searchname);
	
	for (i=0 ;i<5 ;i++ )
	{
		if (student_t[i].studentid==searchid ||student_t[i].name==searchname )
		{
			printf("%d",student_t[i].studentid);	
			printf("%s",student_t[i].name);
			printf("%d",student_t[i].chinese);
			printf("%d",student_t[i].math);
			printf("%d",student_t[i].english);
			printf("%d",student_t[i].allscore);
			printf("%d",student_t[i].avgscore);
		}
	}
	
	return 0;
}