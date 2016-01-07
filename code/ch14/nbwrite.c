/*
* @Author: mcxiaoke
* @Date:   2016-01-07 10:40:05
* @Last Modified by:   mcxiaoke
* @Last Modified time: 2016-01-07 11:37:11
*/

#include <apue.h>
#include <errno.h>
#include <fcntl.h>

char buf[500000];

int main(int argc, char* argv[]) {
    int n, nwrite;
    char *ptr;
    n = read(STDIN_FILENO, buf, sizeof(buf));
    fprintf(stderr, "read %d bytes\n", n);
    set_fl(STDOUT_FILENO, O_NONBLOCK);
    ptr = buf;
    while (n > 0) {
        errno = 0;
        nwrite = write(STDOUT_FILENO, ptr, n);
        fprintf(stderr, "nwrite = %d, errno = %s\n", nwrite, strerror(errno));
        if (nwrite > 0) {
            ptr += nwrite;
            n -= nwrite;
        }
    }
    clr_fl(STDOUT_FILENO, O_NONBLOCK);
    return 0;
}
