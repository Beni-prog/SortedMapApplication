#include "SMIterator.h"



SMIterator::SMIterator(const SortedMap & sm):sm(sm)
{
	this->iterate(sm.root, this->pairs);
	this->current = 0;
}

void SMIterator::iterate(BSTNode * n, std::vector<TElem>& pairs)
{
	//inorder traversal, recursive version
	if (n != NULL)
	{
		iterate(n->left, pairs);
		pairs.push_back(n->info);
		iterate(n->right, pairs);
	}
}

TElem SMIterator::getCurrent()
{
	return this->pairs[current];
}

bool SMIterator::valid()
{
	return this->current < this->pairs.size();
}

void SMIterator::next()
{
	this->current++; 
}
