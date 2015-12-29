/*
* @Author: mcxiaoke
* @Date:   2015-12-29 21:31:01
* @Last Modified by:   mcxiaoke
* @Last Modified time: 2015-12-29 21:32:17
*/

#include <apue.h>

int main(int argc, char *argv[]) {
    if (lseek(STDIN_FILENO, 0, SEEK_CUR) == -1)
    {
        printf("cannot seek\n");
    }else{
        printf("seek OK\n");
    }
    return 0;
}
