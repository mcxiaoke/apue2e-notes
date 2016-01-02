/*
* @Author: mcxiaoke
* @Date:   2016-01-02 21:23:51
* @Last Modified by:   mcxiaoke
* @Last Modified time: 2016-01-02 21:26:05
*/

#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    printf("process pid=%d, ppid=%d, uid=%d, euid=%d, gid=%d, egid=%d\n",
           getpid(), getppid(), getuid(), geteuid(), getgid(), getegid());
    return 0;
}
