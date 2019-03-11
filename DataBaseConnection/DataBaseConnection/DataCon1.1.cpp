// MySqlTest.cpp : Defines the entry point for the console application.
//

#include "pch.h"
#include <mysql.h>
#include <iostream>
#include <string>

using namespace std;
int qstate;

int main()
{
	MYSQL* conn;
	MYSQL_ROW row;
	MYSQL_RES *res;
	conn = mysql_init(0);

	//Host Name / Login User / Login Password / Database Name / Port
	conn = mysql_real_connect(conn, "localhost", "root", "root", "testdb", 3306, NULL, 0);

	//Conn will be false if the connection failed
	if (conn) {
		puts("Successful connection to the Database!");

		//A normal SQL query
		string query = "SELECT * FROM test";
		const char* q = query.c_str();

		qstate = mysql_query(conn, q);
		if (!qstate)
		{
			res = mysql_store_result(conn);

			//Iterates through the results from the request and prints them
			while (row = mysql_fetch_row(res))
			{
				cout << "ID: " << row[0] << ", Name: " << row[1] << ", Value : " << row[2] << endl;
			}
		}
		else
		{
			//Request failed, table not existant or query incorrect
			cout << "Query failed: " << mysql_error(conn) << endl;
		}
	}
	else {
		//Connection failed
		puts("Database connection failed.");
	}

	return 0;
}