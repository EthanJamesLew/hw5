#include "counter.h"

#include <string>
#include <iostream>
#include <istream>
#include <ostream>
#include <iterator>

Counter::Counter()
{
	std::string line;
	std::string word = "";
	unsigned lineNumber = 1;
	bool inLine = false;
	unsigned long int size = 0;
	unsigned wordNum = 0;

	while (std::getline(std::cin, line))
	{
		//+1 because of the endline character
		size = size +  line.size() + 1;
		//Decompose line into words and add the to the wordBlock array
		std::istringstream iss(line);
		while (iss.peek() != EOF)
		{
			iss >> word;
			wordNum += 1;
			for (unsigned i = 0; i < words.size(); i++)
			{
				if (words[i].word == word)
				{
					words[i].lines.push_back(lineNumber);
					inLine = true;
				}
			}
			if (inLine == false)
			{
				words.push_back(wordBlock(word, lineNumber));
			}
			inLine = false;
		}
		iss.clear();
		iss.ignore(100000, '\n');
		word = "";
		lineNumber++;
	}
	byteSize = size;
	wordSize = wordNum;
	lineSize = lineNumber - 1;
}

void Counter::printCount()
{
	std::cout << "Input contains " << wordSize << " words, " << lineSize << " lines, and " << byteSize << " bytes."<<std::endl;
	std::cout << "Word Index: " << std::endl;
	for (unsigned i = 0; i < words.size(); i++)
	{
		std::cout << words[i].word << " ";
		for (unsigned j = 0; j < words[i].lines.size(); j++)
		{
			std::cout << words[i].lines[j];
			if (j != words[i].lines.size() - 1)
			{
				std::cout << ", ";
			}
		}
		std::cout << std::endl;
	}
	/*std::cout << "Size: " << byteSize << std::endl;
	std::cout << "Words: " << wordSize << std::endl;
	std::cout << "Line: " << lineSize << std::endl;*/
	return;
}
