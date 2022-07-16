#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int arrayAnimal[4][5];//20���� ī�� ǥ��
int checkAnimal[4][5];
char *strAnimal[10];
void initAnimalArray();//�迭 �ʱ�ȭ
void initAnimalName();//���� �̸� �ʱ�ȭ
void shuffleAnimal();//���� ����
int getEmptyPosition();
int conv_pos_x(int x);//�Է� ���� ���� �� ã���ִ� ����
int conv_pos_y(int y);//�Է� ���� ���� �� ã���ִ� ����
void printAnimals();//���� ��ġ ���(���� �ϴ� ������״� �Ⱥ��̰�)
void printQuestion();//���� ���(������ ���߸� ���� ī��� ���� �̸��� ���̰� ������)
int foundAllanimals();//��� ī�尡 �������� 1, �������� ���� ī�尡 ������ 0 ��ȯ

int main(){  
    srand(time(NULL));

    initAnimalArray();
    initAnimalName();

    shuffleAnimal();

    int failCount = 0;//Ʋ��Ƚ�� ����

    while(1){
        int select1=0;
        int select2=0;

        printAnimals();//������ġ ���
        printQuestion();//���� ���
        printf("������ ī�带 2�� ������ : ");
        scanf("%d %d",&select1,&select2);//������ ī�� ��ȣ �Է� �ޱ�
        if(select1==select2){// �Է¹��� �� ���� ���� ��� ���� �ڵ� ������ �� ���� �ǵ��ư�
            continue; 
        }

        int firstSelect_x = conv_pos_x(select1);
        int firstSelect_y = conv_pos_y(select1);

        int secondSelect_x = conv_pos_x(select2);
        int secondSelect_y = conv_pos_y(select2);
        //���� ������ ���
        if((checkAnimal[firstSelect_x][firstSelect_y]==0
        && checkAnimal[secondSelect_x][secondSelect_y]==0)
        &&
        (arrayAnimal[firstSelect_x][firstSelect_y]
        ==arrayAnimal[secondSelect_x][secondSelect_y])){
            printf("\n\n ����! : %s�� �߰�\n\n",strAnimal[arrayAnimal[firstSelect_x][firstSelect_y]]);
            checkAnimal[firstSelect_x][firstSelect_y]=1;
            checkAnimal[secondSelect_x][secondSelect_y]=1;
        }
        //�ٸ� ������ ���
        else{
            printf("\n\n��!! (Ʋ�Ȱų�, �̹� ������ ī���Դϴ�)\n");
            printf("%d : %s\n",select1,strAnimal[arrayAnimal[firstSelect_x][firstSelect_y]]);
            printf("%d : %s\n",select2,strAnimal[arrayAnimal[secondSelect_x][secondSelect_y]]);
            printf("\n\n");
            failCount++;
        }

        if(foundAllanimals()==1){//��� ī�尡 �������°�?
            printf("\n\n �����մϴ� ! ��� ������ �� ã�ҳ׿�\n");
            printf("���ݱ��� �� %d�� �Ǽ��Ͽ����ϴ�\n",failCount);
            break;
        }
    }

    return 0;
}


void initAnimalArray(){
	int i,j;
	for(i = 0; i<4;i++){

        for (j=0;j<5;j++){
            arrayAnimal[i][j]=-1;
        }
    }
}
void initAnimalName(){
    strAnimal[0]="������";
    strAnimal[1]="�ϸ�";
    strAnimal[2]="������";
    strAnimal[3]="�����";
    strAnimal[4]="����";
    strAnimal[5]="�ڳ���";
    strAnimal[6]="�⸰";
    strAnimal[7]="��Ÿ";
    strAnimal[8]="Ÿ��";
    strAnimal[9]="ȣ����";

}

int getEmptyPosition(){
    while(1){
        int randPos = rand()%20;
        int x = conv_pos_x(randPos);
        int y = conv_pos_y(randPos);
        if (arrayAnimal[x][y]==-1){
            return randPos;
        }
    }
    return 0;
}

void shuffleAnimal(){
	int i,j;
    for(i = 0; i<10 ; i++){
        for (j =0 ; j<2; j++){
            int pos = getEmptyPosition();
            int x = conv_pos_x(pos);
            int y = conv_pos_y(pos);
            arrayAnimal[x][y] = i;
        }
    }
}



int conv_pos_x(int x){
    return x/5;
}

int conv_pos_y(int y){
    return y%5;
}

void printAnimals(){
	int i,j;
    printf("\n=======�̰� ����ε�..���� �����ݴϴ�======\n");
    for (i=0; i<4; i++){
        for(j=0; j<5;j++){
            printf("%8s",strAnimal[arrayAnimal[i][j]]);
        }
        printf("\n");

    }
    printf("\n===================================\n\n");
}

void printQuestion(){
    printf("\n\n(����)\n");
	int i,j;
    int seq = 0;
    for(i =0;i<4;i++){
        for(j=0;j<5;j++){
            if(checkAnimal[i][j] !=0){
                printf("%8s",strAnimal[arrayAnimal[i][j]]);
            }
            else{
                printf("%8d",seq);
            }
            seq++;
        }
        printf("\n");
    }
}

int foundAllanimals(){
	int i,j;
    for(i=0;i<4;i++){
        for(j=0;j<5;j++){
            if(checkAnimal[i][j]==0){
                return 0;
            }
        }
    }
    return 1; 
}