#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	if(argc!=5){
		printf("Usage: command1 arg1 command2 arg2\n");
		exit(EXIT_FAILURE);
	}

	int fd[2];
	pipe(fd);
	int pid=fork();

	if(pid==0){
		close(fd[1]);
		dup2(fd[0], 0);
		close(fd[0]);
		execlp(argv[3], argv[3], argv[4], NULL);
	}else{
		close(fd[0]);
		dup2(fd[1], 1);
		close(fd[1]);
		execlp(argv[1], argv[1], argv[2], NULL);
	}

	return 0;
}
