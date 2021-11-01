#include <time.h>
#include <iostream>

int main(int argc, char const *argv[])
{
    struct tm *t;
    time_t current=time(NULL);
    t=localtime(& current);
    std::cout << t->tm_year+1900 << std::endl;
    return 0;
}
