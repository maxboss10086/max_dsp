#include <stdio.h>
#include <stdlib.h>

#define num 10
int main(){
    int a[10]   = {0};
    int i;
    int s[num];//定义s为10个数组
    int sum=0;
    int averg=0;
    for(i=0;i<10;i++){//这里不能用if，与verilog不同，if只执行一次
            //verilog有always，所以if是循环执行的
        printf("请输入第%d位同学的成绩",i);
        scanf("%d",&s[i]);
        sum=sum+s[i];
    }
    averg=sum/i;


    printf("成绩输入完毕,平均成绩为%d\n",averg);
    return 0;
}
