#include "node.h"
#include <stdlib.h>

hashNode::hashNode()
{
	next  = NULL;
	index = 0;
}

hashNode::hashNode(int idx)
{
	next  = NULL;
	index = idx;
}

int hashNode::getIndex()
{
	return index;
}

hashNode * hashNode::getNext()
{
	return next;
}

void hashNode:: setNext(hashNode * nextToSet)
{
	next = nextToSet;
}

void hashNode::setIndex(int idx)
{
	index = idx;
}
