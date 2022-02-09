#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>

int main(){
    const char* path = "test";
    int st = mkfifo(path, 0666);
    if (st < 0)
    {
        perror ("mkfifo");
        return -1;
    }

    int fd1 = open(path, O_RDWR);
    if (fd1 < 0)
    {
        perror ("open");
        return -1;
    }

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

    char bufr[2];
    int rd = read(fd1, bufr, sizeof(bufr));
    if (rd < 0)
    {
        perror ("read");
        return -1;
    }

    std::cout<<"Strings are "<<bufr<<std::endl;

    close(fd);
    close(fd1);
    remove(path);
    std::cout<<"finish"<<std::endl;
    return 0;
}
