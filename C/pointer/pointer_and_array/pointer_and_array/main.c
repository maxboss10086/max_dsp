#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[10];//��������a��10��Ԫ��
    int i;//���������
    int *p;//����ָ��
    for(i=0;i<10;i++){
        scanf("%d",&a[i]);//�����ܵ����ݷ�������
    }
    printf("\n");
    for(p=a;p<(a+10);p++){//��������׵�ַ��p��Ȼ��ָ���ַ����
        printf("%d",*p);//ȡ����ַ�е�����
    }
    return 0;
}
