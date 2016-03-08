#pragma once
#include "main.h"

namespace utils
{
	bool fileExists(const std::string& name);

	bool inString(std::string substr, std::string str);

	std::string indexWordinStr(std::string str, unsigned index);

}