#include "stdafx.h"

void bookReturn(){
  	FILE* in;
    char ans[100],book[20][20],str[100],title[10];
    int k=0,num[20];
    char after[10],before[10];
    char *p,c;
    
    

    printf("**********************\n");
    printf("*****책 반납 화면*****\n");
    printf("**********************\n");
    in = fopen("BookList.txt", "r");
    printf("반납할 책 이름 :\n");
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
                
                num[i]+=1;
            
            }
            
    

        }
    }
    
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
    printf("\n반납이 완료되었습니다");
    printf("\n아무키나 입력하면 화면 이동");
    getch();
    system("CLS");
}
