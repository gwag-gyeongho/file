#include "stdafx.h"

void login(){
    char id[20];//���̵�
    char password[20];//��й�ȣ
    char c;
    char d;
    printf("****���� ���� ���α׷�****\n");
    while(1){
        printf("���̵� : ");
        int i=0;
        while(1){
            d=getch();
            if(d == 13){
                id[i]='\0';
                break;

            }
            else{
                printf("%c",d);
                id[i] = d;
            }
            i++;
        }

        printf("\n��й�ȣ : ");
        int j=0;
        while(1){
            c=getch();
            if(c == 13){
                password[j]='\0';
                break;

            }
            else{
                printf("*");
                password[j] = c;
            }
            j++;
        }

        if(strcmp(id,"admin")==0 && (strcmp(password,"1234")==0)){
            printf("\n�α��� ����\n");
            break;
        }

        else{
            printf("�α��� ����\n");
            printf("�ٽ� �α����ϼ��� \n");
            continue;
            
        }
}
    printf("�ƹ�Ű�� �Է��ϸ� ȭ�� �̵�\n");
    getch();
    system("CLS");
}
