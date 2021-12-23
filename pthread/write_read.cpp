#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>
#define THREADNUM 5

//������
pthread_rwlock_t rwlock;

//reader�����ͽ������������Ӧid1
void* reader(void* arg) {
	pthread_rwlock_rdlock(&rwlock);
	printf("reader %ld got the lock\n", (long)arg);
	pthread_rwlock_unlock(&rwlock);
	pthread_exit((void*)0);
}
void* writer(void* arg) {
	pthread_rwlock_wrlock(&rwlock);
	printf("writer %ld got the lock\n", (long)arg);
	pthread_rwlock_unlock(&rwlock);
	pthread_exit((void*)0);
}

int main(int argc, char** args) {
	pthread_t writerid, readerid;  //�����߳�id
	int iRet, i;
	pthread_attr_t attr;//�����߳�����
	int nwriter = 1, nreader = 1;
	iRet = pthread_rwlock_init(&rwlock, NULL);
	if (iRet) {
		printf("rwlock init error\n");
		return iRet;
	}
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);//�Է���״̬�����߳�
	
	for (i = 0; i < THREADNUM; i++) {
		if (i % 3 == 0) {
			pthread_create(&readerid, &attr, reader, (void*)nreader);//�����̣߳�ִ��reader���������Ϊnreader
			printf("create reader %d\n", nreader++);
		}else{
			pthread_create(&writerid, &attr, writer, (void*)nwriter);
			printf("create writer %d\n", nwriter++);
		}
	}
	sleep(5);
	return 0;
}
