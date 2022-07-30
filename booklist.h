//책 목록 확인
#pragma once
#ifndef _BOOKLIST_H_
#define __BOOKLIST_H__
#include "stdafx.h"
#define MAX 1000

void printBookList();

void printBookList(){
    printf("*******************\n");
    printf("****책 목록 화면****\n");
    printf("책이름 대출가능권수\n");
    printf("*******************\n");
    FILE* fp = fopen("booklist.txt", "r");  
    char buffer[MAX] = { 0, };

    fread(buffer, 1, MAX, fp); 
    printf("%s", buffer);

    fclose(fp);
    printf("\n아무키나 입력하면 화면 이동");
    getch();
    system("CLS");
    
    

}

#endif