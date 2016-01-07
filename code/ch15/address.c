/*
* @Author: mcxiaoke
* @Date:   2016-01-07 21:54:04
* @Last Modified by:   mcxiaoke
* @Last Modified time: 2016-01-07 22:04:58
*/

#include <apue.h>
#include <sys/shm.h>

#define ARRAY_SIZE 40000
#define MALLOC_SIZE 100000
#define SHM_SIZE 100000
#define SHM_MODE 0600 // read/write user

char array[ARRAY_SIZE];

int main(int argc, char*argv[]) {
    int shmid;
    char *ptr, *shmptr;
    printf("array[] from 0x%lx to 0x%lx\n", (unsigned long)&array[0], (unsigned long)&array[ARRAY_SIZE]);
    printf("stack around 0x%lx\n", (unsigned long) &shmid);
    if ((ptr = malloc(MALLOC_SIZE)) == NULL)
        err_sys("malloc error");
    printf("malloced from 0x%lx to 0x%lx\n", (unsigned long)ptr, (unsigned long)ptr + MALLOC_SIZE);
    if ((shmid = shmget(IPC_PRIVATE, SHM_SIZE, SHM_MODE)) < 0)
        err_sys("shmget error");
    if ((shmptr = shmat(shmid, 0, 0)) == (void*) - 1)
        err_sys("shmat error");
    printf("shared memory attached from 0x%lx to 0x%lx\n",
           (unsigned long)shmptr, (unsigned long)shmptr + SHM_SIZE);
    if (shmctl(shmid, IPC_RMID, 0) < 0)
        err_sys("shmctl error");
    return 0;
}
