//------------------------------------------------------------------
//------------------------------------------------------------------
#include "../SDL_net_test/UDP_Connection.h"
#include <Windows.h>

int main(int argc, char **argv)
{
	UDPConnection udpConnection;

	std::string IP;
	int32_t localPort = 0;
	int32_t remotePort = 0;

	std::cout
		<< "\n==========================================================================================================\n"
		<< "UDP connection - A simple test for UDP connections using SDL_Net!"
		<< "\n==========================================================================================================\n"
		<< "You'll be asked to enter the following :"
		<< "\n\tRemote IP   : The IP you want to connect to"
		<< "\n\tRemote Port : The port you want to connect to"
		<< "\n\tLocal port  : Your port"
		<< "\nLocal port should be the same as remote port on the other instance of the application"
		<< "\n==========================================================================================================\n\n";

	std::cout << "Enter remote IP ( 127.0.0.1   for local connections ) : ";
	std::cin >> IP;
	std::cout << "...and remote port : ";
	std::cin >> remotePort;

	std::cout << "Enter local port : ";
	std::cin >> localPort;

	udpConnection.Init(IP, remotePort, localPort);


	uint8_t command = 0;

	while (!udpConnection.WasQuit())
	{
		/*std::cout
			<< "Your command : "
			<< "\n\t0 : Send a message"
			<< "\n\t1 : Quit"
			<< "\n\t2 : Check for data"
			<< std::endl;

		std::cin >> command;

		if (command == '0')
			udpConnection.Send("This is a test");
		else if (command == '1')
			udpConnection.Send("quit");
		else if (command == '2')
			udpConnection.CheckForData();
		else
			std::cout << "Illegal command\n";*/

		udpConnection.CheckForData();
		Sleep(2000);
	}

	return 0;
}
