#include "stdafx.h"


void printBookList(){
    printf("*******************\n");
    printf("****å ��� ȭ��****\n");
    printf("å�̸� ���Ⱑ�ɱǼ�\n");
    printf("*******************\n");
    FILE* in = fopen("BookList.txt", "r");  
    char buff[MAX] = { 0, };

    fread(buff, 1, MAX, in); 
    printf("%s", buff);

    fclose(in);
    printf("\n�ƹ�Ű�� �Է��ϸ� ȭ�� �̵�");
    getch();
    system("CLS");
    
    

}