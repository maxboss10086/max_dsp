#include <stdio.h>
#include <stdlib.h>

//ָ��=��ַ
int main()
{
    int i=2000;
    int *p;//����һ����ַ
    p =&i;//��i�ĵ�ַ����p
    printf("%d\n",*p);//�����*����ȡ����ַ�ϵ�����
    return 0;
}
