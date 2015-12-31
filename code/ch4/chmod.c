/*
* @Author: mcxiaoke
* @Date:   2015-12-31 08:33:14
* @Last Modified by:   mcxiaoke
* @Last Modified time: 2015-12-31 08:35:40
*/

#include <apue.h>

int main(int argc, char* argv[]) {
    struct stat statbuf;
    if(stat("foo", &statbuf)<0)
        err_sys("stat error for foo");
    if(chmod("foo",(statbuf.st_mode & ~S_IXGRP)|S_ISGID)<0)
        err_sys("chmod error for foo");
    if(chmod("bar",S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH)<0)
        err_sys("chmod error for bar");
    return 0;
}
