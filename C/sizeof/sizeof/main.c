#include <stdio.h>
#include <stdlib.h>
//sizeof�ĵ�λ���ֽ�
//һ���ֽ�=8λ
int main()
{
   int      i=123;
   char     j='c';
   float    k=3.14;

   printf("size of int is %d\n",sizeof(i));//int�Ƕ���һ����32λ������ݣ�����sizeof=4
   printf("size of int is %d\n",sizeof(j));
   printf("size of int is %d\n",sizeof(k));
   return 0;
}
