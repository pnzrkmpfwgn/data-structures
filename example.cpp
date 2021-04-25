#include <stdio.h>

int main(){
	char *u[2];
	u[0]="COMPUTER";
	u[1]="SCIENCE";
	u[0]++;
	u[1]=u[0]+2;
	printf("%c\n",*(u[0]+2));
	printf("%s\n",u[1]+2);
	
	return 0;
}
