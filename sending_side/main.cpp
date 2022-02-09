#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>


int main()
{
    const char* path = "./../named_pipe";

    int fd = open(path, O_WRONLY);
    if (fd < 0)
    {
        perror ("open");
        return -1;
    }

    char bufw[2]= "1";
    int len = write(fd, bufw, sizeof(bufw));
    if (len < 0)
    {
        perror ("write");
        return -1;
    }

    close(fd);
    return 0;
}
