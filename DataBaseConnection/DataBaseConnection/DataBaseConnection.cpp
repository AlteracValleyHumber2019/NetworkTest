#pragma once
#include "DataBaseConnection.h"
#include <openssl/hmac.h>
using namespace std;


DataBaseConnection::DataBaseConnection(bool _success)
{
	conn = mysql_init(0);
	//Host Name / Login User / Login Password / Database Name / Port
	conn = mysql_real_connect(conn, "remotemysql.com", "xLrH61KxG0", "Ps26I2WARu", "xLrH61KxG0", 3306, NULL, 0);

	//Conn will be false if the connection failed
	if (conn)
	{
		puts("Successful connection to the Database!");
		_success = true;
	}
	else
	{
		puts("Unsuccesful connection to the Database..");
		_success = false;
	}
}

DataBaseConnection::DataBaseConnection(string _hostname, string _loginname, string _loginpassword, string _databasename, int _port, bool _success)
{
	conn = mysql_init(0);
	//Host Name / Login User / Login Password / Database Name / Port
	conn = mysql_real_connect(conn, _hostname.c_str(), _loginname.c_str(), _loginpassword.c_str(), _databasename.c_str(), _port, NULL, 0);

	//Conn will be false if the connection failed
	if (conn)
	{
		puts("Successful connection to the Database!");
		_success = true;
	}
	else
	{
		puts("Unsuccesful connection to the Database..");
		_success = false;
	}
}

DataBaseConnection::DataBaseConnection(char * _hostname, char * _loginname, char * _loginpassword, char * _databasename, int _port, bool _success)
{
	conn = mysql_init(0);
	//Host Name / Login User / Login Password / Database Name / Port
	conn = mysql_real_connect(conn, _hostname, _loginname, _loginpassword, _databasename, _port, NULL, 0);

	//Conn will be false if the connection failed
	if (conn)
	{
		puts("Successful connection to the Database!");
		_success = true;
	}
	else
	{
		puts("Unsuccesful connection to the Database..");
		_success = false;
	}
}

string DataBaseConnection::editRetreived(string input) {
	input.erase(0, 9);
	return input;
}
string  DataBaseConnection::retreiveKey(string input) {
	input.erase(0, 7);
	input.erase(1, input.length());
	return input;
}
string DataBaseConnection::parseHash(string password, MYSQL_ROW databasePass) {
	char key[] = "";
	string foo = databasePass[3];
	strcpy(key, retreiveKey(foo).c_str());

	char data[32];
	strcpy(data, password.c_str());
	
	unsigned char* digest;
	digest = HMAC(EVP_sha256(), key, strlen(key), (unsigned char*)data, strlen(data), NULL, NULL);
	char mdString[128];
	for (int i = 0; i < 32; i++)
		sprintf(&mdString[i * 2], "%02x", (unsigned int)digest[i]);
	puts(mdString);
	return mdString;
}
MYSQL_RES* DataBaseConnection::fetchInformation(string _query)
{

	const char* q1 = _query.c_str();

	//Creates the query state
	qstate = mysql_query(conn, q1);

	//If it's a valid query
	if (!qstate)
		return mysql_store_result(conn);
	else
		return nullptr;
}

MYSQL_RES * DataBaseConnection::fetchInformation(char * _query)
{
	//Creates the query state
	qstate = mysql_query(conn, _query);

	//If it's a valid query
	if (!qstate)
		return mysql_store_result(conn);
	else
		return nullptr;
}

void DataBaseConnection::sendInformation(const char * _query)
{
}


DataBaseConnection::~DataBaseConnection()
{
}
