#include <stdio.h>
#include <unistd.h>
#include <sys/resource.h>
#include <stdlib.h>


int main(int argc, char const *argv[])
{
	pid_t pid=fork();

	if(pid==-1){
		perror("fork");
		exit(EXIT_FAILURE);
	}else if(pid==0){
		pid_t nuevoSID=setsid();
		chdir("/tmp");
		printf("HIJO\n");
	}else{
		sleep(30);
		printf("PADRE\n");
	}



	printf("PID: %i\n", getpid());
	printf("PPID: %i\n", getppid());
	printf("PGID: %i\n", getpgid(pid));
	printf("SID: %i\n", getsid(pid));

	struct rlimit max;
	getrlimit(RLIMIT_NOFILE, &max);

	printf("Máximo número de ficheros: %ld\n", max.rlim_max);

	char dir[1024];
	getcwd(dir, 1024);
	printf("Directorio de trabajo: %s\n", dir);

	return 0;
}
