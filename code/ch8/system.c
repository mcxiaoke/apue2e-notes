/*
* @Author: mcxiaoke
* @Date:   2016-01-03 10:28:03
* @Last Modified by:   mcxiaoke
* @Last Modified time: 2016-01-03 10:33:35
*/

#include <apue.h>
#include <errno.h>
#include <unistd.h>
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

int system(const char* cmdstring) {
    pid_t pid;
    int status;
    if (cmdstring == NULL)
    {
        return 1;
    }
    if ((pid = fork()) < 0) {
        status = -1;
    } else if (pid == 0) {
        execl("/bin/sh", "sh", "-c", cmdstring, (char*)0);
        _exit(127);
    } else {
        while (waitpid(pid, &status, 0) < 0) {
            if (errno != EINTR) {
                status = -1;
                break;
            }
        }
    }

    return status;
}

int main(int argc, char* argv[]) {
    int status;
    if ((status = system("date")) < 0)
        err_sys("system() error");
    pr_exit(status);
    if ((status = system("notfoundcmd")) < 0)
        err_sys("system() error");
    pr_exit(status);
    if ((status = system("who; exit 44")) < 0)
        err_sys("system() error");
    pr_exit(status);
    return 0;
}
