#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>
#include <stdlib.h>

using namespace std;

class hashNode {
private:
	int index;
	hashNode * next;

public:

							// constructors
	hashNode();
	hashNode(int index);

	int getIndex();			// function that returns file index

	int setIndex();			// sets the file index

	hashNode * getNext();	// returns the next node

	hashNode * setNext();	// function that sets the next node

	~hashNode();			// destructor
};
