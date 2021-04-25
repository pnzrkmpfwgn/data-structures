#include <stdio.h>
#include <stdlib.h>
#define MAX 10
int A[MAX];
int front=-1;
int rear=-1;

bool IsEmpty(){
	if(front==-1 && rear==-1){
		return true;
	} 
	else{
		return false;
	}
}
bool IsFull(){
	if((rear+1)%MAX==front){
		return true;
	}
	else{
		return false;
	}
}
void EnQueue(int x){
	if(IsFull()){
		printf("The Queue is full\n");
	}
	else if(IsEmpty()){
		front=0;
		rear=0;
		
	}
	else{
		rear=(rear+1)%MAX;
	}
	A[rear]=x;
}
void DeQueue(){
	if(IsEmpty()){
		exit(1);
	}
	else if(front==rear){
		front=-1;
		rear=-1;
	}
	else{
		front=(front+1)%MAX;
	}

}
int Front(){
	return A[front];	
}
int Rear(){
	return A[rear];
}
void DisplayQueue(){
	for(int i=0;i<MAX;i++){
		printf("%d ",A[i]);
	}
}
int main(){
	int x;
	while(1){
		printf("Press any button to terminate.\n");
		printf("1-Enqueue\n2-Dequeue\n3-Front\n4-Rear\n5-Display the queue\n");
		scanf("%d",&x);
		switch(x){
			case 1:{
				printf("Please enter a number:");
				scanf("%d",&x);
				EnQueue(x);
				printf("The number has been added to the queue\n");
				break;
			}
			case 2:{
				DeQueue();
				printf("The DeQueue operation is completed.\n");
				break;
			}
			case 3:{
				printf("Front: %d\n",Front());
				break;
			}
			case 4:{
				printf("Rear: %d\n",Rear());
				break;
			}
			case 5:{
				printf("The Queue:\n");
				DisplayQueue();
				break;
			}
			default:{
				exit(1);
				break;
			}
		}
	}
	return 0;
}
