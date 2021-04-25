#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node* start=NULL;
struct node* q=NULL;

void sonaekle(int veri){
	int i=0;
	struct node *eklenecek=(struct node*)malloc(sizeof(struct node));
	eklenecek->data=veri;
	eklenecek->next=NULL;

	if(start==NULL){
		start=eklenecek;
		i++;
	}
	else{
		q=start;
		while(q->next !=NULL){
			q=q->next;
		}
		q->next=eklenecek;
	}
}

void yazdir(){
	q=start;
	while(q->next!=NULL){
		printf("%d=>",q->data);
		q=q->next;
	}
	printf("%d",q->data);
}
void basaekle(int basa){
	struct node *basagelecek=(struct node*)malloc(sizeof(struct node));
	basagelecek->data=basa;
	basagelecek->next=start;
	start=basagelecek;
	
}
int main(){
	int secim;
	int sona,basa;
	printf("1= sona eleman ekle");
	printf("2= sona eleman ekle");
	
	while(1){
		printf("Yapmak istediginiz islemi secin\n");
		scanf("%d",&secim);
		switch(secim){
			case 1:{
				printf("sayi giriniz:");
				scanf("%d",&sona);		
				sonaekle(sona);
				yazdir();
				break;
			}
			case 2:{
				printf("sayi giriniz:");
				scanf("%d",&basa);
				basaekle(basa);
				yazdir();
				break;
			}
		}
	}
	return 0;
}
