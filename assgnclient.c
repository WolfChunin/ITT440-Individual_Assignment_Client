#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h> //inet_addr
#include <stdlib.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h> //WRITE
#include <time.h>

int main(int argc, char *argv[])
{
	if(argc != 2) //TO DISPLAY AN ERROR IF THE NUMBER OF COMMAND LINE ARGUMENTS IS
	{		//NOT 2
		printf("Usage: %s <port>\n", argv[0]);
		exit(0);
	}

	int portnum = atoi(argv[1]);   //TO CONVERTS CHARACTER STRING TO AN INTEGER VALUE
	printf("Port Number: %d\n", portnum);

	char serverresp[100];
	int sock_desc;
	struct sockaddr_in server;

	//CREATING SOCKET
	sock_desc = socket(AF_INET, SOCK_STREAM, 0);
	if(sock_desc == -1)
	{
		printf("SOCKET FAILED TO CREATE!!!");
	}

	server.sin_addr.s_addr = inet_addr("192.168.46.6"); //IP ADDRESS OF THE SERVER
	server.sin_family = AF_INET;
	server.sin_port = htons( portnum );

	//CONNECTING TO REMOTE SERVER

	if(connect(sock_desc,(struct sockaddr*)&server, sizeof(server))<0)
	{
		puts("CONNECTING ERROR");
		return 1;
	}

	puts("Connected");
	recv(sock_desc, serverresp, 99, 0);	//TO RECEIVE THE RESPONSE FROM THE SERVER
	printf("Time from server: %s", serverresp);
	return 0;
}

/*SOURCES AND REFERENCES USED IN ORDER TO COMPLETE THIS INDIVIDUAL ASSINGMENT
1. https://github.com/nikhilroxtomar/Day-Time-Sever-Client-in-C/blob/master/client.c
2. https://www.youtube.com/watch?v=h_b16pSouM4
3. https://www.geeksforgeeks.org/tcp-server-client-implementation-in-c/
4. https://riptutorial.com/posix/example/17612/tcp-daytime-client
5. ITT440 LAB ACTIVITIES*/
