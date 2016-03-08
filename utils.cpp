#include "utils.h"


namespace utils
{

	bool fileExists(const std::string& name) {
		std::ifstream f(name.c_str());
		if (f.good()) {
			f.close();
			return true;
		}
		else {
			f.close();
			return false;
		}
	}

	bool inString(std::string substr, std::string str)
	{
		if (str.find(substr) != std::string::npos)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	std::string indexWordinStr(std::string str, unsigned index)
	{
		std::istringstream iss(str);
		std::string word;
		for (unsigned i = 0; i <= index; i++)
		{
			iss >> word;
		}
		iss.clear();
		iss.ignore(100000, '\n');
		return word;
	}
}
