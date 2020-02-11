#pragma once

#include <utility>
#include <string>

class SMIterator;


typedef int TKey;

typedef std::string TValue;

typedef std::pair<TKey, TValue> TElem;


#define NULL_TVALUE " "


typedef bool(*Relation)(TKey, TKey);
struct BSTNode
{
	TElem info;
	BSTNode* right;
	BSTNode* left;
};

class SortedMap
{
	friend class SMIterator;
private:
	//representation of SortedMap
	BSTNode* root;
	Relation r;
public:
	BSTNode* getRoot() { return this->root; }
	SortedMap(Relation r) { this->r = r; this->root = NULL; }

	/* adds a pair (key,value) to the map
	if the key already exists in the map, then the value associated to the key is replaced by the new value and the old value is returned
	if the key does not exist, a new pair is added and the value null is returned*/
	TValue add(TKey c, TValue v);


	//searches for the key and returns the value associated with the key if the map contains the key or null: NULL_TVALUE otherwise
	TValue search(TKey c) const;

	//removes a key from the map and returns the value associated with the key if the key existed or null: NULL_TVALUE otherwise
	TValue remove(TKey c);


	//returns the number of pairs (key,value) from the map
	int sizeSM(BSTNode* currentN) const;

	/* return the iterator for the map
	 the iterator will return the keys following the order given by the relation*/
	SMIterator iterator() const;

	int density();

	// destructor
	~SortedMap();
};

