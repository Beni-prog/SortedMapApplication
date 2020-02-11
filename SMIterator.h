#pragma once
#include "SortedMap.h"
#include <vector>

class SMIterator
{
	friend class SortedMap;
private:
	//the iterator stores a reference to the container 
	const SortedMap& sm;
	//attributes: current;
	int current;
	std::vector<TElem> pairs;
	SMIterator(const SortedMap& sm);

	void iterate(BSTNode*n, std::vector<TElem>& pairs);

public:
	/*
	 returns the current element from the iterator
	 Pre:it ∈ I, it is valid;
     Post: GetCurrent ← p, p ∈ Pair, p is the current element from it( p it’s a pair of Type Pair);
     Throws: an exception if it is not valid;
	*/
	TElem getCurrent();

    /*
	 Descr: verifies whether the iterator is valid or not;
	 Pre : it ∈ I
	 Post : valid ← True, if it points to a valid element from the container or valid ← False otherwise;
	*/
	bool valid();

	/*
	 Descr: moves the current element from the container to the next element or makes the iterator invalid if no elements are left;
     Pre: it ∈ I, it is valid;
     Post: the current element from it points to the next element from the containers;
	 Throws: an exception if it is not valid;
	*/
	void next();
};

