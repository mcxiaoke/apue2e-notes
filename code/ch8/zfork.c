/*
* @Author: mcxiaoke
* @Date:   2016-01-02 22:22:52
* @Last Modified by:   mcxiaoke
* @Last Modified time: 2016-01-02 22:26:32
*/

#include <apue.h>
#include <sys/wait.h>

int main(int argc, char*  argv[]) {
    pid_t pid;
    if ((pid = fork()) < 0) {
        err_sys("fork error");
    } else if (pid == 0) {
        if ((pid = fork()) < 0)
            err_sys("fork error");
        else if (pid > 0)
            exit(0);
        sleep(2);
        printf("second child, parent pid = %d\n", getppid());
        exit(0);
    }
    if (waitpid(pid, NULL, 0) != pid)
        err_sys("waitpid error");
    return 0;
}
