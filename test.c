#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <linux/kernel.h>
#include <sys/syscall.h>
#include <unistd.h>

int main()
{
    long fd = syscall(359, "test.c", "test.c", O_CREAT | O_WRONLY | O_TRUNC, O_RDWR);
    printf("System call sys_hello returned %ld\n", fd);
    close(fd);
    return 0;
}
