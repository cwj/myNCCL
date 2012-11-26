#include <stdio.h>
int glob1;
int glob2;
int glob3;


int main(void)
{
        int local1;
        int local2;
        int local3;


        printf("glob1:  %x,%d,%p\n",glob1,glob1,&glob1);      
        printf("glob2:  %x,%d,%p\n",glob2,glob2,&glob2);      
        printf("glob3:  %x,%d,%p\n\n",glob3,glob3,&glob3);    

        printf("local1:  %x,%d,%p\n",local1,local1,&local1);      
        printf("local2:  %x,%d,%p\n",local2,local2,&local2);               
        printf("local3:  %x,%d,%p\n",local3,local3,&local3);      

        return 0;
}


glob1:  0,0,0x8049688 134518408
glob2:  0,0,0x804968c 134518412
glob3:  0,0,0x8049684 134518404
//这里内存是连续的。。但是不是从大到小，也不是从小到大。

local1:  256ca0,2452640,0xbfe87424  3219692340
local2:  0,0,0xbfe87420             3219692336
local3:  385ff4,3694580,0xbfe8741c  3219692332
//这里是连续，切从大到小