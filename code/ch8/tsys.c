/*
* @Author: mcxiaoke
* @Date:   2016-01-03 10:36:38
* @Last Modified by:   mcxiaoke
* @Last Modified time: 2016-01-03 10:41:25
*/

#include "../utils.h"
#include <apue.h>

int main(int argc, char* argv[]) {
    int status;
    if (argc <2)
    {
        err_quit("command line argument required");
    }
    if((status=system(argv[1]))<0)
        err_sys("system() error");
    pr_exit(status);
    return 0;
}
