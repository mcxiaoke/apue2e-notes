/*
* @Author: mcxiaoke
* @Date:   2016-01-02 14:06:30
* @Last Modified by:   mcxiaoke
* @Last Modified time: 2016-01-02 14:07:39
*/

#include <apue.h>

int main(int argc, char const *argv[])
{
    int i;
    for (i = 0; i < argc; ++i)
        printf("argv[%d]: %s\n", i, argv[i]);
    return 0;
}
