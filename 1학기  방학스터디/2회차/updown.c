#include <stdio.h>

int main(){
    srand(time(NULL));
    int num =rand()%100+1;//1~ 100 ������ ����
    int answer =0;
    int chance = 5;//��ȸ 5��
    while (chance >0){
        printf("������ȸ %d �� \n",chance--);
        printf("���ڸ� ���������� (1~100)  : ");
        scanf("%d",&answer);

        if(answer > num){
            printf("DOWN \n\n");

        }
        else if ( answer<num){
            printf("UP\n\n");
        }
        else if(answer == num){
            printf("�����Դϴ� ! \n\n");
            break;
        }
        else
        {
            printf("�� �� ���� ������ �߻��߾��\n\n");
        }
        if (chance==0){
            printf("��� ��ȸ�� �� ����ϼ̳׿�");
        }
    }
    
    
    return 0;
}