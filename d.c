#include <stdio.h>
#include <string.h>
#define SIZE 100

int str_chr(char *s, int c) {
	int i;
	int count=0;
	for (i=0;i<strlen(s);i++) {
		if( s[i] == c )
		count++;
	}
	return count;
}

int main(void) {

	char str[SIZE];
	char ch;
	printf("���ڿ��� �Է��Ͻÿ�: ");
	gets(str);
	printf("������ �� ���ڸ� �Է��Ͻÿ�: ");
	ch= getchar();
	printf("a: %d",str_chr(str,'a'));

	return 0;

}