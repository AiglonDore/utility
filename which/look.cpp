#include "look.h"

#include <filesystem>
#include <iostream>

void lookForProgramsInDirs(const std::vector<std::string>& dirs, const std::vector<std::string>& prgm, bool all)
{
	for (const std::string& p : prgm)
	{
		std::cout << p;
		bool found(false);
		for (const std::string& dir : dirs)
		{
			std::filesystem::path path(dir);
			path /= p + ".exe";
#ifdef _WIN32
			if (std::filesystem::exists(path))
#else
			if (std::filesystem::exists(path) && std::filesystem::is_regular_file(path) && std::filesystem::is_executable(path))
#endif
			{
				if (!found) std::cout << std::endl;
				std::cout << "  -" << path << std::endl;
				found = true;
			}
			if (found && !all)
			{
				break;
			}
		}
		if (!found)
		{
			std::cout << " not found" << std::endl;
		}
	}
}