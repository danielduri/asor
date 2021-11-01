#include <unistd.h>
#include <sys/types.h>
#include <iostream>


int main(int argc, char const *argv[])
{
	std::cout << "User ID: " << getuid() << std::endl;
	std::cout << "Effective User ID: " << geteuid() << std::endl;
	return 0;
}
