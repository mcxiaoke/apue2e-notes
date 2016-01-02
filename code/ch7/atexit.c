/*
* @Author: mcxiaoke
* @Date:   2016-01-02 13:47:00
* @Last Modified by:   mcxiaoke
* @Last Modified time: 2016-01-02 13:52:24
*/

#include <apue.h>

static void my_exit1(void);
static void my_exit2(void);

int main(int argc, char const *argv[])
{
    if (atexit(my_exit1) != 0)
        err_sys("can't register my_exit1 1");
    if (atexit(my_exit1) != 0)
        err_sys("can't register my_exit1 2");
    if (atexit(my_exit2) != 0)
        err_sys("can't register my_exit2");
    printf("main is done\n");
    return 0;
}

static void my_exit1(void) {
    printf("first exit handler\n");
}

static void my_exit2(void) {
    printf("second exit handler\n");
}
