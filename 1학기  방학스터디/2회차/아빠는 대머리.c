#include <stdio.h>
#include <time.h>

int main(){
    srand(time(NULL));//난수를 생성하기 위한 코드
    printf("\n\n === 아빠는 대머리 게임 === \n\n");
    int answer;//답을 저장하는 변수
    int treatment = rand()%4;//0~3까지 난수 생성

    int cntShowBottle =0;//이번 게임에 보여줄 병의 개수
    int preCntShowBottle = 0;// 앞 게임에 보여준 병 개수
    //서로 보여주는 병 갯수를 다르게 하여 정답률 향상

    //기회 3번
    for(int i=1;i<=3;i++){
        int bottle[4]={0,0,0,0};//4개의 병
        do{
            cntShowBottle=rand()%2 +2;//보여줄 병 개수(0~1,+2->2~3)
        }while(cntShowBottle == preCntShowBottle);//보여줄 병 개수가 달라질때 까지 실행

        int islncluded = 0;// 보여줄 병 중에 발모제가 포함되었는지 여부

        printf("> %d 번째 시도 : ",i);
        //보여줄 병 종류를 선택

        for(int j=0; j< cntShowBottle; j++){

            int randBottle = rand()%4;//0~3까지 난수 생성해 저장

            //선택되지 않은 병을 선택처리함(bottle배열에 있는 값을 0에서 1로 바꿔줌)
            if(bottle[randBottle] == 0){

                bottle[randBottle]=1;

                if (randBottle == treatment){
                    islncluded = 1;//발모제가 선택한 병에 포함 됨
                }
            }
            //이미 선택된 병이면 다시 선택
            else{
                //j에 1을 빼줘서 반복을 한번 더 하게 만들어줌
                j--;
            }
        }

        //사용자에게 문제 표시
        for (int k=0; k<4;k++){
            //선택한 병을 보여줌
            if(bottle[k]==1){
                //배열의 인덱스 번호는 0부터 시작하기 때문에 1을 더해줌
                printf(" %d ",k+1);
            }
        }
        printf("물약을 머리에 바릅니다\n\n");
        //보여준 병 종류에 발모제가 있으면 성공 표시 없으면 실패 표시
        if(islncluded ==1){
                printf(">> 성공 ! 머리가 났어요!!\n");
            }
        else{
                printf(">> 실패 ! 머리가 나지 않았어요");
            }
        printf("\n... 계속 하려면 아무키나 누르세요...");
        //어떤 키를 입력할때까지 대기
        getchar();
    }
    printf("\n\n발모제는 몇 번일까요?");
    scanf("%d",&answer);

    if (answer == treatment+1){
        printf("\n>> 정답입니다 \n");
    }
    else{
        printf("\n>> 땡 ! 틀렸어요, 정답은 %d입니다 \n",treatment+1 );
    }

    return 0;
}

