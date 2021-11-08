       #include <sys/types.h>
       #include <sys/stat.h>
       #include <time.h>
       #include <stdio.h>
       #include <stdlib.h>
       #include <sys/sysmacros.h>
       #include <unistd.h>
#include <iostream>
#include <string>

using namespace std;
	int main(int argc, char const *argv[])
	{
		if(argv[1]!=nullptr){
		   struct stat sb;

           if (lstat(argv[1], &sb) == -1) {
               perror("lstat");
               exit(EXIT_FAILURE);
           }

           if(sb.st_mode & S_IFMT == S_IFDIR){
           		char[] * sym = argv[1];
           		sym+=".sym";
           		char[] * hard = argv[1];
           		hard +=".hard";
           		link(argv[1], hard);
           		symlink(argv[1], sym);
           		return 0;
           }

           return -1;
	
		}else{
			cout << "Specify filename as an argv" << endl;
			return -1;
		}
	}