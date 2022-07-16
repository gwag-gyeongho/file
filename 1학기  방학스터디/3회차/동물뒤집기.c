#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int arrayAnimal[4][5];//20장의 카드 표시
int checkAnimal[4][5];
char *strAnimal[10];
void initAnimalArray();//배열 초기화
void initAnimalName();//동물 이름 초기화
void shuffleAnimal();//동물 섞기
int getEmptyPosition();
int conv_pos_x(int x);//입력 받은 수의 열 찾아주는 변수
int conv_pos_y(int y);//입력 받은 수의 행 찾아주는 변수
void printAnimals();//동물 위치 출력(게임 하는 사람한테는 안보이게)
void printQuestion();//문제 출력(문제를 맞추면 맞춘 카드는 동물 이름이 보이게 뒤집힘)
int foundAllanimals();//모든 카드가 뒤집히면 1, 뒤집히지 않은 카드가 있으면 0 반환

int main(){  
    srand(time(NULL));

    initAnimalArray();
    initAnimalName();

    shuffleAnimal();

    int failCount = 0;//틀린횟수 세기

    while(1){
        int select1=0;
        int select2=0;

        printAnimals();//동물위치 출력
        printQuestion();//문제 출력
        printf("뒤집을 카드를 2개 고르세요 : ");
        scanf("%d %d",&select1,&select2);//뒤집을 카드 번호 입력 받기
        if(select1==select2){// 입력받은 두 수가 같은 경우 밑의 코드 생략후 맨 위로 되돌아감
            continue; 
        }

        int firstSelect_x = conv_pos_x(select1);
        int firstSelect_y = conv_pos_y(select1);

        int secondSelect_x = conv_pos_x(select2);
        int secondSelect_y = conv_pos_y(select2);
        //같은 동물인 경우
        if((checkAnimal[firstSelect_x][firstSelect_y]==0
        && checkAnimal[secondSelect_x][secondSelect_y]==0)
        &&
        (arrayAnimal[firstSelect_x][firstSelect_y]
        ==arrayAnimal[secondSelect_x][secondSelect_y])){
            printf("\n\n 빙고! : %s를 발견\n\n",strAnimal[arrayAnimal[firstSelect_x][firstSelect_y]]);
            checkAnimal[firstSelect_x][firstSelect_y]=1;
            checkAnimal[secondSelect_x][secondSelect_y]=1;
        }
        //다른 동물인 경우
        else{
            printf("\n\n땡!! (틀렸거나, 이미 뒤집힌 카드입니다)\n");
            printf("%d : %s\n",select1,strAnimal[arrayAnimal[firstSelect_x][firstSelect_y]]);
            printf("%d : %s\n",select2,strAnimal[arrayAnimal[secondSelect_x][secondSelect_y]]);
            printf("\n\n");
            failCount++;
        }

        if(foundAllanimals()==1){//모든 카드가 뒤집혔는가?
            printf("\n\n 축하합니다 ! 모든 동물을 다 찾았네요\n");
            printf("지금까지 총 %d번 실수하였습니다\n",failCount);
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
    strAnimal[0]="원숭이";
    strAnimal[1]="하마";
    strAnimal[2]="강아지";
    strAnimal[3]="고양이";
    strAnimal[4]="돼지";
    strAnimal[5]="코끼리";
    strAnimal[6]="기린";
    strAnimal[7]="낙타";
    strAnimal[8]="타조";
    strAnimal[9]="호랑이";

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
    printf("\n=======이건 비밀인데..몰래 보여줍니다======\n");
    for (i=0; i<4; i++){
        for(j=0; j<5;j++){
            printf("%8s",strAnimal[arrayAnimal[i][j]]);
        }
        printf("\n");

    }
    printf("\n===================================\n\n");
}

void printQuestion(){
    printf("\n\n(문제)\n");
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