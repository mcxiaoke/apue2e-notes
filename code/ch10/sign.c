/*
* @Author: mcxiaoke
* @Date:   2016-01-03 15:58:08
* @Last Modified by:   mcxiaoke
* @Last Modified time: 2016-01-03 20:26:09
*/

#include <apue.h>

static void sigusr(int);

int main(int argc, char* argv[]) {
    if (signal(SIGUSR1, sigusr) == SIG_ERR)
        err_sys("can't catch SIGUSR1");
    if (signal(SIGUSR2, sigusr) == SIG_ERR)
        err_sys("can't catch SIGUSR2");
    for (;;) {
        pause();
    }
    return 0;
}

static void sigusr(int signo) {
    if (signo == SIGUSR1)
        printf("received SIGUSR1\n");
    else if (signo == SIGUSR2)
        printf("received SIGUSR2\n");
    else
        err_dump("received signal %d", signo);
}
