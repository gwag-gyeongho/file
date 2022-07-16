#include<stdio.h>

int main(){
    int floor;//정수형 변수 선언
    printf("몇 층으로 쌓겠느냐 ");
    scanf("%d",&floor);//몇층으로 쌓을건지 입력받기
    //2중 for문 실행
    for(int i=0 ; i<floor ; i++){//입력받은 정수의 수만큼 반복
        for(int j=floor ; j>i ; j--){//i가 1씩 늘어나는 것을 이용해 floor부터 1씩 작아지는 별을 공백으로 층층이 쌓는다고 생각하고 공백을 출력
            printf(" ");
        }//피라미드의 규칙이 1층에는 1개, 2층에는 3개 이렇게 2*n+1형식이므로 조건식도 i*2+1을 조건으로 준다
        for(int k=0 ; k<i*2+1 ; k++){//위의 for문의 실행이 끝난 후 위 설명의 조건대로 별을 출력해 피라미드를 만듦
            printf("*");
            
        }
        //한층이 완성되면 다음층으로 넘어가기 위해 줄바꿈
        printf("\n");
    }

    return 0;
}
/*

6을 입력했을때의 예시(0은 공백)

00000*
0000***
000*****
00*******
0*********
***********

 */