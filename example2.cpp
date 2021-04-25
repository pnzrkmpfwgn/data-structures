#include <stdio.h>

int f(int x,int *py,int **pz){
	int y,z;
	(**pz)+=1;
	printf("%d ",**pz);
	z=**pz;
	//*py+=3;
	y=*py;
	printf(" %d ",*py);
	//x+=2;
	printf(" %d ",x);
	return x+y+z;
}

int main(){
	int c ,*b, **a;
	c=6; b=&c;
	a=&b;
	printf("%d",f(c,b,a));
	
	return 0;
}
