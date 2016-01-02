/*
* @Author: mcxiaoke
* @Date:   2016-01-02 21:28:17
* @Last Modified by:   mcxiaoke
* @Last Modified time: 2016-01-02 21:58:10
*/

#include <apue.h>
#include <stdio.h>
#include <unistd.h>

int glob = 6;
char buf[] = "a write to stdout\n";

int main(int argc, char* argv[]) {
    int var;
    pid_t pid;
    var = 88;
    if (write(STDOUT_FILENO, buf, sizeof(buf) - 1) != sizeof(buf) - 1)
        err_sys("write error");
    printf("before vfork\n");
    if ((pid = vfork()) < 0) {
        err_sys("vfork error");
    } else if (pid == 0) {
        glob++;
        var++;
        _exit(0);
    }
    printf("pid = %d, glob = %d, var = %d\n", getpid(), glob, var);
    return 0;
}
