/*
* @Author: mcxiaoke
* @Date:   2016-01-03 20:40:24
* @Last Modified by:   mcxiaoke
* @Last Modified time: 2016-01-03 20:48:46
*/

#include <apue.h>
#include <signal.h>
#include <unistd.h>

static void  sig_alrm1(int signo) {

}

unsigned int sleep1(unsigned int nsecs) {
    if (signal(SIGALRM, sig_alrm1) == SIG_ERR) {
        return (nsecs);
    }
    alarm(nsecs);
    pause();
    return alarm(0);
}

static void sig_alrm2(int signo) {
    longjmp(env_alrm, 1);
}

unsigned int sleep2(unsigned int nsecs) {
    if (signal(SIGALRM, sig_alrm2) == SIG_ERR)
        return nsecs;
    if (setjmp(env_alrm) == 0) {
        alarm(nsecs);
        pause();
    }
    return alarm(0);
}

static void sig_int(int signo) {
    int i, j;
    volatile int k;
    printf("sig_int starting\n");
    for (int i = 0; i < 300000; ++i)
    {
        for (int j = 0; j < 4000; ++i)
        {
            k += i * j;
        }
    }
    printf("sig_int finished\n");
}


int main(int argc, char* argv[]) {
    unsigned int unslept;
    if (signal(SIGINT, sig_int) == SIG_ERR)
        err_sys("signal(SIGINT) error");
    unslept = sleep2(5);
    printf("sleep2 returned: %u\n", unslept);
    return 0;
}
