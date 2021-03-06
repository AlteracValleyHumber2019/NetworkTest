#pragma once
#include <conio.h>
#include <mysql.h>
#include <iostream>
#include <string>
#include "sha256.h"

using namespace std;

class DataBaseConnection
{
public:

	MYSQL* conn;

	DataBaseConnection(bool _success);
	DataBaseConnection(string _hostname, string _loginname, string _loginpassword, string _databasename, int _port, bool _success);
	DataBaseConnection(char* _hostname, char* _loginname, char* _loginpassword, char* _databasename, int _port, bool _success);

	MYSQL_RES* fetchInformation(string _query);
	MYSQL_RES* fetchInformation(char* _query);
	string parseHash(string password,MYSQL_ROW databasePass);
	string retreiveKey(string input);
	string editRetreived(string input);
	void sendInformation(const char* _query);

	~DataBaseConnection();

private:
	int qstate;
	

	MYSQL_RES *res;
};

