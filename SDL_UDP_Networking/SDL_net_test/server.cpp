//------------------------------------------------------------------
//------------------------------------------------------------------
#include "UDP_Connection.h"


int main(int argc, char **argv)
{
	UDPConnection udpConnection;
	
	std::string IP;
	int32_t localPort = 0;
	int32_t remotePort = 8697;

	std::cout
		<< "\n==========================================================================================================\n"
		<< "\t\tUDP Server"
		<< "\n==========================================================================================================\n"
		<< "\tRemote IP   : The IP you want to connect to"
		<< "\n\tLocal port  : Server port"
		<< "\nLocal port should be the same as remote port on the other instance of the application"
		<< "\n==========================================================================================================\n\n";

	std::cout << "Enter remote IP ( 127.0.0.1  for local connections ) : ";
	std::cin >> IP;

	std::cout << "Enter local port : ";
	std::cin >> localPort;

	udpConnection.Init(IP, remotePort, localPort);


	uint8_t command = 0;

	while (!udpConnection.WasQuit())
	{
		std::cout
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
			std::cout << "Illegal command\n";
	}

	return 0;
}