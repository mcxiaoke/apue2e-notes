/*
* @Author: mcxiaoke
* @Date:   2016-01-01 19:56:03
* @Last Modified by:   mcxiaoke
* @Last Modified time: 2016-01-01 20:10:02
*/

#include <apue.h>
#include <sys/sysmacros.h>

int main(int argc, char const *argv[])
{
    int i;
    struct stat buf;
    for (int i = 0; i < argc; ++i)
    {
        printf("%s: ", argv[i]);
        if (stat(argv[i], &buf) < 0) {
            err_ret("stat error");
            continue;
        }
        printf("dev= %d/%d", major(buf.st_dev), minor(buf.st_dev));
        if (S_ISCHR(buf.st_mode) || S_ISBLK(buf.st_mode)) {
            printf(" (%s) rdev = %d/%d", (S_ISCHR(buf.st_mode)) ? "character" : "block",
                   major(buf.st_rdev), minor(buf.st_rdev));
        }
        printf("\n");

    }
    return 0;
}
