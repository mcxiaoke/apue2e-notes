/*
* @Author: mcxiaoke
* @Date:   2016-01-02 12:55:03
* @Last Modified by:   mcxiaoke
* @Last Modified time: 2016-01-02 12:59:53
*/

#include <apue.h>
#include <pwd.h>
#include <stddef.h>
#include <string.h>

struct passwd * getpwnam(const char *name){
    struct passwd *ptr;
    setpwent();
    while((ptr=getpwent())!=NULL)
        if(strcmp(name, ptr->pw_name) ==0)
            break;
    endpwent();
    return(ptr);
}

int main(int argc, char const *argv[])
{
    printf("%s\n", "hello");
    return 0;
}
