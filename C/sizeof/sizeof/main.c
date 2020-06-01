#include <stdio.h>
#include <stdlib.h>
//sizeof的单位是字节
//一个字节=8位
int main()
{
   int      i=123;
   char     j='c';
   float    k=3.14;

   printf("size of int is %d\n",sizeof(i));//int是定义一个个32位宽的数据，所以sizeof=4
   printf("size of int is %d\n",sizeof(j));
   printf("size of int is %d\n",sizeof(k));
   return 0;
}
