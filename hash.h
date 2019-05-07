#ifndef HASH_H
#define HASH_H

#include <stdlib.h>
#include "node.h"
#include <vector>

using namespace std;

class hashTable {
private:
	hashNode ** table;

public:
	hashTable();							// default constructor

	void addNode(int hashVal, int index);	// adds a node to the front of the list specified by hashVal

	hashNode * getPointer(int hashVal);		// returns pointer to a specific hash value

	void getWords(string fileName, vector<string> &words);

	void addToHash(string fileName, int n, int index, hashTable &table);// goes thru file and hashes all n-word chunks

	int hashFunc(string key);		// map a key onto an index

	void deleteList(int hashVal);	// removes LL for a specific hash index

	void makeEmpty();				// removes LL for all indexes
};
#endif	// ifndef HASH_H
