#include <stdlib.h>
#include "node.h"
#include <vector>

using namespace std;

class hashTable {
private:
    hashNode** table;

public:
    hashTable()                              //default constructor

    void addNode(int hashVal, int index);   //adds a node to the front of the list specified by hashVal

    hashNode* getPointer(int hashVal);      //returns pointer to a specific hash value

    void deleteList(int hashVal);           //removes LL for a specific hash index

    void makeEmpty();                       //removes LL for all indexes

};
