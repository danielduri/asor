#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

int main(int argc, char const *argv[])
{
	if(argc!=2){
		printf("Please specify a valid host\n");
		exit(EXIT_FAILURE);
	}

	struct addrinfo *info;
	if(getaddrinfo(argv[1], NULL, NULL, &info)!=0){
		printf("Please specify a valid host\n");
		exit(EXIT_FAILURE);
	}

	while(info!=NULL){
		char host[NI_MAXHOST];
		if(getnameinfo(info->ai_addr, info->ai_addrlen, host, NI_MAXHOST, NULL, 0, NI_NUMERICHOST)!=0){
			printf("Error getting nameinfo\n");
			exit(EXIT_FAILURE);
		}
		printf("Family: %i\n Socket type: %i\n Numeric IP %s\n", info->ai_family, info->ai_socktype, host);
		info=info->ai_next;
	}

	freeaddrinfo(info);
	return 0;
}
