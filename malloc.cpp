#include <stdlib.h>
#include <stdio.h>

struct node{
	int data;
	struct node *sonraki;
};

int main(){
	struct node* ilkdugum =	NULL;
	
	ilkdugum=(struct node*)malloc(sizeof(struct node));
	struct node* ikincidugum = (struct node*)malloc(sizeof(struct node));
	
	struct node* ucuncudugum = (struct node*)malloc(sizeof(struct node));
	
	ilkdugum -> data =15;
	ilkdugum -> sonraki=ikincidugum;
	
	ikincidugum -> data=20;
	ikincidugum->sonraki=ucuncudugum;
	
	ucuncudugum ->data=25;
	ikincidugum->sonraki=NULL;
	
	printf("%d => %d => %d",ilkdugum->data,ikincidugum->data,ucuncudugum->data);
	
	return 0;
}
