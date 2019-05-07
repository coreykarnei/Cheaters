#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class HashTable {
private:
	struct HashNode {
		int        fileIndex;
		HashNode * next;
	};

	static const int TABLE_SIZE = 1500000;	// arbitrary table size
	HashNode ** table;
	int ** collisions;

	int numFiles;

	unsigned long hashFunc(string str, int tableSize);

public:
	HashTable(vector<string> files);
	void hash(string str);
	void getCollisions(int num, vector<string> files);

	~HashTable();
};
