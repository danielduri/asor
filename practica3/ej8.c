#include <stdio.h>
#include <unistd.h>
#include <sys/resource.h>
#include <stdlib.h>
#include <sys/types.h>
       #include <sys/stat.h>
       #include <fcntl.h>
#include <sys/types.h>
       #include <sys/wait.h>




int main(int argc, char const *argv[])
{
	pid_t pid=fork();
	int status;

	if(pid==-1){
		perror("fork");
		exit(EXIT_FAILURE);
	}else if(pid==0){
		pid_t nuevoSID=setsid();

		int out = open("/tmp/daemon.out", O_RDWR|O_CREAT, 0777);
		int err = open("/tmp/daemon.err", O_RDWR|O_CREAT, 0777);
		int in = open("/dev/null", O_RDWR|O_CREAT, 0777);

		dup2(out, 1);
		dup2(err, 2);
		dup2(in, 0);

		execvp(argv[1], argv+1);
	}
	wait(&status);
	return 0;
}
