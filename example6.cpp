#include <stdio.h>
#include <stdlib.h>

struct str{
	int k;
	struct str *ptr_int;
};

int main(){
	struct str *ptr_ext,*p1,*p2;
	ptr_ext=(struct str*)calloc(6,sizeof(struct str));
	p1=ptr_ext->ptr_int;
	p2=ptr_ext;
	ptr_ext->k=3;
	
	ptr_ext->ptr_int->k=ptr_ext->k++;
	p1->ptr_int=p2;
	
	printf("%d %d %d\n",p1->k,p2->k,(*p1).k-p1->k);
	
	return 0;
}
