       #include <stdlib.h>
       #include <stdio.h>
       #include <unistd.h>
       #include <sys/types.h>
       #include <sys/stat.h>
       #include <fcntl.h>

int main(int argc, char const *argv[])
{
	if(argc!=2){
		printf("%s\n", "Usage: file name");
		exit(EXIT_FAILURE);
	}

	int fd = open(argv[1], O_CREAT | O_RDWR, 0777);

	dup2(fd, 1);

	printf("%s\n", "Hello");
	printf("%s\n", "Now logging");
	printf("%s\n", "Hi");

	return 0;
}