#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
	if(argc<2){
		exit(EXIT_FAILURE);
	}

	int file=open("./pipe", O_WRONLY);
	size_t size = strlen(argv[1]);
	write(file,argv[1],size);

	close(file);
	return 0;
}