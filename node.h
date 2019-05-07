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
	int fileIndex;
	hashNode * next;

	int getDir(string dir, vector<string> &files);

public:

	Directory();// default constructor

	Directory(string name);	// constructor

	string getDirName();

	vector<string> getFileNames();

	~Directory();	// destructor
};
