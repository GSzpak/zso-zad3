#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <linux/kernel.h>
#include <sys/syscall.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    long fd = syscall(359, argv[1], argv[2]);
    printf("System call sys_hello returned %ld\n", fd);
    close(fd);
    return 0;
}
