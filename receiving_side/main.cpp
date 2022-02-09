#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>

int main()
{
    const char* path = "./../named_pipe";
    remove(path);
    int st = mkfifo(path, 0666);
    if (st < 0)
    {
        perror ("mkfifo");
        return -1;
    }

    int fd = open(path, O_RDONLY);
    if (fd < 0)
    {
        perror ("can't open");
        return -1;
    }

    char bufr[2];
    int rd = read(fd, bufr, sizeof(bufr));
    if (rd < 0)
    {
        perror ("can't read");
        return -1;
    }

    std::cout<<"Strings are "<<bufr<<std::endl;

    close(fd);
    remove(path);
    return 0;
}
