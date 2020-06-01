#include <stdio.h>
#include <stdlib.h>
//void声明一个函数
void  exchange(int *p1, int *p2)//输入2个地址，即输入p1的地址和p2的地址
{//交换的不是地址，而是地址上的数据
    int *t;
    t   = *p1;//取出地址p1中的数据给t
    *p1 = *p2;//取出地址p2中的数据给p1地址上的数据
    *p2 = t;//t赋值给p2地址上的数据
}

int main()
{
    int a=5 , b=6;
    exchange(&a,&b);//取出2个具体地址进行交换
    printf("a=%d,b=%d \n",a,b);
    return 0;
}
