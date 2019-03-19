//------------------------------------------------------------------
//------------------------------------------------------------------
#include "../SDL_net_test/UDP_Connection.h"
#include <windows.h>

int main(int argc, char **argv)
{
	UDPConnection udpConnection;

	std::string IP;
	int32_t localPort = 4321;
	int32_t remotePort = 0;

	std::cout
		<< "\n==========================================================================================================\n"
		<< "\tUDP CLIENT"
		<< "\n==========================================================================================================\n"
		<< "\tRemote IP   : The IP you want to connect to"
		<< "\n\tRemote Port : The port you want to connect to"
		<< "\nLocal port should be the same as remote port on the other instance of the application"
		<< "\n==========================================================================================================\n\n";

	std::cout << "Enter remote IP ( 127.0.0.1   for local connections ) : ";
	std::cin >> IP;
	std::cout << "Remote port : ";
	std::cin >> remotePort;

	udpConnection.Init(IP, remotePort, localPort);

	while (!udpConnection.WasQuit())
	{
		udpConnection.CheckForData();
		Sleep(1000);
	}

	return 0;
}
