#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define maxcols 80

struct stack{
	int top;
	double items[maxcols];
};

int isdigit(char symb){
		return symb >='0' && symb <= '9';
	}
double eval(char *expr){
	char c;
	int pos;
	double opnd1,opnd2,value;
	struct stack opndstk;
	opndstk.top=-1;
	for(pos=0;(c=expr[pos])!='\0';pos++){
		if(isdigit(c)){
			push(&opndstk,(double)(c-'0'));
		}
		else{
			opnd2=pop(&opndstk);
			opnd1=pop(&opndstk);
			value=open(c,opnd1,opnd2);
			push(&opndstk,value);
		}
		}
	return pop(&opndstk);
}

	
double open(char symb,double op1,double op2){
	switch(symb){
		case '+':return op1 + op2;
		case '-':return op1-op2;
		case '*':return op1*op2;
		case '/':return op1/op2;
		case '$':return pow(op1,op2);
		default:
			printf("Illegal opperand");
			exit(1);
	}
}
main(){
	char expr[maxcols];
	int pos=0;
	while((expr[pos++]=getchar())!='\n');
	expr[--pos]='\0';
	printf("%.5fln",eval(expr));
}


