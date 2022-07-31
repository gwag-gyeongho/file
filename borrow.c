#include "stdafx.h"


void bookBorrow(){
    FILE* fp;
    FILE *p_file=NULL;
    char ans[100],str[100],book[25];
    int k,find_pos;
    char *p,after[10],before[10],temp[256];
    char save[30][20];
    

    printf("**********************\n");
    printf("*****책 대출 화면*****\n");
    printf("**********************\n");
    fp = fopen("BookList.txt", "r");
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
            
            break;

            
        }
    }
    
    fclose(fp);
    
    if(0==fopen_s(&p_file,"BookList.txt","r+t")){
        int i=0;
        int sum=0;
        while(fgets(temp,256,p_file)!=NULL){
            p=strstr(temp,book);
            strcpy(save[i],temp);
            
            sum+=strlen(save[i]);
            if(p!=NULL){
                
                if(strlen(after)>=2){
                    sum--;
                }
                if(sum>40){
                    sum++;
                }
                
                find_pos=strlen(temp) +1;
                fseek(p_file,sum-2,SEEK_SET);
                fwrite(after,strlen(after),1,p_file);
                fseek(p_file,find_pos-4,SEEK_CUR);
                i++;
            }
            
        }
    }
    
    fclose(p_file);
    printf("\n대출이 완료되었습니다");
    printf("\n아무키나 입력하면 화면 이동");
    getch();
    system("CLS");
}
