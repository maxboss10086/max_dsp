#include <stdio.h>
#include <stdlib.h>
//void����һ������
void  exchange(int *p1, int *p2)//����2����ַ��������p1�ĵ�ַ��p2�ĵ�ַ
{//�����Ĳ��ǵ�ַ�����ǵ�ַ�ϵ�����
    int *t;
    t   = *p1;//ȡ����ַp1�е����ݸ�t
    *p1 = *p2;//ȡ����ַp2�е����ݸ�p1��ַ�ϵ�����
    *p2 = t;//t��ֵ��p2��ַ�ϵ�����
}

int main()
{
    int a=5 , b=6;
    exchange(&a,&b);//ȡ��2�������ַ���н���
    printf("a=%d,b=%d \n",a,b);
    return 0;
}
