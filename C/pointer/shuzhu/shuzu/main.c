#include <stdio.h>
#include <stdlib.h>

#define num 10
int main(){
    int a[10]   = {0};
    int i;
    int s[num];//����sΪ10������
    int sum=0;
    int averg=0;
    for(i=0;i<10;i++){//���ﲻ����if����verilog��ͬ��ifִֻ��һ��
            //verilog��always������if��ѭ��ִ�е�
        printf("�������%dλͬѧ�ĳɼ�",i);
        scanf("%d",&s[i]);
        sum=sum+s[i];
    }
    averg=sum/i;


    printf("�ɼ��������,ƽ���ɼ�Ϊ%d\n",averg);
    return 0;
}
