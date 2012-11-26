#include <stdio.h>
int glob1;
int glob2;
int glob3;

char cglob1;
char cglob2;
char cglob3;

short sglob1;
short sglob2;
short sglob3;

float fglob1;
float fglob2;
float fglob3;



int main(void)
{
        int local1;
        int local2;
        int local3;

char clocal1;
char clocal2;
char clocal3;

short slocal1;
short slocal2;
short slocal3;

float flocal1;
float flocal2;
float flocal3;

        printf("glob1:  %x,%d,%p\n",glob1,glob1,&glob1);      //glob1:  0,0,0x8049930 134519088
        printf("glob2:  %x,%d,%p\n",glob2,glob2,&glob2);      //glob2:  0,0,0x8049938 134519096
        printf("glob3:  %x,%d,%p\n\n",glob3,glob3,&glob3);    //glob3:  0,0,0x804992c 134519084

		    printf("cglob1:  %x,%s,%d,%p\n",cglob1,cglob1,cglob1,&cglob1);   //cglob1:  0,(null),0,0x8049934 134519092
        printf("cglob2:  %x,%s,%d,%p\n",cglob2,cglob2,cglob2,&cglob2);   //cglob2:  0,(null),0,0x8049940 134519104
        printf("cglob3:  %x,%s,%d,%p\n\n",cglob3,cglob3,cglob3,&cglob3); //cglob3:  0,(null),0,0x8049941 134519105

		    printf("sglob1:  %x,%d,%p\n",sglob1,sglob1,&sglob1);       //sglob1:  0,0,0x8049936
        printf("sglob2:  %x,%d,%p\n",sglob2,sglob2,&sglob2);       //sglob2:  0,0,0x8049924 
        printf("sglob3:  %x,%d,%p\n\n",sglob3,sglob3,&sglob3);     //sglob3:  0,0,0x8049926

		    printf("fglob1:  %x,%d,%p\n",fglob1,fglob1,&fglob1);       //fglob1:  0,0,(nil)
        printf("fglob2:  %x,%d,%p\n",fglob2,fglob2,&fglob2);       //fglob2:  0,0,(nil)
        printf("fglob3:  %x,%d,%p\n\n",fglob3,fglob3,&fglob3);     //fglob3:  0,0,(nil)


        printf("Transformation glob1: %x,%d\n",&glob1,(int)&glob1+1);  //Transformation glob1: 8049930,134519089  
        printf("Transformation glob2: %x,%d\n\n",&glob2,(int)&glob2+1);//Transformation glob2: 8049938,134519097 

        printf("local1:  %x,%d,%p\n",local1,local1,&local1);      //local1:  256ca0,2452640,0xbfff2c34 
        printf("local2:  %x,%d,%p\n",local2,local2,&local2);      //local2:  0,0,0xbfff2c30            
        printf("local3:  %x,%d,%p\n",local3,local3,&local3);      //local3:  385ff4,3694580,0xbfff2c2c 

        return 0;
}




glob1:  0,0,0x8049930
glob2:  0,0,0x8049938
glob3:  0,0,0x804992c

cglob1:  0,(null),0,0x8049934
cglob2:  0,(null),0,0x8049940
cglob3:  0,(null),0,0x8049941

sglob1:  0,0,0x8049936
sglob2:  0,0,0x8049924
sglob3:  0,0,0x8049926

fglob1:  0,0,(nil)
fglob2:  0,0,(nil)
fglob3:  0,0,(nil)

Transformation glob1: 8049930,134519089
Transformation glob2: 8049938,134519097

local1:  256ca0,2452640,0xbfff2c34
local2:  0,0,0xbfff2c30
local3:  385ff4,3694580,0xbfff2c2c
//全写在一起好像没有啥规律了。。

