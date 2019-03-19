#ifndef TCP_CLIENT_H  
#define TCP_CLIENT_H

#include <SDL_net.h>
#include <iostream>
#include <cstring>
#include <stdio.h>
#include <thread>

class TCP_Client
{

public:
	TCP_Client();
	~TCP_Client();

	/* Mike: This function will initialize SDL 
	Return: true on success and false if something goes wrong */
	bool InitializeClient();

	/* Mike: This function will setup the ip of this client using the passed host and port for connections 
	Return: true on success and false if something goes wrong */
	bool PrepareForConnection(const char* host_address_, int portToConnect_);

	/* Mike: This method will attempt to connec to the host server 
	Return: true on success and false if something goes wrong */
	bool ConnectToServer();

	void Send(std::string message_);

	int ReceiveMessage();

	void UpdateClient();


private:
	//The IP address of this client
	IPaddress ip;

	//The port number to connect to
	int port_client;

	//The socket for the TCP connection for the server
	TCPsocket server_TCPsocket;

	//Create the socket for this client
	TCPsocket client_TCPsocket;

	//Boolean that stores the state of this clients connection
	bool bIsConnected;

};


#endif
