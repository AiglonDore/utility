#include "utils.h"

#include <iostream>

using namespace std;

void parseArgs(int argc, char* argv[], bool& all, std::vector<string>& prgm)
{
	for (size_t i = 1; i < argc; i++)
	{
#ifdef _WIN32
		if (argv[i][0] == '-' || argv[i][0] == '/')
#else
		if (argv[i][0] == '-')
#endif 
		{
#ifdef _WIN32
			if (!strcmp(argv[i], "-a") || !strcmp(argv[i], "/a"))
#else
			if (!strcmp(argv[i], "-a"))
#endif
			{
				all = true;
			}
			else
			{
				cerr << argv[0] << ": option not recognized. Ignoring it." << endl;
			}
		}
		else
			prgm.push_back(argv[i]);
	}
}

void split(const string& str, char sep, vector<string>& dirs)
{
	size_t start = 0;
	size_t end = str.find(sep);
	while (end != string::npos)
	{
		dirs.push_back(str.substr(start, end - start));
		start = end + 1;
		end = str.find(sep, start);
	}
	if (start < str.length())
		dirs.push_back(str.substr(start));
}