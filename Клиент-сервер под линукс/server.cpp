#include <stdio.h> 
#include <netdb.h> 
#include <netinet/in.h> 
#include <stdlib.h> 
#include <string.h> 
#include <arpa/inet.h>
#include <sys/socket.h> 
#include <sys/types.h>
#include <unistd.h>

#define MAX 80 
#define PORT 8080 
#define SA struct sockaddr 

class receiver
{
    private:
	char buff[MAX];
        int converted;
    public:
        void get_message(int sockfd);
};

int main() 
{ 
	int sockfd, connfd, len; 
	struct sockaddr_in servaddr, cli; 

        receiver r1;
	sockfd = socket(AF_INET, SOCK_STREAM, 0); 
	if (sockfd == -1) { 
		printf("socket creation failed...\n"); 
		exit(0); 
	} 
	else
		printf("Socket successfully created..\n"); 
	bzero(&servaddr, sizeof(servaddr)); 
	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY); //любой адрес
	servaddr.sin_port = htons(PORT);
	if ((bind(sockfd, (SA*)&servaddr, sizeof(servaddr))) != 0) { 
		printf("socket bind failed...\n"); 
		exit(0); 
	} 
	else
		printf("Socket successfully binded..\n"); 
	if ((listen(sockfd, 5)) != 0) { 
		printf("Listen failed...\n"); 
		exit(0); 
	} 
	else
		printf("Server listening..\n"); 
	len = sizeof(cli); 
	connfd = accept(sockfd, (SA*)&cli, (socklen_t*)&len); 
	if (connfd < 0) { 
		printf("server acccept failed...\n"); 
		exit(0); 
	} 
	else
		printf("server acccept the client...\n");

	r1.get_message(connfd); 
	close(sockfd); 
} 

void receiver::get_message(int sockfd){
	while(true){
		bzero(buff, MAX);
		read(sockfd, buff, sizeof(buff));
		printf("Server got: %s", buff);
		if(strncmp("exit", buff, 4) != 0){
			converted = atoi(buff);
			if(converted > 99 && converted % 32 == 0)
				printf("  Данные получены\n");
			else
				printf("  ОШИБКА. Данные отклонены.\n");
		}
		else
			break;
	}
}
