#pragma once

#include <string>
#include <iostream>
#include <algorithm> 
#include <cctype>
#include <locale>
#include <sstream> 

class Debug
{
public:
	static void Log(const std::string& message)
	{
		std::cout << message << std::endl;
	}

	static void ClearScreen()
	{
		std::system("cls");
	}

	static std::string ReadLine()
	{
		std::string line;
		std::getline(std::cin, line);
		Trim(line);
		return line;
	}

	static int ReadInt()
	{
		std::string line = ReadLine();
		int i = 0;
		StringToInt(i, line.c_str());
		return i;
	}

private:

	static bool StringToInt(int& i, char const* s)
	{
		std::stringstream ss(s);
		ss >> i;
		if (ss.fail())
		{
			i = -1;
			return false;
		}
		return true;
	}

	static inline void Ltrim(std::string& s)
	{
		s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int ch)
		{
			return !std::isspace(ch);
		}));
	}

	// trim from end (in place)
	static inline void Rtrim(std::string& s)
	{
		s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch)
		{
			return !std::isspace(ch);
		}).base(), s.end());
	}

	// trim from both ends (in place)
	static inline void Trim(std::string& s)
	{
		Ltrim(s);
		Rtrim(s);
	}
};

