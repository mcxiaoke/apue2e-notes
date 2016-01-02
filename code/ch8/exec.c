/*
* @Author: mcxiaoke
* @Date:   2016-01-02 23:09:42
* @Last Modified by:   mcxiaoke
* @Last Modified time: 2016-01-02 23:21:03
*/

#include <apue.h>
#include <sys/wait.h>

char *env_init[] = {"USER=unknown", "PATH=/tmp", NULL};

int main(int argc, char const *argv[])
{
    pid_t pid;
    if ((pid = fork()) < 0) {
        err_sys("fork error");
    } else if (pid == 0) {
        if (execle("/home/vagrant/bin/echoall", "echoall", "myarg1", "MY ARG2", (char*)0, env_init) < 0)
            err_sys("execle error");
    }
    if (waitpid(pid, NULL, 0) < 0)
        err_sys("waitpid error");
    if ((pid = fork()) < 0) {
        err_sys("fork error");
    } else if (pid == 0) {
        if (execlp("echoall", "echoall", "myarg1", "MY ARG2", (char*)0) < 0)
            err_sys("execle error");
    }
    return 0;
}
