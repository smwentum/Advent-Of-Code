#include "Day8Node.h"

using namespace std;

Day8Node::Day8Node(string name, string left, string right)
{
	this->name = name; 
	this->left = left; 
	this->right = right; 

}

Day8Node::Day8Node()
{
}

string Day8Node::getLeft()
{
	return left;
}

string Day8Node::getRight()
{
	return right;
}