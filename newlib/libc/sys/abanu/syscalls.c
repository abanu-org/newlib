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

__attribute__((noinline)) int __SysCall1(int target, int arg1)
{
	int ret;
	__asm__ volatile(
		 "int $250;"
		 : "=a"(ret)
		 : "a"((long)(target)), "b"(arg1)
		 : "%ecx", "%edx", "%edi", "%esi");
	return ret;
}

__attribute__((noinline)) int __SysCall2(int target, int arg1, int arg2)
{
	int ret;
	__asm__ volatile(
		 "int $250;"
		 : "=a"(ret)
		 : "a"((int)(target)), "b"(arg1), "c"(arg2)
		 : "%edx", "%edi", "%esi");
	return ret;
}

__attribute__((noinline)) int fstat(int file, struct stat *st)
{
	//void *addr = __SysCall2(20, 4096, 4); // 4 = basic
	//int result = __SysCall2(35, file, (int)addr);
	//*st = *((struct stat *)addr);
	//return result;
	return 0;
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
	void *addr = (void *)__SysCall1(24, incr); // 4 = basic
	return (caddr_t)addr;
}

int stat(const char *file, struct stat *st);

clock_t times(struct tms *buf);

int unlink(char *name);

int wait(int *status)
{
}

int write(int file, char *ptr, int len)
{
	char *addr = __SysCall2(20, 4096, 4); // 4 = basic

	int i;
	for (i = 0; i < len; i++)
	{
		addr[i] = ptr[i];
	}

	int result = __SysCall2(32, file, (int)addr);
	return len;
}

//int gettimeofday(struct timeval *p, struct timezone *z);
