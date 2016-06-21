#include <stdio.h>
#include <fcntl.h>
#include <linux/kernel.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <stdlib.h>

#define SYS_cow_cp 359

int main(int argc, char *argv[])
{
    long src_fd, dst_fd, res;

    if (argc != 3) {
        printf("Usage: %s <source_file> <destination_file>\n", argv[0]);
        exit(1);
    }

    src_fd = open(argv[1], O_RDONLY);
    if (src_fd < 0) {
        perror("Error while opening source file\n");
        exit(1);
    }

    dst_fd = open(argv[2], O_RDWR | O_CREAT | O_TRUNC);
    if (src_fd < 0) {
        perror("Error while opening destination file file\n");
        close(src_fd);
        exit(1);
    }

    res = syscall(SYS_cow_cp, src_fd, dst_fd);
    close(src_fd);
    close(dst_fd);
    if (res < 0) {
        perror("Error in syscall\n");
    }
    return res;
}
