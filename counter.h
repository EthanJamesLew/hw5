#pragma once
#ifndef COUNTER_H
#define COUNTER_H

#include "main.h"

//Provides a container word wordblock and an interface to access it 
class Counter
{
public:
	//Construct with a filepath
	Counter(std::string fileName, std::ios_base::open_mode);

	//Construct with a string
	Counter(std::string words);

	//Construct with cin
	Counter();

	void printWords();

	std::string getMostUsedWord();

	wordBlock getWordBlock(std::string word);

private:
	unsigned long int byteSize;
	unsigned long int wordSize;
	unsigned long int lineSize;
	std::vector<wordBlock> words;
};

#endif