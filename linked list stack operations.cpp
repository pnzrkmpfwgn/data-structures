#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};
struct node *top=NULL;
void push(int veri){
	struct node *eklenecek=(struct node*)malloc(sizeof(struct node));
	eklenecek->data=veri;
	eklenecek->next=NULL;
	
	if(top!=NULL){
		eklenecek->next=top;
	}
	top=eklenecek;
	
}

void pop(){
	if(top->data==NULL){
		printf("Stack zaten bos");
	}
	else{
		struct node *temp=top;
		top=top->next; 
		free(temp);
	}
}
int peek(){
	return top->data;
}
void yazdir(){
	struct node *q;
	q=top;
	printf("\n");
	while(q!=NULL){
		printf(" %d ==> ",q->data);
		q=q->next;
	}
	printf("NULL\n");
}

int main(){
	int secim,x;
	while(1){
		printf("1-Push\n2-Pop\n3-Peek\n");
		printf("Lutfen secim yapiniz");
		scanf("%d",&secim);
		switch(secim){
			case 1:{
				printf("Sayi giriniz:");
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
				printf("Top eleman:%d\n",peek());
				break;
			}
		}
		
	}
	return 0;
}
