#ifndef USER_H
#define USER_H

#include <iostream>

class User
{
private:
	std::string username;
	std::string password;
	int level;
public:

	User(std::string _username, std::string _password, int _level)
	{
		username = _username;
		password = _password;
		level = _level;
	}

	//Username
	std::string getUsername()
	{
		return username;
	}
	void setUsername(char* _username)
	{
		username = _username;
	}

	//passsword
	std::string getPassword()
	{
		return password;
	}
	void setPassword(char* _password)
	{
		password = _password;
	}

	//Level
	int getLevel()
	{
		return level;
	}
	void setLevel(int _level)
	{
		level = _level;
	}

	std::string to_string() {
		return "Username : " + username + "Level : " + std::to_string(level);
	}
};

#endif //!USER_H
