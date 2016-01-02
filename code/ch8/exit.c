/*
* @Author: mcxiaoke
* @Date:   2016-01-02 22:03:51
* @Last Modified by:   mcxiaoke
* @Last Modified time: 2016-01-02 22:16:58
*/

#include <apue.h>
#include <sys/wait.h>

void pr_exit(int status) {
    if (WIFEXITED(status))
        printf("normal termination, pid = %d, exit status = %d\n", getpid(), WEXITSTATUS(status));
    else if (WIFSIGNALED(status))
        printf("abnormal termination, pid = %d, signal number = %d%s\n", getpid(), WTERMSIG(status),

#ifdef WCOREDUMP
               WCOREDUMP(status) ? " (core file generated)" : "");
#else
               "");
#endif
    else if (WIFSTOPPED(status))
        printf("child stopped, signal number = %d\n", WSTOPSIG(status));
}

int main(int argc, char* argv[]) {
    pid_t pid;
    int status;
    if ((pid = fork()) < 0)
        err_sys("fork error");
    else if (pid == 0)
        exit(7);
    if (wait(&status) != pid)
        err_sys("wait error");
    pr_exit(status);

    if ((pid = fork()) < 0)
        err_sys("fork error");
    else if (pid == 0)
        abort();
    if (wait(&status) != pid)
        err_sys("wait error");
    pr_exit(status);

    if ((pid = fork()) < 0)
        err_sys("fork error");
    else if (pid == 0)
        status /= 0;
    if (wait(&status) != pid)
        err_sys("wait error");
    pr_exit(status);
    return 0;
}
