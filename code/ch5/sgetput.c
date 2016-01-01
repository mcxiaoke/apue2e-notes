/*
* @Author: mcxiaoke
* @Date:   2016-01-01 20:46:55
* @Last Modified by:   mcxiaoke
* @Last Modified time: 2016-01-01 20:48:43
*/

#include <apue.h>
int main(int argc, char const *argv[])
{
    char buf[MAXLINE];
    while (fgets(buf, MAXLINE, stdin) != NULL)
        if (fputs(buf, stdout) == EOF)
            err_sys("output error");
    if (ferror(stdin))
        err_sys("input error");
    return 0;
}
