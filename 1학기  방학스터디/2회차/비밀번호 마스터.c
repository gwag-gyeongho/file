#include <stdio.h>
#include<time.h>
//함수선언
int getRandomNumber(int level);
void showQuestion(int level, int num1, int num2);
void success();
void fail();
//메인함수
int main(){
    //문이 5개가 있고, 각 문마다 점점 어려운 수식 퀴즈가 출제
    //맞히명 통과, 틀리면 실패

    srand(time(NULL));
    int count = 0;
    for(int i = 1; i<=5; i++){
        int num1=getRandomNumber(i);//i가 커짐에 따라 난수의 범위가 점점 커짐
        int num2=getRandomNumber(i);
        
        showQuestion(i,num1,num2);//문제를 출력

        int answer = -1;
        scanf("%d",&answer);//답을 입력 받음
        if(answer == -1){
            printf("프로그램을 종료합니다 \n");
            exit(0);
        }   
        else if (answer == num1 * num2){//정답이면 정답이라고 하고 count++
            success();
            count++;
        }
        else{//틀리면 틀렸다고 출력
            fail();
        }
    }
    //몇개를 맞췄는지 출력
    printf("\n\n 당신은 5개의 비밀번호 중 %d 개를 맞췄습니다\n",count);

    return 0;
}
//함수 정의
int getRandomNumber(int level){//반복할수록 범위가 점점 커지는 난수 생성
    return rand() % (level*7)+1;
}


void showQuestion(int level, int num1, int num2){//문제를 출력
    printf("\n\n\n#####%d 번째 비밀번호 #####\n", level);
    printf("\n      %d x %d ? \n\n",num1,num2);
    printf("################################\n");
    printf("\n비밀번호를 입력하세요(종료 : -1)>>");
}

void success(){
    printf("\n >> Good! 정답입니다 \n");
}

void fail(){
    printf("\n >> Fail! 틀렸습니다 \n");
}