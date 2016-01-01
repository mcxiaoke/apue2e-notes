/*
* @Author: mcxiaoke
* @Date:   2016-01-01 19:44:43
* @Last Modified by:   mcxiaoke
* @Last Modified time: 2016-01-01 19:51:50
*/

#include <apue.h>

int main(int argc, char const *argv[])
{
    char *ptr;
    int size;
    if (chdir("/var/spool/rsyslog") < 0)
        err_sys("chdir failed.");
    ptr = path_alloc(&size);
    if (getcwd(ptr, size) == NULL)
        err_sys("getcwd failed");
    printf("cwd=%s\n", ptr);
    return 0;
}
