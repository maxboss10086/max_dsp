#include <stdio.h>
#include <stdlib.h>

int main()
{
    char    a[] = "i love you";//定义一个字符串数组
    char    b[10];//等下要把a的字符复制到b，所以b也是10
    char    *p1;
    char    *p2;
    int     i;

    p1=a;//将数组a的首地址辅助给p1
    p2=b;//将数组b的首地址辅助给p2
    for(;*p1!='\0';p1++,p2++){//如果p1指针取出的字符串不等于\0，则地址自增
        *p2=*p1;
    }
    *p2 ='\0';
    printf("string a is : %s\n",a);
    printf("string b is :");
    for(i=0;b[i]!='\0';i++){
        printf("%c",b[i]);
    }
    printf("\n");
}
