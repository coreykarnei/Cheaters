#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "node.h"
#include "hash.h"

using namespace std;

int getDir(string dir, vector<string> &files);

const int TABLESIZE = 1000000;


int main(int argc, char * argv[])
{
	if (argc != 4) {
		cout << "Incorrect amount of arguments." << endl;
		return (-1);
	}
	string dir    = argv[1];
	int n         = atoi(argv[2]);
	int threshold = atoi(argv[3]);

	if (n < 1 || threshold < 1) {
		cout << "Incorrect arguments." << endl;
		return (-1);
	}

	vector<string> files = vector<string>();
	int test = getDir(dir, files);
	if (test != 0) {
		cout << "Couldn't find files." << endl;
		return (-1);
	}
	for (int i = 0; i < 10; i++) {
		string output = files[i];
		//cout << output << endl;
	}

	hashTable dataTable;

	for (int i = 0; i < files.size(); i++) {
		if (files[i] != "." && files[i] != "..") {
			string fullName = dir + "/" + files[i];
			dataTable.addToHash(fullName, n, i, dataTable);
		}
	}

	int ** collisionTable = new int *[files.size()];
	for (int i = 0; i < files.size(); i++) {
		collisionTable[i] = new int[files.size()];
	}

	for (int i = 0; i < files.size(); i++) {
		for (int j = 0; j < files.size(); j++) {
			collisionTable[i][j] = 0;
		}
	}

	for (int i = 0; i < TABLESIZE; i++) {
		hashNode * temp1;
		temp1 = dataTable.getPointer(i);

		while (temp1 != NULL) {
			hashNode * temp2;
			temp2 = temp1->getNext();
			while (temp2 != NULL) {
				collisionTable[temp1->getIndex()][temp2->getIndex()] += 1;
				temp2 = temp2->getNext();
			}
			temp1 = temp1->getNext();
		}
	}
	int max    = threshold;
	int maxRow = 0;
	int maxCol = 0;

	while (max >= threshold) {
		max = 0;
		for (int i = 0; i < files.size(); i++) {
			for (int j = 0; j < files.size(); j++) {
				int collisions = collisionTable[i][j];
				if (collisions > max) {
					maxRow = i;
					maxCol = j;
					max    = collisions;
				}
			}
		}
		if (max >= threshold) {
			cout << max << " collisions: \"" << files[maxRow] << "\", \"" << files[maxCol] << "\"" << endl;
			collisionTable[maxRow][maxCol] = 0;
		}
	}
	dataTable.makeEmpty();

	for (int i = 0; i < files.size(); i++) {
		delete(collisionTable[i]);
	}
	delete(collisionTable);

	return (0);
}	// main

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
