int main(int argc, char const *argv[])
{
	if(argc!=3){
		printf("Please specify address and port\n");
		exit(EXIT_FAILURE);
	}

	struct addrinfo *info;

	if(getaddrinfo(argv[1], argv[2], NULL, &info)!=0){
		printf("Please specify A VALID address and port, in that order\n");
		exit(EXIT_FAILURE);
	}

	int fd=socket(info->ai_family, SOCK_DGRAM, 0);

	bind(fd, info->ai_addr, info->ai_addrlen);

	buf[c] = '\0';
	char host[NI_MAXHOST];
	char host[NI_MAXSERV];
	struct sockaddr_storage addr;

	while(1){
		c = recvfrom(fd, buf, 2, NULL, (struct sockaddr *) addr, sizeof(addr));
		getnameinfo((struct sockaddr *) &addr, sizeof(addr), host, NI_MAXHOST, serv, NI_MAXSERV, NI_NUMERICHOST|NI_NUMERICSERV);
		
	}

	return 0;
}
