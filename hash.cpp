#include "hash.h"
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

HashTable::HashTable()	// default constructor
{
	for (int i = 0; i < TABLE_SIZE; i++) {
		HashTable[i] = NULL;
	}
}

unsigned long long HashTable::hashFunc(string str, int tableSize)
{
	unsigned long long index = 0
	  for (int i = 0; i < str.size(); i++) {
		index += static_cast<int>(str[i]) % 7 * pow(2, (i % 63));
	}
	return index % tableSize;
}

int HashTable::hash(string str)
{
	unsigned long long index = hashFunc(str, TABLE_SIZE);
	HashNode * ptr = table[index];

	if (ptr != NULL) {
		HashNode * temp = new HashNode;
		temp->fileIndex = fileIndex;
		temp->next      = ptr;
		table[index]    = temp;
	} else {
		ptr = new HashNode;
		ptr->fileIndex = fileIndex;
		ptr->next      = NULL;
		table[index]   = ptr;
	}
}
