#include <sys/utsname.h>
#include <iostream>

int main(int argc, char const *argv[])
{
	utsname structure;
	uname(& structure);
	std::cout << "Sysname: " << structure.sysname << std::endl;
	std::cout << "Nodename: " << structure.nodename << std::endl;
	std::cout << "Release: " << structure.release << std::endl;
	std::cout << "Version: " << structure.version << std::endl;
	std::cout << "Machine: " << structure.machine << std::endl;
	return 0;
}