/*
* @Author: mcxiaoke
* @Date:   2015-12-28 22:45:13
* @Last Modified by:   mcxiaoke
* @Last Modified time: 2016-01-03 22:05:36
*/

#include <stdio.h>

int main(int argc, char* argv[]) {
    printf("hello world, process id is %d, user id is %d\n", getpid(), getuid());
    return 0;
}
