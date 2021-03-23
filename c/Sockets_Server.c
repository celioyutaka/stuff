/*

CÉLIO YUTAKA
SERVIDOR

*/
#include <winsock.h>
#include <windows.h>
#include <pthread.h>
#include <unistd.h>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>

#define DEFAULT_PORT 65010
#define IPADDRESS "127.0.0.1"
#define MAX_SIZE 1024

using namespace std;

SOCKET msgsock[100];

void enviarMensagemClientes(char *Buffer)
{
    int i;
	int retval;
	//if (strlen(Buffer) > 0)
	//cout << "texto sendo enviado p cliente:("<< strlen(Buffer)<<") " << Buffer << endl;

    for (i = 0; i < 100; i++)
    {
        //if ( msgsock[i] > 0)
            //cout << "socketTHREAD: " << msgsock[i] << endl;
         retval = send(msgsock[i], Buffer, sizeof (Buffer), 0);
         //retval = send(*sockclient, Buffer, sizeof (Buffer), 0);
    }

}


void * THClientSession(void * socketid)
{
	SOCKET * sockclient = (SOCKET *)socketid;
	char Buffer[MAX_SIZE];
	int retval;
	int fromlen;
    struct sockaddr_in from;

	while (1)
    {

		//cout << "Thread: New Thread for socket: " << *sockclient << endl;



        fromlen = sizeof (from);

        retval = recv(*sockclient, Buffer, sizeof (Buffer), 0);

        if (retval < 0)
        {
            cout << "No bytes received" << endl;
            break;
	    }
        //else
            //printf("Server: recv() is OK.\n");

        if (retval == 0)
        {
            printf("Server: Client closed connection.\n");
			break;
        }

        //cout << "Server: Received " << retval << " bytes" << endl;


        //printf("Server: Echoing the same data back to client...\n");

        //strupr(Buffer);
        //if (*sockclient > 0)
            //cout << "socketINDV: " << *sockclient << endl;
        //retval = send(*sockclient, Buffer, sizeof (Buffer), 0);
        if (strcmp(strupr(Buffer),"QUIT") == 0)
		{
            memset(Buffer,0x0,MAX_SIZE);
			break;
		}

		if (strlen(Buffer) > 0)
            cout << "CLIENTE["<< *sockclient << "]: " << Buffer << endl;

        int i;
        for (i = 0; i < 100; i++)
        {
            if (msgsock[i] > 0){


                retval = send(msgsock[i], Buffer, sizeof (Buffer), 0);
            }
        }

        //enviarMensagemClientes(Buffer);

        memset(Buffer,0x0,MAX_SIZE);
        //retval = send(*sockclient, Buffer, sizeof (Buffer), 0);


        if (retval < 0)
        {
            cout << "Server: send() failed: error: " << endl;
        }
        //else
            //cout << "Server: send() is OK." << endl;




    }
    closesocket(*sockclient);

}

int main(int argc, char **argv)
{
    int retval, fromlen;
    struct sockaddr_in local, from;
    SOCKET listen_socket;
    WSADATA wsaData;
    pthread_t threads;
    // threads
	int * retthreads = new int;
    int thindx = 0;
    pthread_t thret;

    if ((retval = WSAStartup(0x202, &wsaData)) != 0)
    {
        cout << "Server: WSAStartup() failed with error: " << retval << endl;
        WSACleanup();
        return -1;
    }
    else
        cout << "Server: WSAStartup() is OK." << endl;

	//
	// Criando o socket do servidor (passivo)
	//
    listen_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (listen_socket == INVALID_SOCKET)
    {
        cout << "Server: socket() failed with error: " << listen_socket << endl;
        exit(-1);
    }
    else
        cout << "Server: socket() is OK." << endl;

	//
	// Parârametros de configuração do socket
	//
    local.sin_family = AF_INET;
    local.sin_addr.s_addr = INADDR_ANY;
    local.sin_port = htons(DEFAULT_PORT);

    if (bind(listen_socket, (struct sockaddr*) &local, sizeof (local)) == SOCKET_ERROR)
    {
        cout << "Server: bind() failed with error: " << endl;
        exit(-2);
    }

    cout << "Server: bind() is OK.";

	//
	// colocando o socket no estado de listen
	//
    if (listen(listen_socket, 5) == SOCKET_ERROR)
    {
        cout << "Server: listen() failed with error: " << endl;
        exit(-3);
    }
    //else
        //cout << "Server: listen() is OK" << endl;

    cout << "Server: listening and waiting connection on port " << DEFAULT_PORT << endl;

    fromlen = sizeof(from);

	while (1) {
		//
		// Aguardando conexão do cliente
		//

        msgsock[thindx] = accept(listen_socket,
                         (struct sockaddr*) &from,
                         &fromlen);

        if ( msgsock[thindx] == INVALID_SOCKET)
        {
            cout << "Server: accept() error: " << INVALID_SOCKET << endl;
            continue;
        }
        //else
            //cout << "Server: accept() is OK (" << msgsock[thindx] << ")" << endl;

        fflush(stdout);

    	thret = pthread_create((pthread_t *)&threads,NULL,THClientSession,(void *)&msgsock[thindx]);
		thindx++;

		if (thindx >= 100)
			Sleep(3600);

	}

    closesocket(listen_socket);

    exit(0);
}

