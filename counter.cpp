#include "counter.h"

//Construct with a filepath
Counter::Counter(std::string fileName, std::ios_base::open_mode open)
{
	std::ifstream inFile;
	std::string buffer = std::string("");
	std::string word = std::string("");
	bool inArray = false;
	int index = 0;

	//Check if file exists and can be opened
	if (!(utils::fileExists(fileName) && open == std::ios_base::in))
	{
		throw;
		return;
	}

	//Get size of file in bytes
	std::ifstream in(fileName, std::ifstream::ate | std::ifstream::binary);
	byteSize = in.tellg();
	in.close();

	inFile.open(fileName);

	while (inFile.peek() != EOF)
	{
		getline(inFile, buffer);

		//Count line
		lineSize += 1;

		//Decompose line into words and add the to the wordBlock array
		std::istringstream iss(buffer);
		while (iss.peek() != EOF)
		{
			iss >> word;
			for (unsigned i = 0; i < words.size(); i++)
			{
				if (words[i].word == word)
				{
					words[i].lines.push_back(lineSize);
					inArray = true;
				}
			}
			if (inArray == false)
			{
				words.push_back(wordBlock(word));
			}
			inArray = false;
			index++;
		}
		iss.clear();
		iss.ignore(100000, '\n');
		word = "";
	}

}

//Construct with a string
Counter::Counter(std::string words)
{

}

//Construct with cin
Counter::Counter()
{
	std::string buffer = std::string("");
	std::string word = std::string("");
	bool inArray = false;
	int index = 0;

	while (std::cin.peek() != EOF)
	{
		//getline(std::cin, buffer);

		//Count line
		std::cin >> buffer;

		//Decompose line into words and add the to the wordBlock array
		std::istringstream iss(buffer);
		while (iss.peek() != EOF)
		{
			iss >> word;
			for (unsigned i = 0; i < words.size(); i++)
			{
				if (words[i].word == word)
				{
					words[i].lines.push_back(lineSize);
					inArray = true;
				}
			}
			if (inArray == false)
			{
				words.push_back(wordBlock(word));
			}
			inArray = false;
			index++;
		}
		iss.clear();
		iss.ignore(100000, '\n');
		word = "";
	}
}

std::string Counter::getMostUsedWord()
{
	return words[1].word;
}

wordBlock Counter::getWordBlock(std::string word)
{
	return wordBlock();
}

void Counter::printWords()
{
	for (unsigned i = 0; i < words.size(); i++)
	{
		if (words[i].word != "")
		{
			std::cout << words[i].word /*<< " | Occurences: "*/;
			std::cout <<" | " << words[i].lines.size() + 1;
			/*for (unsigned j = 0; j < words[i].lines.size(); j++)
			{
			std::cout << words[i].lines[j] << ", ";
			}*/
			std::cout << std::endl;
		}
	}
}