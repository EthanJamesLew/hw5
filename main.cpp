#include "wordblock.h"
#include "counter.h"
#include <cassert>
#include <vector>
using namespace std;

int main()
{
	wordBlock *b = new wordBlock();
	std::vector<int> a = {};
	assert(b->word == "");
	assert(b->lines == a);

	wordBlock *c = new wordBlock();
	vector<int> g = { 4, 9 };
	c->word = "test";
	c->lines.push_back(4);
	c->lines.push_back(9);
	assert(c->word == "test");
	assert(c->lines == g);

	Counter h = Counter();
	h.printCount();
}
