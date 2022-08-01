#include "stdafx.h"


void bookBorrow(){
  	FILE* fp;
    char ans[100],book[20][20],str[100],title[10];
    int k=0,bookexist=0,num[20];
    char after[10],before[10];
    char *p,c;
    
    

    printf("**********************\n");
    printf("*****책 대출 화면*****\n");
    printf("**********************\n");
    fp = fopen("BookList.txt", "r");
    printf("대출할 책 이름 :\n");
    scanf("%s",ans);
    
    int i=0,cnt=0;
     while((c=fgetc(fp))!=EOF){
        if(c=='\n'){
            cnt++;
        }
    }   
    fclose(fp);   
    
    fp = fopen("BookList.txt", "r");
    while (!feof(fp)) {
        for (i= 0; i<cnt+1;i++){
            fscanf(fp, "%s %d\n", title, &k);

            strcpy(book[i],title);            
            num[i]=k;
            if (strcmp(ans,book[i])==0 ) {
                if(num[i]==0){
                    printf("책이 없습니다");
                    bookexist=1;
                    continue;
                }
                num[i]-=1;
            
            }
            
    

        }
    }
    
    fclose(fp);
    
    fp = fopen("BookList.txt", "w");
    int j=0;
    for(j=0;j<cnt+1;j++){
        if(j==cnt){
            fprintf(fp,"%s %d",book[j],num[j]);
        }
        else{
            fprintf(fp,"%s %d\n",book[j],num[j]);
        }

    }
    fclose(fp);
    
    if(bookexist==1){
        printf("대출할 수 없습니다.");
    }
    else{
        printf("\n대출이 완료되었습니다");
        
    }
    printf("\n아무키나 입력하면 화면 이동");
    getch();
    system("CLS");
}

