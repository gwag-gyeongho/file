#include "stdafx.h"
#define max 1000

int main(){
    int num=0;
    login();

    while(1){
        printDisplay();
        printf("���ϴ� �۾� ��ȣ : ");
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
                printf("���α׷��� ����˴ϴ�\n");
                exit(0);
                break;
            
            default:
                printf("\n�Է� ������ ������ϴ�\n");
                printf("\n�ƹ�Ű�� �Է��ϸ� ȭ�� �̵�\n");
        }
        
    }
    return 0;
}

