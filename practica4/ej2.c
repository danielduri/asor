#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{

	int p_h[2];
	int h_p[2];
	pipe(p_h);
	pipe(h_p);
	int pid=fork();

	if(pid==0){
		close(p_h[1]);
		close(h_p[0]);

		for (int i = 0; i < 10; ++i)
		{
			char message[1000];
			int size=read(p_h[0], message, 1000);
			write(1, message, size);
			sleep(1);
			char l[1];
			l[0] = 'l';
			write(h_p[1], l, 1);
		}
		char q[1];
		q[0] = 'q';
		write(h_p[1], q, 1);

		close(p_h[0]);
		close(h_p[1]);
		exit(EXIT_SUCCESS);

	}else{

		close(p_h[0]);
		close(h_p[1]);

		char stdin[1000];
		char childStatus[1];
		childStatus[0] = 'l';

		while(childStatus[0]!='q'){
			int size=read(0, stdin, 999);
			stdin[size]='\0';

			write(p_h[1], stdin, size+1);
			read(h_p[0], childStatus, 1);
		}
		close(p_h[1]);
		close(h_p[0]);
		exit(EXIT_SUCCESS);

	}

	return 0;
}
