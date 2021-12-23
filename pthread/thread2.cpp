#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int global = 10;
int main() {
	pid_t pid;
	int  stack = 1;
	int* heap;
	heap = (int*)malloc(sizeof(int));
	*heap = 3;

	pid = fork();
	if (pid < 0) {
		perror("fail to fork\n");
		exit(-1);
	}
	else if (pid == 0) {
		global++;
		stack++;
		(*heap)++;
		printf("In sub-process,global: %u,stack: %u,heap: %u\n", global, stack, *heap);
		exit(0);
	}
	else {
		sleep(2);
		printf("In parrent-process,global: %u,stack: %u,heap: %u\n", global, stack, *heap);
	}
	return 0;
}