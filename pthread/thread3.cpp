#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
/*
int main() {
	printf("using exit\n");
	printf("this is content in buff");
	exit(0);
}
*/

int main() {
	printf("using _exit\n");
	printf("this is content in buffer"); //Ö±½ÓÍË³ö
	_exit(0);
}