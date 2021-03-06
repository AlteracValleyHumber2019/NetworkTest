#ifndef UDP_CONNECTION_H
#define UDP_CONNECTION_H

#include <SDL_net.h>

#include <iostream>
#include <sstream>

#include "User.h"
#include <windows.h>

struct UDPConnection
{
	UDPConnection()
	{
		quit = false;
	}
	~UDPConnection()
	{
		SDLNet_FreePacket(packet);
		SDLNet_Quit();
	}

	//local port -> server where the client connects
	//remote port -> the local port on the server which the client connects to
	bool Init(const std::string &ip, int32_t remotePort, int32_t localPort)
	{
		std::cout << "Connecting to \n\tIP : " << ip << "\n\tPort : " << remotePort << std::endl;
		std::cout << "Local port : " << localPort << "\n\n";

		// Initialize SDL_net
		if (!InitSDL_Net())
			return false;

		if (!OpenPort(localPort))
			return false;

		if (!SetIPAndPort(ip, remotePort))
			return false;

		if (!CreatePacket(512))
			return false;

		return true;
	}
	bool InitSDL_Net()
	{
		std::cout << "Initializing SDL_net...\n";

		if (SDLNet_Init() == -1)
		{
			std::cout << "\tSDLNet_Init failed : " << SDLNet_GetError() << std::endl;
			return false;
		}

		std::cout << "\tSuccess!\n\n";
		return true;
	}
	bool CreatePacket(int32_t packetSize)
	{
		std::cout << "Creating packet with size " << packetSize << "...\n";

		// Allocate memory for the packet
		packet = SDLNet_AllocPacket(packetSize);

		if (packet == nullptr)
		{
			std::cout << "\tSDLNet_AllocPacket failed : " << SDLNet_GetError() << std::endl;
			return false;
		}

		// Set the destination host and port
		// We got these from calling SetIPAndPort()
		packet->address.host = serverIP.host;
		packet->address.port = serverIP.port;

		std::cout << "\tSuccess!\n\n";
		return true;
	}
	bool OpenPort(int32_t port)
	{
		std::cout << "Opening port " << port << "...\n";

		// Sets our sovket with our local port
		ourSocket = SDLNet_UDP_Open(port);

		if (ourSocket == nullptr)
		{
			std::cout << "\tSDLNet_UDP_Open failed : " << SDLNet_GetError() << std::endl;
			return false;
		}

		std::cout << "\tSuccess!\n\n";
		return true;
	}
	bool SetIPAndPort(const std::string &ip, uint16_t port)
	{
		std::cout << "Setting IP ( " << ip << " ) " << "and port ( " << port << " )\n";

		// Set IP and port number with correct endianess
		if (SDLNet_ResolveHost(&serverIP, ip.c_str(), port) == -1)
		{
			std::cout << "\tSDLNet_ResolveHost failed : " << SDLNet_GetError() << std::endl;
			return false;
		}

		std::cout << "\tSuccess!\n\n";
		return true;
	}
	// Send data. 
	bool Send(const std::string &str)
	{
		if (str == "quit")
			quit = true;
		// Set the data
		// UDPPacket::data is an Uint8, which is similar to char*
		// This means we can't set it directly.
		//
		// std::stringstreams let us add any data to it using << ( like std::cout ) 
		// We can extract any data from a std::stringstream using >> ( like std::cin )
		//
		//str

  		memcpy(packet->data, str.c_str(), str.length());
		packet->len = str.length();

		std::cout
			<< "==========================================================================================================\n"
			<< "Sending : \'" << packet->data << "\', Length : " << packet->len << "\n";

		// Send
		// SDLNet_UDP_Send returns number of packets sent. 0 means error
		if (SDLNet_UDP_Send(ourSocket, -1, packet) == 0)
		{
			std::cout << "\tSDLNet_UDP_Send failed : " << SDLNet_GetError() << "\n"
				<< "==========================================================================================================\n";
			return false;
		}

		std::cout << "\tSuccess!\n"
			<< "==========================================================================================================\n";

		
		return true;
	}
	const char* CheckForData()
	{
		std::cout << "\nCHECKING DATA:\n";
		// Check to see if there is a packet waiting for us...
		if (SDLNet_UDP_Recv(ourSocket, packet))
		{
			return reinterpret_cast<char*>(packet->data);
		}
	}
	bool WasQuit()
	{
		return quit;
	}

	UDPpacket *packet;
private:
	bool quit;
	UDPsocket ourSocket;
	IPaddress serverIP;
};

#endif //UDP_CONNECTION_H