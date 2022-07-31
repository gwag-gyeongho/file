#include "stdafx.h"
#define max 1000

int main(){
    int num=0;
    login();

    while(1){
        printDisplay();
        printf("원하는 작업 번호 : ");
        scanf("%d",&num);
        system("CLS");
        switch(num){
            case 1:
                printBookList();                          
                break;

            case 2:
                bookBorrow();              
                break;

            case 3:
                bookReturn();            
                break;

            case 4:
                printf("프로그램이 종료됩니다\n");
                exit(0);
                break;
            
            default:
                printf("\n입력 범위를 벗어났습니다\n");
                printf("\n아무키나 입력하면 화면 이동\n");
        }
        
    }
    return 0;
}

