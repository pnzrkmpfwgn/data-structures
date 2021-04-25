#include <stdio.h>
#include <stdlib.h>
#define MAXCHAR 1000

int main(){
	FILE *fp;
	char str[MAXCHAR];
	char* filename = "c://Users/HP58/Desktop/Programlar/C/Dersler/emp.txt";
	
	fp=fopen(filename,"r");
	if(fp==NULL){
		printf("Could not open file %s",filename);
		return 1;
	}
	while(fgets(str,MAXCHAR,fp)!= NULL){
		printf("%s",str);
	}
	fclose(fp);
	return 0;
}
