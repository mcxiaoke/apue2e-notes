/*
* @Author: mcxiaoke
* @Date:   2016-01-01 22:23:56
* @Last Modified by:   mcxiaoke
* @Last Modified time: 2016-01-01 22:26:39
*/

#include <apue.h>

int main(int argc, char const *argv[])
{
    char name[L_tmpnam], line[MAXLINE];
    FILE *fp;
    printf("%s\n", tmpnam(NULL));
    tmpnam(name);
    printf("%s\n", name);
    if ((fp = tmpfile()) == NULL)
        err_sys("tmpfile error");
    fputs("one line of output\n", fp);
    rewind(fp);
    if (fgets(line, sizeof(line), fp) == NULL)
        err_sys("fgets error");
    fputs(line, stdout);
    return 0;
}
