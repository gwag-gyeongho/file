#include "stdafx.h"


void printBookList(){
    printf("*******************\n");
    printf("****책 목록 화면****\n");
    printf("책이름 대출가능권수\n");
    printf("*******************\n");
    FILE* fp = fopen("BookList.txt", "r");  
    char buffer[MAX] = { 0, };

    fread(buffer, 1, MAX, fp); 
    printf("%s", buffer);

    fclose(fp);
    printf("\n아무키나 입력하면 화면 이동");
    getch();
    system("CLS");
    
    

}