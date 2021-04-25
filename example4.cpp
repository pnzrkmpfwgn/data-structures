#include <stdio.h>

struct uu{
	int value;
	int a[5];
};
void fun(struct uu *);

int main(){
	int k;
	struct uu s;
	struct uu a;
	s.value=7;
	for(k=0;k<=5;k++){
		a.a[k]=3*k+1;
	}
	//fun(&s);
	//printf("%d\n",s.value);
	
	for(k=0;k<=5;k++){
		printf("%d\n",a.a[k]);
	
	}
	
	return 0;
}
void fun(struct uu *r){
	int *q;
	++r->value;
	
	//printf("%d\n",(*(r->a+1)));
	q=r->a+4;
	
	//printf("%d\n",*q--);
	//printf("%d\n",*--q);
}


