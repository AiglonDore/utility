#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <vector>

#include "utils.h"
#include "look.h"

using namespace std;

int main(int argc, char *argv[])
{
	bool all(false);
	vector<string> prgm;
	parseArgs(argc, argv, all, prgm);
	if (argc < 2) {
		cerr << "Usage: " << argv[0] << " [-a] program1 [program2 ...]" << endl;
		string line;
		do
		{
			cout << "Program to look for (empty to exit): ";
			getline(cin, line);
			if (line.empty()) break;
			else
			{
				vector<string> splitedInput;
				split(line, ' ', splitedInput);
				for (auto& s : splitedInput)
				{
					prgm.push_back(s);
				}
				
			}
		} while (true);
	}

#ifdef _WIN32
	char sep = ';';
	char* buf;
	_dupenv_s(&buf, NULL, "PATH");
	string path;
	if (buf != NULL)
	{
		path = buf;
	}
	else
	{
		std::cerr << "Environment variable not found. Aborting." << std::endl;
		return 1;
	}
	free(buf);
#else 
	char sep = ':';
	string path = getenv("PATH");
#endif
	vector<string> dirs;
	split(path, sep, dirs);

	lookForProgramsInDirs(dirs, prgm, all);
	
	return 0;
}