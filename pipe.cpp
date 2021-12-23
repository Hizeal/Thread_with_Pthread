#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#define INPUT 0
#define OUTPUT 1

int main() {
	int fd[2];
	char buf[256];
	int returned_count;
	pid_t pid;

	pipe(fd);

	pid = fork();
	if (pid < 0) {
		printf("thread create error\n");
		exit(1);
	}
	else if (pid == 0) {
		printf("in the child thread......\n");
		close(fd[INPUT]);
		write(fd[OUTPUT], "hello world", strlen("hello world"));
		exit(0);
	}
	else {
		printf("in the parent thread......\n");
		close(fd[OUTPUT]);
		returned_count = read(fd[INPUT], buf, sizeof(buf));
		printf("%d bytes of data recevied from child thread: %s\n", returned_count, buf);
	}
	return 0;
}