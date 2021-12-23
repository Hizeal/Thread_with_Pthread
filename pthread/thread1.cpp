// thread.cpp: 定义应用程序的入口点。
//
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main() {
	pid_t pid;
	pid = fork();
	if (pid < 0) { //此时创建失败
		perror("fail to fork\n");
		exit(-1);
	}
	else if (pid == 0) { //子进程创建成功
		printf("Sub process,PID: %u,PPID: %u\n", getpid(), getppid()); //前者获得进程的PID，后者获得父进程的PID
	}
	else {//对于父进程
		
		printf("Parent process: %u,Sub process: %u\n", getpid(), pid);
		sleep(2);
	}
	return 0;
}
