#include <stdio.h>
#include<stdlib.h>

int main (int argc,char *argv[]){
	char *s;
	if(argc!=2){
		s = argv[1];
		putchar('\n');
		while(*s!='\0'){
			printf("%c",*s++);
		}
	}else{
		printf("\n Name is : %s",argv[1]);
	}
	return 0;
}
