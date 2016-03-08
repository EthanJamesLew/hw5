#pragma once
#ifndef WORDBLOCK_H
#define WORDBLOCK_H
#include "main.h"
typedef struct  wordBlock
{
	//Stores the word
	std::string word;
	//Store the lines it occurs in
	std::vector<int> lines;
	wordBlock(std::string str, int num)
	{
		word = str;
		lines.push_back(num);
		return;
	}
	wordBlock()
	{

	}
};
#endif
