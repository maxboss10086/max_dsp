#include <stdio.h>
#include <stdlib.h>

int main()
{
    char    a[] = "i love you";//����һ���ַ�������
    char    b[10];//����Ҫ��a���ַ����Ƶ�b������bҲ��10
    char    *p1;
    char    *p2;
    int     i;

    p1=a;//������a���׵�ַ������p1
    p2=b;//������b���׵�ַ������p2
    for(;*p1!='\0';p1++,p2++){//���p1ָ��ȡ�����ַ���������\0�����ַ����
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
