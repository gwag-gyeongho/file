#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_STACK_SIZE 100
#define MAX_EXPR_SIZE 100
int top = -1;

typedef enum {
	lparen, rparen, plus, minus, times, divide,
	mod, eos, operand, space
} precedence;


precedence get_token(char* expr, char* symbol, int* n) {
	*symbol = expr[*n];  (*n)++;
	
	switch (*symbol) {
	case '(': return lparen;
	case ')': return rparen;
	case '+': return plus;
	case '-': return minus;
	case '*': return times;
	case '/': return divide;
	case '%': return mod;
	case '$': return eos;
	case ' ': return space;
	default: return operand;
	}
}

typedef int element;
precedence stack[MAX_STACK_SIZE];




static int isp[] = { 0, 19, 12, 12, 13, 13, 13, 0 , 99};
static int icp[] = { 20, 19, 12, 12, 13, 13, 13, 0 , 99};
char expr[MAX_EXPR_SIZE];
char iexpr[MAX_EXPR_SIZE];


void stack_full()
{
	printf("full");
}

element stack_empty()
{

}

void push(int* ptop, element item)
{

	
	if (*ptop >= MAX_STACK_SIZE - 1) {
		stack_full();
		return;
	}
	
	stack[++*ptop] = item;
}

element pop(int* top)
{

	if (*top == -1)
		return stack_empty();
	
	return stack[(*top)--];
}



void print_token(precedence token, int * index) {
	
	switch (token) {
	case lparen:
		iexpr[(*index)++] = '('; break;
	case rparen:
		iexpr[(*index)++] = ')';break;
	case plus:
		iexpr[(*index)++] = '+';break;
	case minus:
		iexpr[(*index)++] = '-';break;
	case divide:
		iexpr[(*index)++] = '/';break;
	case times:
		iexpr[(*index)++] = '*';break;
	case mod:
		iexpr[(*index)++] = '%';break;
	case eos:
		iexpr[(*index)++] = '$';break;
	}
}


int eval(void) {
	precedence token;
	int op1, op2, n = 0, top = -1;
	char symbol;
	token = get_token(iexpr, &symbol, &n);
	while (token != eos) {

		
		if (token == operand)  
		{
			char tmp[10]="";
			int i=0, j=0, result = 0;
			for(i=n-1; iexpr[i] != ' ';i++){
				tmp[j] = iexpr[i];
				j++;
			}
			tmp[i] = '\0';
			result = atoi(tmp);
			push(&top, result);
			token = get_token(iexpr, &symbol, &n);
			
		}	
		else if (token != space){
			op2 = pop(&top); 
			op1 = pop(&top);
			switch (token) {
			case plus:push(&top, op1 + op2); break;
			case minus:push(&top, op1 - op2);break;
			case times: push(&top, op1 * op2); break;
			case divide: push(&top, op1 / op2); break;
			case mod: push(&top, op1 % op2);
			}
		}

		token = get_token(iexpr, &symbol, &n);
	}  
	
	return pop(&top);
}

void infix_to_postfix(void) {
	int index = 0;
	
	char symbol;
	precedence token;
	int num = 0, top = 0;
	stack[0] = eos;
	for (token = get_token(expr, &symbol, &num); token != eos;
		token = get_token(expr, &symbol, &num)) {
		if (token == operand){   
				
				iexpr[index++] = symbol;
			}
		
		else if (token == rparen) {
			while (stack[top] != lparen)  
			{
				iexpr[index++] = ' ';
				print_token(pop(&top), &index);
			}
			pop(&top);  
		}
		else {
			if(token != lparen)
				iexpr[index++] = ' ';
			while (isp[stack[top]] >= icp[token])
			{
				print_token(pop(&top), &index);
				iexpr[index++] = ' ';
			}
			push(&top, token);
		}  
	}  
	while ((token = pop(&top)) != eos){
		iexpr[index++] = ' ';
		print_token(token, &index);
		
	}
	print_token(eos, &index);

	
}


int main() {

	int i;
	char END[15]="END_OF_INPUT";
   	char test[1024];
		
    char *Line;
    FILE *in = fopen("test.txt", "r");
    while (!feof(in)) {
    	Line = fgets(test, 1024, in);
    	printf("Input: %s", Line);
		strcpy(expr,Line);
		if(strcmp(END,expr) == 0)
			break;
		infix_to_postfix();
		printf("Output: ");
		for (int i= 0; iexpr[i]!='$'; i++){
			printf("%c", iexpr[i]);
		}
		printf("\nEvaluation value: %d\n\n", eval()); 
		}
    
    fclose(in);
	
	return 0;
}