/*
* @Author: mcxiaoke
* @Date:   2016-01-05 21:14:23
* @Last Modified by:   mcxiaoke
* @Last Modified time: 2016-01-05 21:22:06
*/

#include <apue.h>
#include <pthread.h>

pthread_t ntid;

void printids(const char *s) {
    pid_t pid;
    pthread_t tid;
    pid = getpid();
    tid = pthread_self();
    printf("%s pid %u tid %u (0x%x)\n", s, (unsigned int) pid, (unsigned int) tid, (unsigned int)tid);
}

void* thr_fn(void *arg) {
    printids("new thread: ");
    return (void*)0;
}

int main(int argc, char* argv[]) {
    int err;
    err = pthread_create(&ntid, NULL, thr_fn, NULL);
    if (err != 0)
        err_quit("can't create thread: %s", strerror(err));
    printids("main thread:");
    sleep(1);
    return 0;
}
