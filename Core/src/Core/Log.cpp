#include "corepch.h"
#include "Log.h"

#include <iostream>

namespace KMG
{
	void Log::Trace(const std::string& text)
	{
		std::cout << "[LOG] " << text << std::endl;
	}

	void Log::Info(const std::string& text)
	{
		std::cout << "[INFO] " << text << std::endl;
	}

	void Log::Warn(const std::string& text)
	{
		std::cout << "[WANRING] " << text << std::endl;
	}

	void Log::Error(const std::string& text)
	{
		std::cout << "[ERROR] " << text << std::endl;
	}
}