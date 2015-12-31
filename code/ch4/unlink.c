/*
* @Author: mcxiaoke
* @Date:   2015-12-31 08:48:39
* @Last Modified by:   mcxiaoke
* @Last Modified time: 2015-12-31 08:50:12
*/

#include <apue.h>
#include <fcntl.h>

int main(int argc, char* argv[]) {
    if(open("tempfile",O_RDWR)<0)
        err_sys("open error");
    if(unlink("tempfile")<0)
        err_sys("unlink error");
    printf("file unlinked\n");
    sleep(15);
    printf("done\n");
    return 0;
}
