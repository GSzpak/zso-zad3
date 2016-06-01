#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <linux/kernel.h>
#include <sys/syscall.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    long src_fd, dst_fd;
    src_fd = open(argv[1], O_RDONLY);
    dst_fd = open(argv[2], O_RDONLY);
    long syscall_res = syscall(359, src_fd, dst_fd);
    printf("System call sys_hello returned %ld\n", syscall_res);
    close(src_fd);
    close(dst_fd);
    return 0;
}
