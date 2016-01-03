/*
* @Author: mcxiaoke
* @Date:   2016-01-03 10:38:12
* @Last Modified by:   mcxiaoke
* @Last Modified time: 2016-01-03 10:41:52
*/

#include "utils.h"
#include <stdio.h>
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
