#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>


//��й�ȣ�� �Է� �޾Ƽ�
//�´°�� ����ϱ⸦ �о�ͼ� �����ְ�. ����ۼ�
//Ʋ�� ��� ��� �޼����� ǥ���ϰ� ����

#define MAX 10000

int main(){
    //fgets, inuts Ȱ��
    char line[MAX];//���Ͽ��� �ҷ��� ������ ������ ����
    char contents[MAX];//�ϱ��忡 �Է��� ����
    char password[20];//��й�ȣ �Է�
    char c;//��й�ȣ �Է� �� �� Ű�� Ȯ�ο�

    printf("����ϱ⿡ ���Ű��� ȯ���մϴ� \n");
    printf("��й�ȣ�� �Է��ϼ��� : ");
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
    printf("\n\n ��й�ȣ Ȯ����...\n\n");
    if(strcmp(password,"rhkrrudgh")==0){
        printf("��й�ȣ Ȯ�� �Ϸ�\n");
        char *fileName = "./secretdiary.txt";
        FILE * file = fopen(fileName,"a+b");//'a+b'= ������ ������ ����, ������ ������ �̾ ����
        if(file == NULL){
            printf("���� ���� ����");
            return 1;
        }
        //�ؽ�Ʈ ������ ���� �ҷ�����
        while(fgets(line,MAX,file)!=NULL){
            printf("%s",line);
        }

        printf("\n\n ������ ��� �ۼ��ϼ���. �����Ϸ��� EXIT�� �Է��ϼ���\n\n");
        //���ο� ���� �ۼ�
        while (1)
        {
            scanf("%[^\n]",contents);//������ ������ ������ �о����
            getchar();
            //EXIT�� �Է��ϸ� �����ϱ�
            if(strcmp(contents,"EXIT")==0){
                printf("����ϱ� �Է��� �����մϴ�");
                break;
            }
            inuts(contents,file);
            inuts("\n",file);//���͸� ���� getchar�� �Է��Ͽ��� ���������Ƿ� �ٹٲ� ���Ƿ� �߰�
        }
        fclose(file);
        
    }//��й�ȣ Ʋ�����
    else{
        printf("��й�ȣ�� Ʋ��");
    }

    return 0;
}