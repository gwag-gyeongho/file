//å ��� Ȯ��
#pragma once
#ifndef _BOOKLIST_H_
#define __BOOKLIST_H__
#include "stdafx.h"
#define MAX 1000

void printBookList();

void printBookList(){
    printf("*******************\n");
    printf("****å ��� ȭ��****\n");
    printf("å�̸� ���Ⱑ�ɱǼ�\n");
    printf("*******************\n");
    FILE* fp = fopen("booklist.txt", "r");  
    char buffer[MAX] = { 0, };

    fread(buffer, 1, MAX, fp); 
    printf("%s", buffer);

    fclose(fp);
    printf("\n�ƹ�Ű�� �Է��ϸ� ȭ�� �̵�");
    getch();
    system("CLS");
    
    

}

#endif