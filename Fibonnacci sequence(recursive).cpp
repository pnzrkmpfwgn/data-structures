#include <stdio.h>
#include <stdlib.h>

int fib(int n){
	int x,y;
	if(n<=1)return n;
	
	x=fib(n-1);
	y=fib(n-2);
	return x+y;
}

int main(){
	printf("%d",fib(9));
	return 0;
}
