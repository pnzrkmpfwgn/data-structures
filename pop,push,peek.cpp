#include <stdio.h>
#include <stdlib.h>
#define BOYUT 5
int dizi[BOYUT],top;
void push(int veri){
	if(top+1==BOYUT){
		printf("Stack dolu");
	}
	else{
		top=top+1;
		dizi[top]=veri;
	}
}
void pop(){
	if(top==-1){
		printf("Stack zaten bos");
	}
	else{
		top=top-1;
	}
}

int peek(){
	return dizi[top];
}

void yazdir(){
	int i;
	for(i=0;i<top+1;i++){
		printf("%d",dizi[i]);
	}
	printf("==> TOP");
}

int main(){
	top=-1;
	int secim;
	int x;
	printf("\n1-Push\n2-Pop\n3-Peek\n");
	printf("Seciminizi giriniz:");
	scanf("%d",&secim);
	
	while(1){
			switch(secim){
		case 1:{
			printf("Bir sayi giriniz:");
			scanf("%d",&x);	
			push(x);
			yazdir();
			break;
		}
		case 2:{
			pop();
			yazdir();
			break;
		}
		case 3:{
			printf("\nTop degeri===> %d",peek());
			break;
		}
	}
	}
	return 0;
}
