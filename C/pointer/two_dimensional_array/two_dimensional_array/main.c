#include <stdio.h>
#include <stdlib.h>
//二维数组与指针
//指针在二维数组中取值，如同sdram行列寻址
int main()
{
    int a[3][4] = {0,1,2,3,4,5,6,7,8,9,10,11};
    int (*p)[4];//指针数组，即表示数组里面有4个指针
    int i;
    int j;
    p=a;
    for(i=0;i<3;i++){
        for(j=0;j<4;j++){
            printf("%2d ",*(*(p+i)+j) );//取出数组的列地址，加上行地址，再取出就是数组的数据了
            //这与sdram取值同理，先行寻址，再列寻址，才能取出数据
        }
    }
    return 0;
}
