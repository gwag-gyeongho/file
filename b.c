#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{   
 	FILE* fp;
    char ans[100],book[20][20],str[100],title[10];
    int k=0,bookexist=0,num[20];
    char after[10],before[10];
    char *p,c;
    
    

    printf("**********************\n");
    printf("*****å ���� ȭ��*****\n");
    printf("**********************\n");
    fp = fopen("BookList.txt", "r");
    printf("������ å �̸� :\n");
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
                    printf("å�� �����ϴ�\n");
                    bookexist=1;
                    break;
                }
                num[i]-=1;
            
            }
            else{
                printf("�������� �ʴ� å�Դϴ�\n");
                bookexist=1;
                break;
            }
            
    

        }
        if(bookexist==1){
            break;
        }
    }
    if(bookexist!=1){
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
    }
    else{
        printf("");
    }
    
    if(bookexist==1){
        printf("\n������ �� �����ϴ�.\n");
    }
    else{
        printf("\n������ �Ϸ�Ǿ����ϴ�\n");
        
    }

    return 0;

}