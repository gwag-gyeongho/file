#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>


//비밀번호를 입력 받아서
//맞는경우 비밀일기를 읽어와서 보여주고. 계속작성
//틀린 경우 경고 메세지를 표시하고 종료

#define MAX 10000

int main(){
    //fgets, inuts 활용
    char line[MAX];//파일에서 불러온 내용을 저장할 변수
    char contents[MAX];//일기장에 입력할 내용
    char password[20];//비밀번호 입력
    char c;//비밀번호 입력 할 때 키값 확인용

    printf("비밀일기에 오신것을 환영합니다 \n");
    printf("비밀번호를 입력하세요 : ");
    int i=0;
    while(1){
        c=getch();
        if(c == 13){
            password[i]='\0';
            break;

        }
        else{
            printf("*");
            password[i] = c;
        }
        i++;
    }
    printf("\n\n 비밀번호 확인중...\n\n");
    if(strcmp(password,"rhkrrudgh")==0){
        printf("비밀번호 확인 완료\n");
        char *fileName = "./secretdiary.txt";
        FILE * file = fopen(fileName,"a+b");//'a+b'= 파일이 없으면 생성, 파일이 있으면 이어서 쓰기
        if(file == NULL){
            printf("파일 열기 실패");
            return 1;
        }
        //텍스트 파일의 내용 불러오기
        while(fgets(line,MAX,file)!=NULL){
            printf("%s",line);
        }

        printf("\n\n 내용을 계속 작성하세요. 종료하려면 EXIT를 입력하세요\n\n");
        //새로운 내용 작성
        while (1)
        {
            scanf("%[^\n]",contents);//새줄이 나오기 전까지 읽어들임
            getchar();
            //EXIT를 입력하면 종료하기
            if(strcmp(contents,"EXIT")==0){
                printf("비밀일기 입력을 종료합니다");
                break;
            }
            inuts(contents,file);
            inuts("\n",file);//엔터를 위에 getchar를 입력하여서 무시했으므로 줄바꿈 임의로 추가
        }
        fclose(file);
        
    }//비밀번호 틀린경우
    else{
        printf("비밀번호가 틀림");
    }

    return 0;
}