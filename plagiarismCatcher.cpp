#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

int getFiles(string dir, vector<string> &files);

int main(){ }


/**
   getFiles

   function that gets the file names from the directory and
   stores them in the vector supplied as argument 2.

 **/
int getFiles(string dir, vector<string> &files)
{
	DIR * openDir;
	struct dirent * readDir;

	if ((openDir = opendir(dir.c_str())) == NULL) {
		cout << "ERROR (" << errno << ") opening " << dir << endl;
		return (errno);
	}

	while ((readDir = readdir(dp)) != NULL) {
		files.push_back(string(readDir->d_name));
	}
	closedir(openDir);
	return (0);
}
