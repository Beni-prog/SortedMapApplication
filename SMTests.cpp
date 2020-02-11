#include <assert.h>

#include "SMTests.h"
#include "SortedMap.h"
#include "SMIterator.h"

#include <exception>

using namespace std;

bool tryThis(TKey k1, TKey k2) {
	if (k1 <= k2) 
	{
		return true;
	}
	else 
	{
		return false;
	}
}

void testSM() 
{
	//constructor test
	SortedMap sm(tryThis);
	assert(sm.sizeSM(sm.getRoot()) == 0);

	//add function tests
	sm.add(123, "Pop Ioan");
	assert(sm.sizeSM(sm.getRoot()) == 1);
	assert(sm.add(123, "Acalinei Beniamin") == "Pop Ioan");
	TValue v = sm.add(123, "Chuck Norris");
	assert(v == "Acalinei Beniamin");
	assert(sm.sizeSM(sm.getRoot()) == 1);

	//search function tests
	assert(sm.search(123) != NULL_TVALUE);
	assert(sm.search(123) == "Chuck Norris");
	assert(sm.search(122) == " ");


	//iterator functions tests
	SMIterator it = sm.iterator();
	while (it.valid()) {
		TElem e = it.getCurrent();
		assert(e.second != NULL_TVALUE);
		it.next();
	}
	//remove function tests
	assert(sm.remove(123) == "Chuck Norris");
	assert(sm.sizeSM(sm.getRoot()) == 0);
}
