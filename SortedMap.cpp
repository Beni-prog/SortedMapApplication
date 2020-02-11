#include "SortedMap.h"
#include"SMIterator.h"

SortedMap::~SortedMap()
{

}

TValue SortedMap::add(TKey c, TValue v)
{
	BSTNode* n= new BSTNode();
	n->left = NULL;
	n->right = NULL;
	n->info = { c,v };
	BSTNode* currentN = this->root;

	int stop = 1;
	if (currentN == NULL)
	{
        this->root = n;
		stop = 0;
	}
		

	while (stop == 1)
	{
		if (currentN->info.first == c)
		{
			TValue oldvalue = currentN->info.second;
			currentN->info.second = v;
			return oldvalue;
		}
		if (this->r(c, currentN->info.first) == true)
		{
			if (currentN->left != NULL)
				currentN = currentN->left;
			else
			{
				currentN->left = n;
				stop = 0;
			}
        }
		else
		{
			if (currentN->right != NULL)
				currentN = currentN->right;
			else
			{
				currentN->right = n;
				stop = 0;
			}
		}
	}
	return NULL_TVALUE;


}

TValue SortedMap::search(TKey c) const
{
	bool found = false;
	BSTNode* currentN = this->root;
	if (currentN == NULL)
		return NULL_TVALUE;

	if (currentN->info.first == c)
	{
		found = true;
		return currentN->info.second;
	}

	while (found == false)
	{
		if (currentN->info.first == c)
		{
			found = true;
			return currentN->info.second;
		}
		if (this->r(c, currentN->info.first) == true)
		{
			if (currentN->left != NULL)
				currentN = currentN->left;
			else
				return NULL_TVALUE;
		}
		else
		{
			if (currentN->right != NULL)
				currentN = currentN->right;
			else
				return NULL_TVALUE;
		}
	}
	return NULL_TVALUE;
}

TValue SortedMap::remove(TKey c)
{
	TValue oldvalue = "Not found!";
	BSTNode* currentN = this->root;
	BSTNode* prev = NULL;

	
	while (oldvalue == "Not found!")
	{
		if (currentN->info.first == c)
		{
			oldvalue = currentN->info.second;
			if (currentN->left == NULL && currentN->right == NULL)
			{
				if (prev == NULL)
					this->root = NULL;//we removed the root
				else
				{
					if (prev->left == currentN)
						prev->left = NULL;//the node is a leaf, in the left side of the tree;
					else
						prev->right = NULL;//the node is a leaf, in the right side of the tree;
				}
			}
			else 
				if (currentN->left == NULL)
				{
					if (prev == NULL)
					{
						this->root = currentN->right;
					}
					else {
						if (prev->left == currentN)
						{
							prev->left = currentN->right;
						}
						else
							prev->right = currentN->right;
					}
				}
				else
					if (currentN->right==NULL)
					{
						if (prev == NULL)
						{
							this->root = currentN->left;
						}
						else
						{
							if (prev->right == currentN)
							{
								prev->right = currentN->left;
							}
							else
								prev->left = currentN->left;
						}
					}
					else
					{
						BSTNode* node = currentN->right;//second node
						BSTNode* parent = currentN;//first node
						while (node->left != NULL)//third node
						{
							parent = node;
							node = node->left;
						}
						currentN->info = node->info;//eliminate the second node
						if (parent == currentN)
							parent->right = node->right;
						else
                            parent->left = node->right;
					}
		}
		else
		   if (this->r(c, currentN->info.first) == true)
		   {
			   if (currentN->left != NULL)
			   {
				  prev = currentN;
				  currentN = currentN->left;
			   }
			   else
				  return oldvalue;
		   }
		   else
		   {
			   if (currentN->right != NULL)
			   {
				  prev = currentN;
				  currentN = currentN->right;
			   }
			   else
				return oldvalue;
		   }
	}
	return oldvalue;
}

int SortedMap::sizeSM(BSTNode* currentN) const
{
	//kind of inorder traversal recursive
	if (currentN != NULL)
		return 1 + sizeSM(currentN->left) + sizeSM(currentN->right);
	else
		return 0;
}

SMIterator SortedMap::iterator() const
{
	return SMIterator(*this);
}

int SortedMap::density()
{
	BSTNode* r1 = this->getRoot();
	while (r1 != NULL && r1->left!=NULL) 
		r1 = r1->left;
	int min = r1->info.first;
	BSTNode* r2 = this->getRoot();
	while (r2 != NULL && r2->right!=NULL)
		r2 = r2->right;
	int max = r2->info.first;
	return (max - min) / this->sizeSM(this->getRoot());

}
