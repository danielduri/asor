#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>


int main()
{
	setuid(0);
	perror("Error");
	std::cout << "Error number: " << errno << std::endl;
	std::cout << strerror(errno) << std::endl;
	return 1;
}