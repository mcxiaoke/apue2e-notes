/*
* @Author: mcxiaoke
* @Date:   2015-12-28 22:45:13
* @Last Modified by:   mcxiaoke
* @Last Modified time: 2015-12-28 23:15:59
*/

#include <apue.h>

int main() {
    printf("hello world, process id is %d, user id is %d\n", getpid(), getuid());
    return 0;
}
