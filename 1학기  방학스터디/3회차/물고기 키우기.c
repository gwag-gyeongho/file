#include <stdio.h>
#include <time.h>
#include <stdlib.h>
//����Ⱑ 6���� ��� ����
//���׿� ����ִµ� �縷
//�縷�� �����ؼ� ���� ���� ����
//���� �� �����ϱ����� ���׿� ���� �༭ ����� �����

//�������� ����
int level;//������ ǥ���� ����
int arrayFish[6];//����� 6����
int *cursor;
//�Լ� ����
void initinfo();//������ ó�� ���·� �ʱ�ȭ �ϱ� (ó������ 100)
void printfFishes();//������� ���� ���
void decreaseWater(long elapsedTime);//������ �����̰� �������� �ϱ�
int checkFishAlive();//����Ⱑ ��� ������ 0, �Ѹ����� ����ִٸ� 1 ��ȯ

int main(){
    long startTime = 0;//���� ���� �ð�
    long totalElapsedTime =0;//�� ��� �ð�
    long prevElapsedTime = 0;// ���� ����ð� (�ֱٿ� ���� �� �ð� ����)

    int num;//�� �� ���׿� ���� �� ������, ����� �Է�
    initinfo();

    cursor = arrayFish;//cursor[0]... cursor[1]...

    startTime = clock();//���� �ð��� 10000 ���� 1�� ������ ��ȯ

    while(1){
        printfFishes();//���� ����� ���׿� ���� �󸶳� ������� ǥ��
        printf("�� �� ���࿡ ���� �ֽðھ��?");
        scanf("%d",&num);

        if(num <1 || num>6){//�Է� ���� ������ ����� ����
            printf("\n�Է°��� �߸��Ǿ����ϴ�\n");
            continue;
        }

        totalElapsedTime = (clock()-startTime)/CLOCKS_PER_SEC;//clock_per_sec �ʴ����� �ٲ���
        printf("�� ��� �ð� : %ld �� \n",totalElapsedTime);
        //���� �� �� �ð�(���������� ���� �ð�) ���ķ� �帥 �ð�
        prevElapsedTime = totalElapsedTime - prevElapsedTime;
        printf("�ֱ� ����ð� : %ld �� \n",prevElapsedTime);

        //������ ���� ����(����)
        decreaseWater(prevElapsedTime);
        //����ڰ� �Է��� ���׿� ���� �ش�
        //1. ������ ���� 0�̸�? ���� �� �ʿ�x �̹� ����Ⱑ ����
        if (cursor[num-1]<=0){
            printf("%d �� ������ �̹� �׾����ϴ�.. ���� ���� �ʽ��ϴ� \n",num);

        }
        //2. ������ ���� 0�� �ƴѰ��? ���� �ش� but 100�� ���� �ʴ��� üũ
        else if(cursor[num-1]+1<=100){
            printf("%d �� ���࿡ ���� �ݴϴ� \n\n", num);
            cursor[num-1]+=1;
        }
        //�������� �Ұ��� Ȯ��(�������� 20�ʸ��� �ѹ��� ����)
        if (totalElapsedTime/20>level-1){
            level++;
            printf("*** �� ������ ! ���� %d �������� %d ������ ���׷��̵� ***\n\n",level-1,level);

            //���� ���� = 5
            if(level==5){
                printf("\n\n�����մϴ�, �ְ� ������ �޼��Ͽ����ϴ�. ������ �����մϴ�");
                exit(0);
            }
        }
        //��� ����Ⱑ �׾����� Ȯ��
        if(checkFishAlive()==0){
            printf("��� ����Ⱑ...�̤�����...\n");
            exit(0);
        }
        else{
            //�ּ� �Ѹ��� �̻��� ����Ⱑ �������
            printf("����Ⱑ ���� ����־��!\n");

        }
        prevElapsedTime = totalElapsedTime;
    }

    return 0;
}



void initinfo(){
    level = 1;//���� ���� (1~5)
    int i;
    for(i=0; i<6 ;i++){
        arrayFish[i]=100;//������ �� ���� (0~100)
    }


}



void printfFishes(){
    printf(" %3d��  %3d��  %3d��  %3d��  %3d��  %3d��\n",1,2,3,4,5,6);
    int i;
    for(i=0; i<6; i++){
        printf(" %3d ",arrayFish[i]);
    }
    printf("\n\n");
}


void decreaseWater(long elapsedTime){
    int i;
    for(i=0; i<6; i++){
        arrayFish[i] -=(level * 3 * (int)elapsedTime );
        //���̵� ������ ���� 3�� ������
        if(arrayFish[i]<0){
            arrayFish[i]=0;
        }

    }
}

int checkFishAlive(){
    int i;
    for(i =0; i<6 ; i++){
        if(arrayFish[i]>0){
            return 1;
        } 
    }
    return 0;
}