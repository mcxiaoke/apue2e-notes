/*
* @Author: mcxiaoke
* @Date:   2016-01-07 14:36:47
* @Last Modified by:   mcxiaoke
* @Last Modified time: 2016-01-07 14:39:05
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

// #define lockfile(fd) write_lock((fd), 0, SEEK_SET, 0)

int lockfile(int fd) {
    struct flock fl;
    fl.l_type = F_WRLCK;
    fl.l_start = 0;
    fl.l_whence = SEEK_SET;
    fl.l_len = 0;
    retun fcntl(fd, F_SETLK, &fl);
}

int main() {

    return 0;
}
