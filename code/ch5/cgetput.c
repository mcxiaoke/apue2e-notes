/*
* @Author: mcxiaoke
* @Date:   2016-01-01 20:44:58
* @Last Modified by:   mcxiaoke
* @Last Modified time: 2016-01-01 20:46:41
*/

#include <apue.h>

int main(int argc, char const *argv[])
{
    int c;
    while ((c = getc(stdin)) != EOF)
        if (putc(c, stdout) == EOF)
            err_sys("output eror");
    if (ferror(stdin))
        err_sys("input error");
    return 0;
}
