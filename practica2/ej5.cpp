#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <iostream>

using namespace std;
int main(int argc, char const *argv[])
{
	if(argv[1]!=nullptr){
		int ret=open(argv[1], O_CREAT, S_IRUSR+S_IWUSR+S_IRGRP+S_IROTH+S_IXOTH);
		return ret;		
	}else{
		cout << "Specify filename as an argv" << endl;
		return -1;
	}
	
}