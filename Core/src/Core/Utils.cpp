#include "corepch.h"
#include "Utils.h"

namespace KMG::Utils
{
	std::string FileReader::ReadFile(const std::string& path)
	{
		std::string result;
		std::ifstream in(path, std::ios::in | std::ios::binary);
		
		KMG_CORE_VALIDATE(in, "UTILS::FILE: Failed to read file at path: " + path);
		
		if (in)
		{
			in.seekg(0, std::ios::end);
			result.resize((size_t)in.tellg());
			in.seekg(0, std::ios::beg);
			in.read(&result[0], result.size());
			in.close();
		}

		return result;
	}
}