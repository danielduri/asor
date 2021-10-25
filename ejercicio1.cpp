#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>


int main()
{
	int errno;
	errno=setuid(0);
	std::cout << strerror(errno) << std::endl;
	return 1;
}