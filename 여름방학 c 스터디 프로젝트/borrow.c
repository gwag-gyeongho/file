#include "stdafx.h"


void bookBorrow(){
  	FILE* in;
    char ans[100],book[20][20],str[100],title[10];
    int k=0,bookexist=0,num[20];
    char after[10],before[10];
    char *p,c;
    
    

    printf("**********************\n");
    printf("*****책 대출 화면*****\n");
    printf("**********************\n");
    in = fopen("BookList.txt", "r");
    printf("대출할 책 이름 :\n");
    scanf("%s",ans);
    
    int i=0,cnt=0;
     while((c=fgetc(in))!=EOF){
        if(c=='\n'){
            cnt++;
        }
    }   
    fclose(in);   
    
    in = fopen("BookList.txt", "r");
    while (!feof(in)) {
        for (i= 0; i<cnt+1;i++){
            fscanf(in, "%s %d\n", title, &k);

            strcpy(book[i],title);            
            num[i]=k;
            if (strcmp(ans,book[i])==0 ) {
                if(num[i]==0){
                    printf("책이 없습니다\n");
                    bookexist=1;
                    break;
                }
                num[i]-=1;
            
            }
            else{
                printf("존재하지 않는 책입니다\n");
                bookexist=1;
                break;
            }
            
    

        }
        if(bookexist==1){
            break;
        }
    }
    if(bookexist!=1){
        fclose(in);
    
        in = fopen("BookList.txt", "w");
        int j=0;
        for(j=0;j<cnt+1;j++){
            if(j==cnt){
                inrintf(in,"%s %d",book[j],num[j]);
            }
            else{
                inrintf(in,"%s %d\n",book[j],num[j]);
            }

        }
        fclose(in);
    }
    else{
        printf("");
    }
    
    if(bookexist==1){
        printf("\n대출할 수 없습니다.\n");
    }
    else{
        printf("\n대출이 완료되었습니다\n");
        
    }
    printf("\n아무키나 입력하면 화면 이동");
    getch();
    system("CLS");
}

