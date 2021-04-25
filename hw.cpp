#include <stdio.h>
#include <stdlib.h>

int max(int ,int );
int min(int ,int );
int FindMin(int [], int);
int FindMax(int [], int );
double avgRec(int [],int ,int );
double average(int [],int );
int sumRec(int [],int ,int );
int sum(int [],int );

int main(){
	char x;
	int n;
	int cntr=0;
	printf("Please enter the amount of integers:");
	scanf("%d",&n);
	int a[n];
	for(int i=1;i<=n;i++){
		printf("Enter %d. integer:",i);
		scanf("%d",&a[cntr]);
		cntr++;
	}
	printf("Operation Selection => Max[\'M\'], Min[\'m\'], Sum[\'s\' or \'S\'], Average[\'A\' or \'a\']:");
	printf("\n(Press \'e\' or \'E)\n");
	while(1){

	scanf("%c",&x);
	switch(x){
		case 'M':{
			printf("The max of the array:%d\n",FindMax(a,n));
			break;
		}
			case'm':{
				printf("The min of the array:%d\n",FindMin(a,n));
				break;
			}
		case 'A':
			case 'a':{
				printf("The average:%.2lf\n",average(a,n));
				break;
			}
		case 'S':
			case 's':{
				printf("The Sum:%d\n",sum(a,n));
				break;
			}
			case 'E':
				case 'e':{
					exit(1);
				}
	}
	}
	
	return 0;
}
int max(int a,int n){
	if(a>n)return a;
	else return n;
}
int min(int a,int n){
	if(a<n) return a;
	else return n;
}

int FindMin(int A[], int n){
	if(n==1) return A[0];
	return min(A[n-1],FindMin(A,n-1));
}


int FindMax(int A[], int n){
	if(n==1) return A[0];
	return max(A[n-1],FindMax(A,n-1));
}

double avgRec(int a[],int i,int n){
	if(i==n-1)
	return a[i];
	
	if(i==0)
	 return ((a[i] + avgRec(a, i+1, n))/n);
	
	 return (a[i] + avgRec(a, i+1, n)); 
	
}

double average(int a[],int n){
	return avgRec(a,0,n);
}

int sumRec(int a[],int i,int n){
	if(i==n-1)
	return a[i];
	if(i==0)
	return (a[i]+sumRec(a,i+1,n));
	
	return a[i]+sumRec(a,i+1,n);
}

int sum(int a[],int n){
	return sumRec(a,0,n);	
}
