#pragma once
#include "Base/Log.h"

#include <fstream>
#include <string>

namespace KMG::Utils
{
	class FileReader
	{
	public:
		virtual ~FileReader() = default;

		static std::string ReadFile(const std::string& path);
	private:
		FileReader() = default;
	};
}
