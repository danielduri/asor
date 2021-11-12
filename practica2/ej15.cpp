#include <iostream>
#include <unistd.h>
#include <sys/types.h>
       #include <sys/stat.h>
       #include <fcntl.h>
#include <time.h>


using namespace std;
int main(int argc, char const *argv[])
{
	if(argc!=2){
		cout << "Usage: <filepath>" << endl;
		exit(EXIT_FAILURE);
	}

	int fd = open(argv[1], O_RDWR);

	if(fd==-1){
		cout << "Couldn't open" << endl;
		return -1;
	}

	int status = lockf(fd, F_TEST, 0);

	if(status==0){
		cout << "Unlocked" << endl;
		
		struct tm *t;
	    time_t current=time(NULL);
	    t=localtime(& current);		
		cout << t->tm_hour << ":" << t->tm_min << ":" << t->tm_sec << endl;
		lockf(fd, F_LOCK, 0);
		sleep(30);
		lockf(fd, F_ULOCK, 0);	
	}else{
		cout << "Locked" << endl;
	}

	return 0;
}