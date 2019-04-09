//------------------------------------------------------------------
//------------------------------------------------------------------
#include "UDP_Connection.h"


int main(int argc, char **argv)
{
	UDPConnection udpConnection;
	
	std::string IP;
	int32_t localPort = 8697;
	int32_t remotePort = 8697;

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

		if (command == '0') {
			std::cout << "Username: ";
			std::string username;
			std::cin >> username;

			std::cout << "Password: ";
			std::string password;
			std::cin >> password;

			std::cout << "Level: ";
			int level;
			std::cin >> level;

			User *user = new User(username, password, level);

			udpConnection.Send(user->to_string());
		}

		else if (command == '1')
			udpConnection.Send("quit");
		else if (command == '2')
			std::cout << udpConnection.CheckForData() << "\n";
		else
			std::cout << "Illegal command\n";
	}

	return 0;
}