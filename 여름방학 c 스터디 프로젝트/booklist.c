#include "stdafx.h"


void printBookList(){
    printf("*******************\n");
    printf("****책 목록 화면****\n");
    printf("책이름 대출가능권수\n");
    printf("*******************\n");
    FILE* in = fopen("BookList.txt", "r");  
    char buff[MAX] = { 0, };

    fread(buff, 1, MAX, in); 
    printf("%s", buff);

    fclose(in);
    printf("\n아무키나 입력하면 화면 이동");
    getch();
    system("CLS");
    
    

}