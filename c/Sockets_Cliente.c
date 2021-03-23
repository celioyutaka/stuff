/*

CÉLIO YUTAKA
CLIENTE

*/

#define WINDOWS

#ifdef WINDOWS
#include <winsock.h>
#include <windows.h>
#include <pthread.h>
#endif

#ifdef LINUX
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#define closesocket(n) close(n)
#define SOCKET socklen_t
#endif

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>

#define DEFAULT_PORT 65010
#define IPADDRESS "127.0.0.1"
#define MAX_SIZE 1024
#define NUM_THREADS     5

using namespace std;
 SOCKET connect_socket;
void *DigitarMensagem(void  *cs)
{
//   long *tid;
//   tid = (long*)threadid;
//   cout << "tester" << endl;
    int i;
    char Buffer[MAX_SIZE] = "";
    int retval;
    //SOCKET *connect_socket = (SOCKET*)(cs);

    fflush(stdin);
    memset(Buffer,0x0,sizeof(Buffer));
    cin.getline(Buffer, MAX_SIZE);

    //fgets(Buffer,MAX_SIZE,stdin);
    fflush(stdin);


    retval = send(connect_socket, Buffer, sizeof (Buffer), 0);
    if (strlen(Buffer) > 1)
    {
        if (retval <= 0)
        {
            cout << "Client: send() failed: error: " << endl;
            closesocket(connect_socket);
            exit(-3);
        }
        else{
            memset(Buffer,0x0,MAX_SIZE);
        }
    }


    pthread_exit(NULL);
}


int main(int argc, char** argv)
{
    char Buffer[MAX_SIZE];
	char BufferR[MAX_SIZE];
	pthread_t threads[NUM_THREADS];
    int retval;
    int rc;
   	int t = 0;
#ifdef WINDOWS
    int fromlen;
#else
    socklen_t fromlen;
#endif

    struct sockaddr_in server, client;


#ifdef WINDOWS
    WSADATA wsaData;

    if ((retval = WSAStartup(0x202, &wsaData)) != 0)
    {
        cout << "Server: WSAStartup() failed with error: " << retval << endl;
        WSACleanup();
        return -1;
    }
    else
        cout << "Server: WSAStartup() is OK." << endl;
#endif

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(IPADDRESS);
    server.sin_port = htons(DEFAULT_PORT);

    connect_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (connect_socket < 0)
    {
        cout << "Client: socket() failed with error: " << connect_socket << endl;
        exit(-1);
    }
    else
        cout << "Client: socket() is OK." << endl;

    if (connect(connect_socket, (struct sockaddr*) &server, sizeof (server)) < 0)
    {
        cout << "Client: connect() failed\n" << endl;
        exit(-2);
    }
    else
        cout << "Client: connect() is OK." << endl;
    int i ;
    while(1){

        rc = pthread_create(&threads[t], NULL, DigitarMensagem, &connect_socket);



        //fflush(stdin);

        retval = recv(connect_socket, BufferR, sizeof (BufferR), 0);
        if (retval <= 0)
        {
            cout << "Client: recv() failed" << endl;
            exit(-4);
        }
        //else
            //cout << "Client: recv() is OK." << endl;

        if (strlen(BufferR) > 0){

            cout << "Recebido: " << BufferR << endl;
        }
            //
    }
    closesocket(connect_socket);
#ifdef LINUX
    sleep(5);
#endif

    exit(0);
}

