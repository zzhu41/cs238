#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    int fd;
    if(argc == 2) {
        fd = open(argv[1],O_RDONLY);
        int c;
        while(read(fd,&c,1)) {
            write(STDOUT_FILENO,&c,1);
        }
        close(fd);
    } else {
        dup2(fd, STDIN_FILENO);
        int c;
        while(read(fd,&c,1)) {
            write(STDOUT_FILENO,&c,1);
        }
        close(fd);
    }
    return 0;
}