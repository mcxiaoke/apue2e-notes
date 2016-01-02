/*
* @Author: mcxiaoke
* @Date:   2016-01-02 22:59:12
* @Last Modified by:   mcxiaoke
* @Last Modified time: 2016-01-02 23:02:32
*/

#include <apue.h>

static void charatatime(char *);

int main(int argc, char* argv[]) {
    pid_t pid;
    if ((pid = fork()) < 0) {
        err_sys("fork error");
    } else if (pid == 0) {
        charatatime("output from child\n");
    } else {
        charatatime("output from parent\n");
    }
    exit(0);
    return 0;
}

static void charatatime(char *str) {
    char *ptr;
    int c;
    setbuf(stdout, NULL);
    for (ptr = str; (c = *ptr++) != 0;)
        putc(c, stdout);
}
