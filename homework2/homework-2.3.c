#include <stdio.h>

int glob1;
int glob2;
int glob3;
int main(void)
{
	  printf("glob1:  %x,%s,%d,%p\n",glob1,glob1,glob1,&glob1);   
    printf("glob2:  %x,%s,%d,%p\n",glob2,glob2,glob2,&glob2);   
    printf("glob3:  %x,%s,%d,%p\n\n",glob3,glob3,glob3,&glob3); 
        
    return 0;
}
//glob1:  0,(null),0,0x8049770
//glob2:  0,(null),0,0x8049768
//glob3:  0,(null),0,0x804976c
//这里内存是连续的。。但是不是从大到小，也不是从小到大。每个变量分配四位


#include <stdio.h>

char cglob1;
char cglob2;
char cglob3;
int main(void)
{
	  printf("cglob1:  %x,%s,%d,%p\n",cglob1,cglob1,cglob1,&cglob1);   
    printf("cglob2:  %x,%s,%d,%p\n",cglob2,cglob2,cglob2,&cglob2);   
    printf("cglob3:  %x,%s,%d,%p\n\n",cglob3,cglob3,cglob3,&cglob3); 
        
    return 0;
}


//cglob1:  0,(null),0,0x804977c
//cglob2:  0,(null),0,0x804977d
//cglob3:  0,(null),0,0x804977e
//从上到下连续分配一位给char型	
	
//short型
#include <stdio.h>
short sglob1;
short sglob2;
short sglob3;
int main(void)
{
	  printf("sglob1:  %x,%s,%d,%p\n",sglob1,sglob1,sglob1,&sglob1);   
    printf("sglob2:  %x,%s,%d,%p\n",sglob2,sglob2,sglob2,&sglob2);   
    printf("sglob3:  %x,%s,%d,%p\n\n",sglob3,sglob3,sglob3,&sglob3); 
        
    return 0;
}

//sglob1:  0,(null),0,0x8049780
//sglob2:  0,(null),0,0x804977e
//sglob3:  0,(null),0,0x804977c
//从下到上连续分配两位位给short型


#include <stdio.h>
float fglob1;
float fglob2;
float fglob3;
int main(void)
{
	
	  printf("fglob1:  %x,%s,%d,%p\n",fglob1,fglob1,fglob1,&fglob1);   
    printf("fglob2:  %x,%s,%d,%p\n",fglob2,fglob2,fglob2,&fglob2);   
    printf("fglob3:  %x,%s,%d,%p\n\n",fglob3,fglob3,fglob3,&fglob3); 
        
    return 0;
}

//fglob1:  0,(null),0,(nil)
//fglob2:  0,(null),0,(nil)
//fglob3:  0,(null),0,(nil)
//初始不分配空间？