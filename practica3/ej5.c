#include <stdio.h>
#include <unistd.h>
#include <sys/resource.h>

int main(int argc, char const *argv[])
{
	pid_t pid=getpid();
	printf("PID: %i\n", pid);
	printf("PPID: %i\n", getppid());
	printf("PGID: %i\n", getpgid(pid));
	printf("SID: %i\n", getsid(pid));

	struct rlimit max;
	getrlimit(RLIMIT_NOFILE, &max);

	printf("Max file desc: %lld\n", max.rlim_max);

	char dir[1024];
	getcwd(dir, 1024);
	printf("Directorio de trabajo: %s\n", dir);

	return 0;
}
