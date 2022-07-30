//책 대출
#pragma once
#ifndef _BORROW_H_
#define __BORROW_H__
#include "stdafx.h"

void bookBorrow();


void bookBorrow(){
    FILE* fp;
    FILE *p_file=NULL;
    char ans[100],str[100],book[25];
    int k,find_pos;
    char *p,after[10],before[10],temp[256];
    
    

    printf("**********************\n");
    printf("*****책 대출 화면*****\n");
    printf("**********************\n");
    fp = fopen("booklist.txt", "r");
    printf("대출할 책 이름 :\n");
    scanf("%s",ans);
    
    
    while (!feof(fp)) {
        
        fgets(str, 100, fp);
        sscanf(str,"%s %d",book,&k);
        if (strcmp(ans,book)==0 ) {
            if(k==0){
                printf("책이 없습니다");
                break;
            }
            
            sprintf(before,"%d",k);
            sprintf(after,"%d",k-1);
            
            
        }
    }
    fclose(fp);

    if(0==fopen_s(&p_file,"booklist.txt","r+t")){
        while(fgets(temp,256,p_file)!=NULL){
            p=strstr(temp,before);
            if(p!=NULL){
                find_pos=strlen(temp) - (p-temp)+1;
                fseek(p_file,(-1)*find_pos+1,SEEK_CUR);
                fwrite(after,1,1,p_file);
                fseek(p_file,find_pos-4,SEEK_CUR);
            }
        }
    }
    
    fclose(p_file);
    printf("\n대출이 완료되었습니다");
    printf("\n아무키나 입력하면 화면 이동");
    getch();
    system("CLS");
}



#endif