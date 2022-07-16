#include <stdio.h>
//함수 선언
void p(int num);

int main(){
    int num=2;
    //printf("num 은 %d 입니다 \n",num);
    p(num);

    num+=3;
    //printf("num 은 %d 입니다 \n",num);
    p(num);

    num-=1;
    //printf("num 은 %d 입니다 \n",num);
    p(num);

    num*=3;
    //printf("num 은 %d 입니다 \n",num);
    p(num);

    num/=6;
    //printf("num 은 %d 입니다 \n",num);
    p(num);

    return 0;
}

//함수 정의
void p(int num){
    printf("num 은 %d 입니다 \n",num);
}