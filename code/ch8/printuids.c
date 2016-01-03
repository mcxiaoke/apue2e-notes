/*
* @Author: mcxiaoke
* @Date:   2016-01-03 10:35:16
* @Last Modified by:   mcxiaoke
* @Last Modified time: 2016-01-03 10:35:54
*/

#include <stdio.h>

int main(void) {
    printf("real uid=%d, effective uid=%d\n", getuid(), geteuid());
    return 0;
}
