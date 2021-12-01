#include <sys/select.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>


int main(int argc, char const *argv[])
{
	char buffer[256];

	int pipe1 = open("./pipe", O_RDONLY|O_NONBLOCK);
	int pipe2 = open("./fifo", O_RDONLY|O_NONBLOCK);

	int pipe, selection=0, currpipe;

	while(selection!=-1){
		fd_set set;
		FD_ZERO(&set);
		FD_SET(pipe1, &set);
		FD_SET(pipe2, &set);

		int maxfd;
		if(pipe1<pipe2){
			maxfd=pipe2+1;
		}else{
			maxfd=pipe1+1;
		}

		selection=select(maxfd, &set, NULL, NULL, NULL);

		if(selection>0){
			if(FD_ISSET(pipe1, &set)){
				pipe = 1;
				currpipe=pipe1;
			}else if(FD_ISSET(pipe2, &set)){
				pipe = 2;
				currpipe = pipe2;
			}

			ssize_t readsize = 255;
			
			while(readsize==255){
				readsize=read(currpipe, buffer, 255);

				buffer[readsize]='\0';
				printf("Tuberia %i: %s\n", pipe, buffer);
			}

			if(readsize!=255){
				if(pipe==1){
					close(pipe1);
					pipe1 = open("./pipe", O_RDONLY|O_NONBLOCK);
				}else if(pipe==2){
					close(pipe2);
					pipe2 = open("./fifo", O_RDONLY|O_NONBLOCK);
				}
			}

		}
	}

	close(pipe1);
	close(pipe2);

	return 0;
}