#include <stdio.h>
#include <stdlib.h>
#define BOYUT 5
int kuyruk[BOYUT],front= -1,rear=-1;

void enQueue(int veri){
	if(rear==BOYUT){
		printf("\nkuyruk dolu.");
	}
	else{
		if(front==-1){
			front=0;
		}
		rear=rear+1;
		kuyruk[rear]=veri;
	}
}

void deQueue(){
	if(front==-1||front>rear){
		printf("Kuyruk bos");
		front=-1;
		rear=-1;
	}
	else{
		front=front+1;
		
	}
	
}
void display(){
	int i;
	for(i=front;i<=rear;i++){
		printf("%d ",kuyruk[i]);
	}
}

int main(){
	int secim,x;
	printf("\n1-Enqueue\n2-Dequeue");
	while(1){
		scanf("%d",&secim);
		switch(secim){
			case 1:{
				printf("\nSayi giriniz:");
				scanf("%d",&x);
				enQueue(x);
				display();
				break;
			}
			case 2:{
				deQueue();
				display();
				break;
			}
		}
		}
		return 0;
	}
	

