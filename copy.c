// use open(), read(), write() to perform copy
// copy sourceFile targetFile ; read from sourceFile and write to targetFile
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#define MaxBuf 4096

int main(int argc, char **argv) {
    char buf[MaxBuf];
    int fd_in, fd_out;
    int readCnt;

    if(argc != 3) {
        fprintf(stderr, "usage: %s sourceFile targetFile\n", argv[0]);
        exit(1);
    }
    fd_in = open(argv[1], O_RDONLY);
    if(fd_in < 0) {
        fprintf(stderr, "open error: %s\n", argv[1]);
        exit(1);
    }
    fd_out = open(argv[2], O_CREAT | O_WRONLY, 0600);   // file permission set to 600
    if(fd_out < 0) {
        fprintf(stderr, "open error: %s\n", argv[2]);
        exit(1);
    }
    // while(read_one_byte_from fd_in is successful) {
    //    write_one_byte_to fd_out;
    // }

    while( (readCnt = read(fd_in, buf, 50)) > 0) {
        write(fd_out, buf, 50);
    }
    // can change the number of bytes in the read() function to be a block size 4096
    // in such case, the amount of data in write() needs to be changed to readCnt;
    // i.e. write(fd_out, buf, readCnt);
    // one is encouraged to compare the performance of different approaches
}
