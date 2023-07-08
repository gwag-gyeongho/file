#include <stdio.h>
#include <time.h>
#include <stdlib.h>
//물고기가 6마리 살고 있음
//어항에 살고있는데 사막
//사막은 건조해서 물이 빨리 증발
//물이 다 증말하기전에 어항에 물을 줘서 물고기 살려줘

//전역변수 선언
int level;//레벨을 표시할 변수
int arrayFish[6];//물고기 6마리
int *cursor;
//함수 선언
void initinfo();//데이터 처음 상태로 초기화 하기 (처음상태 100)
void printfFishes();//물고기의 상태 출력
void decreaseWater(long elapsedTime);//어항의 물높이가 낮아지게 하기
int checkFishAlive();//물고기가 모두 죽으면 0, 한마리라도 살아있다면 1 반환

int main(){
    long startTime = 0;//게임 시작 시간
    long totalElapsedTime =0;//총 경과 시간
    long prevElapsedTime = 0;// 직전 경과시간 (최근에 물을 준 시간 간격)

    int num;//몇 번 어항에 물을 줄 것인지, 사용자 입력
    initinfo();

    cursor = arrayFish;//cursor[0]... cursor[1]...

    startTime = clock();//현재 시간을 10000 분의 1초 단위로 변환

    while(1){
        printfFishes();//현재 물고기 어항에 물이 얼마나 들었는지 표시
        printf("몇 번 어행에 물을 주시겠어요?");
        scanf("%d",&num);

        if(num <1 || num>6){//입력 숫자 범위를 벗어나면 실행
            printf("\n입력값이 잘못되었습니다\n");
            continue;
        }

        totalElapsedTime = (clock()-startTime)/CLOCKS_PER_SEC;//clock_per_sec 초단위로 바꿔줌
        printf("총 경과 시간 : %ld 초 \n",totalElapsedTime);
        //직전 물 준 시간(마지막으로 물준 시간) 이후로 흐른 시간
        prevElapsedTime = totalElapsedTime - prevElapsedTime;
        printf("최근 경과시간 : %ld 초 \n",prevElapsedTime);

        //어항의 물을 감소(증발)
        decreaseWater(prevElapsedTime);
        //사용자가 입력한 어항에 물을 준다
        //1. 어항의 물이 0이면? 물을 줄 필요x 이미 물고기가 죽음
        if (cursor[num-1]<=0){
            printf("%d 번 물고기는 이미 죽었습니다.. 물을 주지 않습니다 \n",num);

        }
        //2. 어항의 물이 0이 아닌경우? 물을 준다 but 100을 넘지 않는지 체크
        else if(cursor[num-1]+1<=100){
            printf("%d 번 어행에 물을 줍니다 \n\n", num);
            cursor[num-1]+=1;
        }
        //레벨업을 할건지 확인(레벨업은 20초마다 한번씩 수행)
        if (totalElapsedTime/20>level-1){
            level++;
            printf("*** 축 레벨업 ! 기존 %d 레벨에서 %d 레벨로 업그레이드 ***\n\n",level-1,level);

            //최종 레벨 = 5
            if(level==5){
                printf("\n\n축하합니다, 최고 레벨을 달성하였습니다. 게임을 종료합니다");
                exit(0);
            }
        }
        //모든 물고기가 죽었는지 확인
        if(checkFishAlive()==0){
            printf("모든 물고기가...ㅜㅜ흑흑...\n");
            exit(0);
        }
        else{
            //최소 한마리 이상의 물고기가 살아있음
            printf("물고기가 아직 살아있어요!\n");

        }
        prevElapsedTime = totalElapsedTime;
    }

    return 0;
}



void initinfo(){
    level = 1;//게임 레벨 (1~5)
    int i;
    for(i=0; i<6 ;i++){
        arrayFish[i]=100;//어항의 물 높이 (0~100)
    }


}



void printfFishes(){
    printf(" %3d번  %3d번  %3d번  %3d번  %3d번  %3d번\n",1,2,3,4,5,6);
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
        //난이도 조절을 위해 3을 곱해줌
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