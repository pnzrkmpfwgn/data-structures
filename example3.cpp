#include<stdio.h>
#include<String>
#include<stdlib.h>
#include<conio.h>
#define STACKSIZE 5
using namespace std;
struct person {
	int empnr;
	string name;
	int age;
};
struct stack{
	struct person items[6];
	int top;
};
void push(struct stack *,struct person *, int , string , int );
void pop(struct stack *,struct person *);

int main(){
	struct stack s;
	struct person p;
	int empnumber;
	string name;
	int age;
	char optype;
	s.top=-1;
	do{
		printf("Enter Operation type:\n");
		scanf("%c",&optype);
		switch(optype){
			case 'I':{
				printf("Enter employee Number:");
				scanf("%d",&empnumber);
				printf("\nEnter employee name:");
				scanf("%d",&name);
				printf("\nEnter employee age:");
				scanf("%d",&age);
				push(&s,&p,empnumber,name,age);
				break;
			}
			case 'D':{
				pop(&s,&p);
				break;
			}
			default:printf("%s","Illegal Operation code \n");
		}
	}while(optype!='E');
	return 0;
}

void pop(struct stack *ps,struct person *pp ){
	int x,y,z;
	string i;
	if(ps->top==-1){
		printf("%s","stack underflow");
		exit(1);
	}
	else{
		
		ps->top=ps->top-1;
		y=pp->empnr;
		z=pp->age;
	
	}
	printf("%d %d",y,z);

}

void push(struct stack *ps, struct person *pp , int number,string name,int age){
	if(ps->top== STACKSIZE - 1){
		printf("%s","stack overflow");
		exit(1);
	}
	else{
	ps->top=ps->top +1;
	pp->empnr=number;
	pp->name=name;
	pp->age=age;
	}
}

