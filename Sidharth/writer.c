#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    key_t key=ftok("shmfile",65);
    int shmid=shmget(key,1024,0666 | IPC_CREAT);
    char *data=(char *)shmat(shmid,NULL,0);
    printf("Enter a string:");
    fgets(data,1024,stdin);
    return 0;
}
