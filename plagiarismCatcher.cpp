#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

void getWords(string fileName, vector<string> &words);

int getDir(string dir, vector<string> &files);


int main(){ }

/**
   getWords

   Function that gets each word in the file named fileName,
   and stores them in the vector supplied as argument 2 ("words").

 **/
void getWords(string fileName, vector<string> &words)
{
	ifstream fileStream;

	fileStream.open(fileName.c_str());

	if (!fileStream.is_open()) {
		cout << "Cannot open file." << endl;
	}

	string word;
	while (fileStream >> word) {
		words.push_back(word);
	}
}

/**
   getDir

   function that gets the file names from the directory and
   stores them in the vector supplied as argument 2.

 **/
int getDir(string dir, vector<string> &files)
{
	DIR * openDir;
	struct dirent * readDir;

	if ((openDir = opendir(dir.c_str())) == NULL) {
		cout << "ERROR (" << errno << ") opening " << dir << endl;
		return (errno);
	}

	while ((readDir = readdir(openDir)) != NULL) {
		files.push_back(string(readDir->d_name));
	}
	closedir(openDir);
	return (0);
}
