#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *left;
	struct node *right;
};
struct node *root=NULL;
struct node* newNode(int key){
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->data=key;
	temp->left=NULL;
	temp->right=NULL;
	
	if(root==NULL){
		root = temp;
	}	
	return temp;

}

void inorder(struct node *root){
	if(root!=NULL){
		inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right);
		
	}
}


struct node *ekle(struct node* node,int key){
	if(node ==NULL){
		return newNode(key);
	}
	if(key< node->data){
		node->left = ekle(node->left,key);
	}
	else if(key > node->data){
		node->right = ekle (node->right,key);
	}
}

struct node* search(int aranan){
	struct node* current;
	current=root;
	while(current->data!=aranan){
		if(current!=NULL){
			printf("%d ",current->data);
			if(aranan < current->data){
				current=current->left;
			}
			else{
				current=current->right;
			}
		}
		if(current==NULL){
			printf("Aradiginiz sayi agacta bulunmuyor");
			return NULL;
		}
	}
	printf(" %d",current->data);
	return current;
}

int main(){
	int secim,x;
	while(1){
		printf("\n1-Sayi ekle\n2-inorder traversal\n3-Arama\n");
		printf("Seciminizi yapiniz:");
		scanf("%d",&secim);
		switch(secim){
			case 1:{
				printf("Sayi giriniz:");
				scanf("%d",&x);
				ekle(root,x);
				break;
			}
			case 2:{
				inorder(root);
				break;
			}
			case 3:{
				printf("Sayiyi giriniz:");
				scanf("%d",&x);
				search(x);
				break;
			}
		}
		
	}
	return 0;
}
