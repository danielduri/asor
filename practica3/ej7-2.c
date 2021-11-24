#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
	if(argc<2){
		printf("Usage: <command>, for commands with saces, wrap command with " "\n");
		exit(EXIT_FAILURE);
	}
	execvp(argv[1], argv+1);
	printf("El comando terminó de ejecutarse\n");
	return 0;
}