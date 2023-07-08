#include <stdio.h>
#include<time.h>
//�Լ�����
int getRandomNumber(int level);
void showQuestion(int level, int num1, int num2);
void success();
void fail();
//�����Լ�
int main(){
    //���� 5���� �ְ�, �� ������ ���� ����� ���� ��� ����
    //������ ���, Ʋ���� ����

    srand(time(NULL));
    int count = 0;
    for(int i = 1; i<=5; i++){
        int num1=getRandomNumber(i);//i�� Ŀ���� ���� ������ ������ ���� Ŀ��
        int num2=getRandomNumber(i);
        
        showQuestion(i,num1,num2);//������ ���

        int answer = -1;
        scanf("%d",&answer);//���� �Է� ����
        if(answer == -1){
            printf("���α׷��� �����մϴ� \n");
            exit(0);
        }   
        else if (answer == num1 * num2){//�����̸� �����̶�� �ϰ� count++
            success();
            count++;
        }
        else{//Ʋ���� Ʋ�ȴٰ� ���
            fail();
        }
    }
    //��� ������� ���
    printf("\n\n ����� 5���� ��й�ȣ �� %d ���� ������ϴ�\n",count);

    return 0;
}
//�Լ� ����
int getRandomNumber(int level){//�ݺ��Ҽ��� ������ ���� Ŀ���� ���� ����
    return rand() % (level*7)+1;
}


void showQuestion(int level, int num1, int num2){//������ ���
    printf("\n\n\n#####%d ��° ��й�ȣ #####\n", level);
    printf("\n      %d x %d ? \n\n",num1,num2);
    printf("################################\n");
    printf("\n��й�ȣ�� �Է��ϼ���(���� : -1)>>");
}

void success(){
    printf("\n >> Good! �����Դϴ� \n");
}

void fail(){
    printf("\n >> Fail! Ʋ�Ƚ��ϴ� \n");
}