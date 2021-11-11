       #include <sys/types.h>
       #include <sys/stat.h>
       #include <time.h>
       #include <stdio.h>
       #include <stdlib.h>
       #include <sys/sysmacros.h>
       #include <unistd.h>
       #include <string.h>

	int main(int argc, char const *argv[])
	{
		if(argv[1]!=NULL){
		   struct stat sb;

           if (lstat(argv[1], &sb) == -1) {
               perror("lstat");
               exit(EXIT_FAILURE);
           }

           if(S_ISREG(sb.st_mode)){
           		char * sym = malloc(sizeof(char) * (strlen(argv[1])));
           		char * hard = malloc(sizeof(char) * (strlen(argv[1])));
           		
                strcpy(hard, argv[1]);
                strcpy(sym, argv[1]);

                if(symlink(argv[1], strcat(sym, ".sym"))==-1){
                    perror("Couldn't create symbolic link");
                }else{
                    printf("%s\n","Symbolic link created");
                }

           		if(link(argv[1], strcat(hard, ".hard"))==-1){
                    perror("Couldn't create hard link");
                }else{
                    printf("%s\n","Hard link created");
                }
           		return 0;
           }

           return -1;
	
		}else{
			perror("Specify filename as an argv");
			exit(EXIT_FAILURE);
		}
	}
