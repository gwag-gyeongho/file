#include <stdio.h>
//�Լ� ����
void p(int num);

int main(){
    int num=2;
    //printf("num �� %d �Դϴ� \n",num);
    p(num);

    num+=3;
    //printf("num �� %d �Դϴ� \n",num);
    p(num);

    num-=1;
    //printf("num �� %d �Դϴ� \n",num);
    p(num);

    num*=3;
    //printf("num �� %d �Դϴ� \n",num);
    p(num);

    num/=6;
    //printf("num �� %d �Դϴ� \n",num);
    p(num);

    return 0;
}

//�Լ� ����
void p(int num){
    printf("num �� %d �Դϴ� \n",num);
}