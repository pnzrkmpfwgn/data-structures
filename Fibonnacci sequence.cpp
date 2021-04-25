#include <stdio.h>
#include <stdlib.h>

int fib(int n){
	int lofib = 0,hifib=1;
	int i,x;
	for(i=2;i<=n;i++){
		x=lofib;
		lofib=hifib;
		hifib=x+lofib;
	}
	return hifib;
}

int main(){
	printf("%d",fib(9));
	return 0;
}
