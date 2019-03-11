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
	conn = mysql_real_connect(conn, "localhost", "root", "root", "loginDatabase", 3306, NULL, 0);

	//Conn will be false if the connection failed
	if (conn) {
		puts("Successful connection to the Database!");

		bool connected = false;


		while (!connected)
		{
			system("CLS");

			cout << "Enter your Username OR Email : ";
			string user;
			cin >> user;

			cout << "Enter your Password : ";
			string pass;
			cin >> pass;

			string query1 = "SELECT * FROM players WHERE (player_name = '" + user + "') OR (player_email = '" + user + "')";
			cout << "Query from the server : " + query1 << endl;
			system("PAUSE");

			const char* q1 = query1.c_str();

			qstate = mysql_query(conn, q1);

			if (!qstate)
			{
				res = mysql_store_result(conn);

				//row will be FALSE if no result is found
				if (row = mysql_fetch_row(res))
				{
					//We will get only 1 line as a result
					//Data is stored as... ID, name, pass, email
					if (pass == row[2])
						cout << "Connected to the server succesfully under : " + user + " !" << endl;
					else
						cout << "Incorrect password, try again" << endl;


					system("PAUSE");
					connected = true;
					
				}
				else
				{
					cout << "Could not find username or email in the database... ";
					system("PAUSE");
				}
			}

		}

		//A normal SQL query

		cout << "Now dumping database..." << endl;
		system("PAUSE");
		system("CLS");
		string query = "SELECT * FROM players";
		const char* q = query.c_str();

		qstate = mysql_query(conn, q);
		if (!qstate)
		{
			res = mysql_store_result(conn);

			//Iterates through the results from the request and prints them
			while (row = mysql_fetch_row(res))
				cout << "ID: " << row[0] << ", Name: " << row[1] << ", Password : " << row[2] << ", Email : " << row[3] << endl;
		}
		else
		{
			//Request failed, table not existant or query incorrect
			cout << "Query failed: " << mysql_error(conn) << endl;
		}
	}
	else {
		//Connection failed
		puts("Database connection failed - Please contact an admin");
	}

	return 0;
}