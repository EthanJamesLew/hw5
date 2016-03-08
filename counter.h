#pragma once
#ifndef COUNTER_H
#define COUNTER_H

#include "main.h"

//Provides a container word wordblock and an interface to access it 
class Counter
{
public:
	Counter();
	void printCount();

private:
	unsigned long int byteSize;
	unsigned long int wordSize;
	unsigned long int lineSize;
	std::vector<wordBlock> words;
};

#endif
