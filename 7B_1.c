#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include<sys/shm.h>
#include<sys/ipc.h>

int main()
{
	key_t key = ftok("shmfile",65);
	int shmid;
	void *shmaddr;
	shmid = shmget(key,100,0666);
	printf("shmid of the shared memory is %d\n",shmid);
	shmaddr = shmat(shmid,NULL,0);
	printf("the shared menory is attached to the address %p\n",shmaddr);
	printf("data read from the shared memory is :\n%s",(char*)shmaddr);
	return 0;
}