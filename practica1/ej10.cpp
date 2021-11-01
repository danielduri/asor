#include <pwd.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <iostream>


int main(int argc, char const *argv[])
{
	struct passwd * pwd;
	pwd=getpwuid(getuid());
	std::cout << "User ID: " << getuid() << std::endl;
	std::cout << "Effective User ID: " << geteuid() << std::endl;
	std::cout << "Username: " << pwd->pw_name << std::endl;
	std::cout << "Directory:  " << pwd->pw_dir << std::endl;
	std::cout << "Description: " << pwd->pw_gecos << std::endl;
	return 0;
}
