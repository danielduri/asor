#include <unistd.h>
#include <iostream>

int main(int argc, char const *argv[])
{
	std::cout << "Child max: " << sysconf(_SC_CHILD_MAX) << std::endl;
	std::cout << "File max: " << sysconf(_SC_OPEN_MAX) << std::endl;

	return 0;
}