#pragma once

#include <string>
#include <vector>

void parseArgs(int argc, char* argv[], bool& all, std::vector<std::string>& prgm);
void split(const std::string& str, char sep, std::vector<std::string>& dirs);