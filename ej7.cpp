#include <unistd.h>
#include <iostream>
#include <stdio.h>
const char * path = "dummyfile";

int main(int argc, char const *argv[])
{
	std::cout << "Link max: " << pathconf(path, _PC_LINK_MAX) << std::endl;
	std::cout << "Name max: " << pathconf(path, _PC_NAME_MAX) << std::endl;

	return 0;
}