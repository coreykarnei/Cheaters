#include "hash.h"
#include <stdlib.h>

using namespace std;

const int SIZE = 1000000;


hashTable::hashTable() {
    table = new hashNode*[SIZE];
    for(int i =0; i<SIZE; i++){
        table[i] = NULL;
    }
}


void hashTable::addNode(int hashVal, int index) {
    hashNode* cur = table[hashVal];
    while(cur != NULL){
        if(cur->getFileIndex == index){
            return;
        }
        cur = cur->getNext;
    }
    hashNode* insert = new hashNode(index);
    insert->setNext(table[hashVal]);
    table[hashVal] = insert;
}




hashNode* hashTable::getPointer(int hashVal) {
    return table[hashVal];
}



void hashTable::deleteList(int hashVal) {
    hashNode* cur = table[hashVal];
    while(cur != NULL){
        hashNode *del = cur;
        cur = cur->getNext();
        delete (del);
    }
}

void hashTable::makeEmpty() {
    int i = 0;
    while(i<SIZE){
        deleteList(i);
        i++;
    }
}

