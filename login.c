#include "stdafx.h"

void login(){
    char id[20];//아이디
    char password[20];//비밀번호
    char c;
    char d;
    printf("****도서 관리 프로그램****\n");
    while(1){
        printf("아이디 : ");
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

        printf("\n비밀번호 : ");
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
            printf("\n로그인 성공\n");
            break;
        }

        else{
            printf("로그인 실패\n");
            printf("다시 로그인하세요 \n");
            continue;
            
        }
}
    printf("아무키나 입력하면 화면 이동\n");
    getch();
    system("CLS");
}
