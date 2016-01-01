/*
* @Author: mcxiaoke
* @Date:   2016-01-01 19:41:37
* @Last Modified by:   mcxiaoke
* @Last Modified time: 2016-01-01 19:42:37
*/

#include <apue.h>

int main(int argc, char* argv[]) {
    if(chdir("/tmp") < 0)
        err_sys("chdir failed!");
    printf("chdir to /tmp succeeded\n");
    return 0;
}
