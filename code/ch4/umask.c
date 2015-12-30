/*
* @Author: mcxiaoke
* @Date:   2015-12-30 22:10:09
* @Last Modified by:   mcxiaoke
* @Last Modified time: 2015-12-30 22:13:20
*/

#include <apue.h>
#include <fcntl.h>

#define RWRWRW (S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH)

int main(int argc, char* argv[]) {
    umask(0);
    if(creat("foo", RWRWRW)<0)
        err_sys("create error for foo");
    umask(S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH);
    if(creat("bar", RWRWRW)<0)
        err_sys("create error for bar");
    return 0;
}
