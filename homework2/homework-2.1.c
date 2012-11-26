#include <stdio.h>
int glob1;
int glob2;
int glob3;


int main(void)
{
        int local1;
       


        printf("glob1:  %x,%d,%p,%d\n",glob1,glob1,&glob1,(int)&glob1+1); 
        printf("glob2:  %x,%d,%p,%d\n",glob2,glob2,&glob2,(int)&glob2+1); 
        printf("glob3:  %x,%d,%p,%d\n\n",glob3,glob3,&glob3,(int)&glob3+1); 
        
        local1=(int)&glob3+1;
        
        printf("local1:  %x,%d,%p,%d\n",local1,local1,&local1,(int)&glob3+1); 
       
     

        return 0;
}

glob1:  0,0,0x80497c8,134518729
glob2:  0,0,0x80497c0,134518721
glob3:  0,0,0x80497c4,134518725(0x80497c5)//地址偏一位，没有偏一个int型长度

local1:  80497c5,134518725,0xbf54580c,134518725