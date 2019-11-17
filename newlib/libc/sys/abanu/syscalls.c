/* note these headers are all provided by newlib - you don't need to provide them */
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/fcntl.h>
#include <sys/times.h>
#include <sys/errno.h>
#include <sys/time.h>
#include <stdio.h>

void _exit()
{
}

int close(int file)
{
    return 0;
}

char **environ; /* pointer to array of char * strings that define the current environment variables */

int execve(char *name, char **argv, char **env);

int fork();

__attribute__ ((noinline)) int _SCall_(int target, int arg1)
{
    int ret;
    __asm__ volatile (
        "int $250;"
        : "=a" (ret)
        : "a" ((long)(target)), "b" (arg1)
    );
    return ret;
}

__attribute__ ((noinline)) int fstat(int file, struct stat *st)
{
    return _SCall_(88, 89);
}

int getpid();

int isatty(int file)
{
    return 0;
}

int kill(int pid, int sig);

int link(char *old, char *new);

int lseek(int file, int ptr, int dir)
{
    return 0;
}

int open(const char *name, int flags, ...);

int read(int file, char *ptr, int len)
{
    return 0;
}

caddr_t sbrk(int incr)
{
    return (caddr_t)0;
}

int stat(const char *file, struct stat *st);

clock_t times(struct tms *buf);

int unlink(char *name);

int wait(int *status)
{
}

int write(int file, char *ptr, int len)
{
}

//int gettimeofday(struct timeval *p, struct timezone *z);
