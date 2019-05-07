#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Directory {
private:
	string dirName;
	vector<string> fileNames;

	int getDir(string dir, vector<string> &files);

public:

	Directory();// default constructor

	Directory(string name);	// constructor

	string getDirName();

	vector<string> getFileNames();

	~Directory();	// destructor
};
