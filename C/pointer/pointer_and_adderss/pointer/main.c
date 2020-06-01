#include <stdio.h>
#include <stdlib.h>

//指针=地址
int main()
{
    int i=2000;
    int *p;//定义一个地址
    p =&i;//将i的地址给到p
    printf("%d\n",*p);//这里的*就是取出地址上的数据
    return 0;
}
