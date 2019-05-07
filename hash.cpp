#include "hash.h"
#include <stdlib.h>
#include <vector>

using namespace std;

const int SIZE = 1000000;


hashTable::hashTable() {
    table = new hashNode*[SIZE];
    for(int i =0; i<SIZE; i++){                                 //constructs table with contents = NULL
        table[i] = NULL;
    }
}


void hashTable::addNode(int hashVal, int index) {
    hashNode* cur = table[hashVal];
    while(cur != NULL){                                         //do nothing if index already in correct spot
        if(cur->getFileIndex == index){
            return;
        }
        cur = cur->getNext;
    }
    hashNode* insert = new hashNode(index);
    insert->setNext(table[hashVal]);                            //add node at specified hashVal
    table[hashVal] = insert;
}




hashNode* hashTable::getPointer(int hashVal) {
    return table[hashVal];                                      //return pointer to hashVal
}



void hashTable::addToHash(string fileName, int n, int index, hashTable &table) {
    vector <string> words;
    getWords(fileName, words);

    for(int i =0; i<(words.size()-n); i++){
            string strin;
            for (int j = 0; j<n; j++){
                strin += words[i+j];
            }
        table.addNode(hashFunc(strin), index);
    }
}


int hashTable::hashFunc(string key) {
    int i = 0;
    for (int j = 0; j<key.size(); j++){
        i = i*19 + key[j];
    }
    return abs(i % SIZE);
}


void hashTable::deleteList(int hashVal) {
    hashNode* cur = table[hashVal];
    while(cur != NULL){                                         //delete list till pointing to NULL
        hashNode *del = cur;
        cur = cur->getNext();
        delete (del);
    }
}

void hashTable::makeEmpty() {
    int i = 0;
    while(i<SIZE){
        deleteList(i);                                          //delete it all!
        i++;
    }
}

