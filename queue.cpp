#include <stdio.h>
#include <stdlib.h>
#define Max 1000

struct queue{
	int items[Max];
	int front,rear;
};

int empty (struct queue *pq) {
	return pq->front==pq->rear?0:1;
}

void insert (struct queue *pq,int x){
	if(pq->rear==Max-1)pq->rear=0;
	else pq->rear++;
	
		printf("queue overflow");
		pq->items[pq->rear]=x;
		exit(1);
		
	}
	//insert(&q,5);

int remove(struct queue *pq){
	if(empty(pq)){
		printf("queue overflow");
		exit(1);
	}
	if(pq->front==Max-1){
		pq->front=0;
	}
	else{
		pq->front++;
	}
	return pq->items[pq->front];
}
int main(){
struct queue q;
	int x;
	scanf("%d",&x);
	insert(&q,x);
	//x=remove(&q);
	return 0;
}
