#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
	if(argc!=2){
		printf("Usage: <command>. For args, wrap entire command with \" \".\n");
		exit(EXIT_FAILURE);
	}
	system(argv[1]);
	printf("El comando terminó de ejecutarse\n");
	return 0;
}