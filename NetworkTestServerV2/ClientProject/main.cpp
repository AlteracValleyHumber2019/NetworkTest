#include "TCP_Client.h"

/////////////////
// CLIENT MAIN //
/////////////////

int main(int argc, char* argv[])
{
	// Mike: Create a client 
	TCP_Client client = TCP_Client();

	// Mike: Initialize the client
	if (client.InitializeClient())
	{
		// Mike: Set the port and server address
		int port = 1234;
		const char* server_address = "127.0.0.1";

		// Mike: Prepare the client for connections
		if (client.PrepareForConnection(server_address, port))
		{
			// Mike: If the connection was prepared properly, then connect to the server
			if (client.ConnectToServer())
			{
				// Mike: if the client connects to the server, send them a message
				client.Send("Hello Server");
				bool waiting = true;

				// Mike: Run a while loop while waiting for a message back from the server
				while (waiting)
				{
					if (client.ReceiveMessage() == 1)
					{
						waiting = false;
					}
				}
			}
		}
	}

	getchar();

	return 0;
	
}