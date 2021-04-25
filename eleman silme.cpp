#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node* start=NULL;
struct node* temp=NULL;
struct node* q=NULL;

void sonaekle(int veri){
	struct node* eklenecek=(struct node*)malloc(sizeof(struct node));
	eklenecek->data=veri;
	eklenecek->next=NULL;

	if(start==NULL){
		start=eklenecek;
	}
	else{
		q=start;
		while(q->next !=NULL){
			q=q->next;
		}
		q->next=eklenecek;
	}
}

void arayaekle(int x,int y){
	struct node* arayaeklenecek=(struct node*)malloc(sizeof(struct node));
	arayaeklenecek->data=y;
	q=start;
	while(q->next->data!=x){
		q=q->next;
	}
	struct node* onune=(struct node*)malloc(sizeof(struct node));
	onune=q->next;
	q->next=arayaeklenecek;
	arayaeklenecek->next=onune;
}
void basaekle(int basa){
	struct node *basagelecek=(struct node*)malloc(sizeof(struct node));
	basagelecek->data=basa;
	basagelecek->next=start;
	start=basagelecek;
	
}
void sondansil(){
	if(start!=NULL){
	q=start;
	while(q->next->next!=NULL){
			q=q->next;
	}
	free(q->next);
		q->next=NULL;	
	}
	else{
		printf("Eleman kalmadi veya yok");
	}
}
void bastansil(){
	struct node* ikinci=NULL;
	ikinci=start->next;
	free(start);
	start=ikinci;
}
void yazdir(){
	q=start;
	while(q->next!=NULL){
		printf("%d=>",q->data);
		q=q->next;
	}
	printf("%d\n",q->data);
}

int main(){
	int secim,sona,basa,x,y;
	printf("1-Sona eleman ekle\n2-Basa eleman ekle\n3-Araya Eleman Ekle\n4-Sondan eleman sil.\n5-Bastan eleman sil.");
	printf("\nSeciminizi yapiniz ");
	
		while(1){
			scanf("%d",&secim);
			switch(secim){
				case 1:{
					printf("\n sayi giriniz:");
					scanf("%d",&sona);
					sonaekle(sona);
					yazdir();
					break;
				}
				case 2:{
					printf("\n sayi giriniz:");
					scanf("%d",&basa);
					basaekle(basa);
					yazdir();
					break;
				}
				case 3:{
					printf("\n hangi elemanin onune ekleme yapacaksiniz:");
					scanf("%d",&x);
					printf("\n sayi giriniz");
					scanf("%d",&y);
					arayaekle(x,y);
					yazdir();
					break;
				}
				case 4:{
					sondansil();
					yazdir();
					break;
				}
				case 5:{
					bastansil();
					yazdir();
					break;
				}
			}
		}
	return 0;
}
