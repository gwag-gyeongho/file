#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char **list;
	char buffer[BUFSIZ];
	int len ,NUM,i;

	printf("How many lines? : ");
	scanf("%d",&NUM);
	getchar();//�Է� ���� ����

	list=(char**) malloc(NUM*sizeof(char*));
	if( list == NULL ) {
			printf("malloc() ����!\n\n");
			exit(1);
		}


	for (i = 0; i < NUM; i++) {
		printf("Type a sentence : ");
		gets(buffer);
		fgets(buffer,BUFSIZ,stdin);
		len=strlen(buffer)+1;

		list[i]=(char*) malloc(len*sizeof(char));
		if( list[i] == NULL ) {
			printf("malloc() ����!\n\n");
			exit(1);
		}
		strcpy(list[i],buffer);

	}
	for(i=1;i<NUM;i++){
		printf("���ڿ� %d: %s",i,list[i]);
	}
	for(i=0;i<NUM;i++){
		free(list[i]);
	}
	free(list);
	return 0;
}