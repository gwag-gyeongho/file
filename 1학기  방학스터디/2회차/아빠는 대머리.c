#include <stdio.h>
#include <time.h>

int main(){
    srand(time(NULL));//������ �����ϱ� ���� �ڵ�
    printf("\n\n === �ƺ��� ��Ӹ� ���� === \n\n");
    int answer;//���� �����ϴ� ����
    int treatment = rand()%4;//0~3���� ���� ����

    int cntShowBottle =0;//�̹� ���ӿ� ������ ���� ����
    int preCntShowBottle = 0;// �� ���ӿ� ������ �� ����
    //���� �����ִ� �� ������ �ٸ��� �Ͽ� ����� ���

    //��ȸ 3��
    for(int i=1;i<=3;i++){
        int bottle[4]={0,0,0,0};//4���� ��
        do{
            cntShowBottle=rand()%2 +2;//������ �� ����(0~1,+2->2~3)
        }while(cntShowBottle == preCntShowBottle);//������ �� ������ �޶����� ���� ����

        int islncluded = 0;// ������ �� �߿� �߸����� ���ԵǾ����� ����

        printf("> %d ��° �õ� : ",i);
        //������ �� ������ ����

        for(int j=0; j< cntShowBottle; j++){

            int randBottle = rand()%4;//0~3���� ���� ������ ����

            //���õ��� ���� ���� ����ó����(bottle�迭�� �ִ� ���� 0���� 1�� �ٲ���)
            if(bottle[randBottle] == 0){

                bottle[randBottle]=1;

                if (randBottle == treatment){
                    islncluded = 1;//�߸����� ������ ���� ���� ��
                }
            }
            //�̹� ���õ� ���̸� �ٽ� ����
            else{
                //j�� 1�� ���༭ �ݺ��� �ѹ� �� �ϰ� �������
                j--;
            }
        }

        //����ڿ��� ���� ǥ��
        for (int k=0; k<4;k++){
            //������ ���� ������
            if(bottle[k]==1){
                //�迭�� �ε��� ��ȣ�� 0���� �����ϱ� ������ 1�� ������
                printf(" %d ",k+1);
            }
        }
        printf("������ �Ӹ��� �ٸ��ϴ�\n\n");
        //������ �� ������ �߸����� ������ ���� ǥ�� ������ ���� ǥ��
        if(islncluded ==1){
                printf(">> ���� ! �Ӹ��� �����!!\n");
            }
        else{
                printf(">> ���� ! �Ӹ��� ���� �ʾҾ��");
            }
        printf("\n... ��� �Ϸ��� �ƹ�Ű�� ��������...");
        //� Ű�� �Է��Ҷ����� ���
        getchar();
    }
    printf("\n\n�߸����� �� ���ϱ��?");
    scanf("%d",&answer);

    if (answer == treatment+1){
        printf("\n>> �����Դϴ� \n");
    }
    else{
        printf("\n>> �� ! Ʋ�Ⱦ��, ������ %d�Դϴ� \n",treatment+1 );
    }

    return 0;
}

