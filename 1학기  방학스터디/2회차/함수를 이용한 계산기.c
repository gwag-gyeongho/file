#include <stdio.h>

void p(int num);
int add(int num1, int num2);
int sub(int num1, int num2);
int mul(int num1, int num2);
int div(int num1, int num2);

int main(){
    int num =2;
    num= add(num,3);
    p(num);

    num=sub(num,1);
    p(num);

    num=mul(num,3);
    p(num);

    num=div(num,6);
    p(num);

    return 0;
}

int add(int num1,int num2){
    return num1+ num2;
}
int sub(int num1, int num2){
    return num1-num2;
}
int mul(int num1, int num2){
    return num1*num2;
}
int div(int num1, int num2){
    return num1/num2;
}
void p(int num){
    printf("num 은 %d 입니다 \n",num);
}