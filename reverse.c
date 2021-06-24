#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#define MaxBuf 1 << 18

int main(int argc, char **argv) {
    char *buf;
    int fd;
    unsigned int fileSize = 0;
    char *ptr;
    
    fd = open(argv[1], O_RDWR);
    fileSize = lseek(fd, 0, SEEK_END);
    buf = (char *) malloc(fileSize + 1);
    lseek(fd, 0, SEEK_SET);
    read(fd, buf, fileSize);
    ptr = buf + fileSize - 1;

    char *rev = (char *) malloc(fileSize + 1);
    char *qtr = rev;
    while(*ptr) {
        *qtr++ = *ptr--;
    }
    *qtr = '\0';
    lseek(fd, 0, SEEK_SET);
    write(fd, rev, fileSize);
}
