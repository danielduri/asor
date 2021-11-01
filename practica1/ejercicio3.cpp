#include <iostream>
#include <string.h>


int main(int argc, char const *argv[])
{
	for (int i = 0; i < 256; ++i)
	{
		std::cout << "Number " << i << ": " << strerror(i) << std::endl;
	}
	return 0;
}
