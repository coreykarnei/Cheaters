#include "dir.h"

using namespace std;


int Directory::getDir(string dir, vector<string> &files)
{
	DIR * dirPtr;
	struct dirent * dirStr;

	if ((dirPtr = opendir(dir.c_str())) == NULL) {
		cout << "Error Number " << errno << " when opening " << dir << endl;
		return errno;
	}

	while ((dirStr = readdir(dirPtr)) != NULL) {
		files.push_back(string(dirStr->d_name));
	}
	closedir(dirPtr);
	return (0);
}

Directory::Directory()	// defualt constructor
{
	dirName   = "New Dir";
	fileNames = vector<string>();
}

Directory::Directory(string name)
{
	dirName   = name;
	fileNames = vector<string>();
	getDir(dirName, fileNames);
}

string Directory::getDirName()
{
	return dirName;
}

vector<string> Directory::getFileNames()
{
	return fileNames;
}

Directory::~Directory()	// destructor
{ }
