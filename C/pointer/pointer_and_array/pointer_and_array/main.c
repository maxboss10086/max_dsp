#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[10];//定义数组a有10个元素
    int i;//定义计数器
    int *p;//定义指针
    for(i=0;i<10;i++){
        scanf("%d",&a[i]);//将接受的数据放入数组
    }
    printf("\n");
    for(p=a;p<(a+10);p++){//将数组的首地址给p，然后指针地址自增
        printf("%d",*p);//取出地址中的数据
    }
    return 0;
}
