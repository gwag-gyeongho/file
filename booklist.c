#include "stdafx.h"


void printBookList(){
    printf("*******************\n");
    printf("****å ��� ȭ��****\n");
    printf("å�̸� ���Ⱑ�ɱǼ�\n");
    printf("*******************\n");
    FILE* fp = fopen("BookList.txt", "r");  
    char buffer[MAX] = { 0, };

    fread(buffer, 1, MAX, fp); 
    printf("%s", buffer);

    fclose(fp);
    printf("\n�ƹ�Ű�� �Է��ϸ� ȭ�� �̵�");
    getch();
    system("CLS");
    
    

}