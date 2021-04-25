#include <stdio.h>
int main(){
	int v[3]={10,100,200};
	int nums[2][3]  =  { {16, 18, 20}, {25, 26, 27} };
	int *ptr;
	ptr=nums[0][0];
		printf("%d\n",*(*ptr));
		printf("%d\n",*(*ptr+1));
		printf("%d\n",**(ptr+2));

	

	
	
	
	
	return 0;
}
