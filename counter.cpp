#include "counter.h"

Counter::Counter()
{
	std::string buffer;
	unsigned lineNumber = 1;
	bool inLine = false;

	while (getline(std::cin, buffer))
	{
		for (unsigned i = 0; i < words.size(); i++)
		{
			if (words[i].word == buffer)
			{
				words[i].lines.push_back(lineNumber);
				inLine = true;
			}
		}
		if (inLine == false)
		{
			words.push_back(wordBlock(buffer, lineNumber));
		}
		lineNumber++;
		inLine = false;
	}
}

void Counter::printCount()
{
	for (unsigned i = 0; i < words.size(); i++)
	{
		std::cout << words[i].word << " " << words[i].lines.size();
	}
	return;
}
