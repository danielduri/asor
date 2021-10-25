#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>


int main()
{
	if(setuid(0)==-1){
		perror("Error");
		std::cout << "Error number: " << errno << std::endl;
		std::cout << strerror(errno) << std::endl;
	}	
	return 1;
}