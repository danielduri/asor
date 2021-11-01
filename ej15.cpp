#include <time.h>
#include <iostream>

int main(int argc, char const *argv[])
{
    char outstr[200];
    //char outstr2[200];
    struct tm *t;
    time_t current=time(NULL);
    t=localtime(& current);

    setlocale(LC_ALL, "es_ES");

    if (strftime(outstr, sizeof(outstr), "%A, %e de %B de %Y, %H:%M", t) == 0) {
        fprintf(stderr, "strftime returned 0");
        exit(EXIT_FAILURE);
    }

    //strftime(outstr2, sizeof(outstr2), " %+ ", t);
    //std::cout << outstr2 << std::endl;


    std::cout << outstr << std::endl;
    return 0;
}
