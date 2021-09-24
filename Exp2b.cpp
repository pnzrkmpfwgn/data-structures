#include <iostream>
#define MAXCHAR 1000
using namespace::std;

int main(){
    cout << " warning: ISO C++ forbids converting a string constant to ‘char*’ [-Wwrite-strings] 8 | char *filename = \"C://users/user/desktop/deneme.txt\";";
    cout << endl;
    return 0;
}
// #include <stdio.h>
// #include <stdlib.h>
// #define MAXCHAR 1000

// int main(){
// 	FILE *fp;
// 	char str[MAXCHAR];
// 	char* filename = "c://Users/HP58/Desktop/Programlar/C/Dersler/emp.txt"; // Burayı sil {!!!!!}
	
// 	fp=fopen(filename,"r");
// 	if(fp==NULL){
// 		printf("Could not open file %s",filename);
// 		return 1;
// 	}
// 	while(fgets(str,MAXCHAR,fp)!= NULL){
// 		printf("%s",str);
// 	}
// 	fclose(fp);
// 	return 0;
// }
