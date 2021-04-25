#include <stdio.h>
#include <stdlib.h>

int binsrch(int *a,int x,int low, int high){
	int mid;
	if(low>high){
		return -1;
	}
	mid=(low+high)/2;
	return x==a[mid] ? mid : x < a[mid] ?
	binsrch(a,x,low,mid-1) : binsrch(a,x,mid + 1,high);
}

int main(){
	int v[15]={23,31,36,48,59,70,76,88,99,108,120,132,154,160,177};
	
	printf("%d",binsrch(v,108,5,10));
	return 0;
}
