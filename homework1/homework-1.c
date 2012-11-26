#include <stdio.h>
int glob1;



int main(void)
{
        printf("glob1:  %x,%d,%p,%p,%d\n",glob1,glob1,&glob1,&((int)&glob1+1),(int)&glob1+1); 

        return 0;
}


//In function 'main':
//Line 8: error: invalid lvalue in unary '&' 为什么不能这样取地址？