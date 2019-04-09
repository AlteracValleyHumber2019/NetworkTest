#include "TCP_Server.h"

/////////////////
// SERVER MAIN //
/////////////////

int main(int argc, char* argv[])
{
	// Mike: Create a client 
	TCP_Server server = TCP_Server();

	// Mike: Initialize the client
	if (server.InitializeServer())
	{
		// Mike: Set the port and server address
		int port = 1234;

		// Mike: Prepare the client for connections
		server.PrepareForConnection(port);
	}

	// Mike: Setup a running boolean, keeping the server active while it waits for a message
	bool running = true;

	while (running)
	{
		// Mike: if the server receives a message, update server will return 1, which will stop the process
		if (server.UpdateServer() == 1)
		{
			running = false;
		}
	}

	getchar();

	return 0;
}