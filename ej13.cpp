#include <sys/time.h>
#include <iostream>

int main(int argc, char const *argv[])
{
	struct timeval begin;
	struct timeval end;
	struct timeval *interval;
	gettimeofday(& begin, NULL);
	for (int i = 0; i<1000000; ++i)
	{
		
	}
	gettimeofday(& end, NULL);
	std::cout << end.tv_usec-begin.tv_usec << "ms" << std::endl;

	return 0;
}