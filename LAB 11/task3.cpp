// 1. Write a Program to implement Hash table and implement 
//the following task. Via linked lists and any
// Hash calculation method.
// Keys= (20,34,45,70,56)
// a. Insert element into the table
// b. Search element from the key
// c. Delete element at a key

#include<iostream>
using namespace std;

class HashTableEntry{
    public:
    int key;
    int value;
    HashTableEntry*  next;
    HashTableEntry(int key, int value){
        this->key = key;
        this->value = value;
        this->next = NULL;
    }
};

class HashMap{
    private:
    HashTableEntry** table;
    int size;
    static const int TABLE_SIZE = 10;
    int elements;

    public:
    HashMap(){
        this->size = TABLE_SIZE;
        this->elements = 0;
        table = new HashTableEntry*[TABLE_SIZE]();
    }

    int Hash(int k){
        return k % size; 
    }

    double LoadFactor() const {
        return 1.0 * elements / size;
    }

    void ResizeTable(int newSize){
        HashTableEntry** newTable = new HashTableEntry*[newSize]();

        for(int i=0; i<size; ++i){
            HashTableEntry* current = table[i];
            while(current != NULL){
                int newHash = current->key % newSize;
                HashTableEntry* next = current->next;
                current->next = newTable[newHash];
                newTable[newHash] = current;
                current = next;
            }
        }
        delete[] table;
        table = newTable;
        size = newSize;
    }

    void Insert(int k, int v = 0){
        int hash = Hash(k);
        HashTableEntry* newEntry = new HashTableEntry(k,v);

        if(table[hash] == NULL){
            table[hash] = newEntry;
        } else {
            HashTableEntry* current = table[hash];
            while (current->next != NULL){
                current = current->next;
            }
            current->next = newEntry;
        }
        elements++;

        if(LoadFactor() > 0.7){
            int newSize = size*2;
            ResizeTable(newSize);
        }
    }

    int SearchKey(int k){
        int hash = Hash(k);
        HashTableEntry* current = table[hash];
        while (current != NULL){
            if(current->key == k){
                return current->value;
            }
            current = current->next;
        }
        return -1;
    }

    void Remove(int k){
        int hash = Hash(k);
        HashTableEntry* current = table[hash];
        HashTableEntry* prev = NULL;
        while (current != NULL && current->key != k){
            prev = current;
            current = current->next;
        }

        if(current != NULL){
            if(prev != NULL){
                prev->next = current->next;
            } else {
                table[hash] = current->next;
            }
            delete current;
            elements--;
        }
    }

    void PrintTable(){
        for(int i=0; i<size; ++i){
            cout << "Index " << i << ": ";
            HashTableEntry* current = table[i];
            while(current != NULL){
                cout << "Key-" << current->key << ", value = " << current->value << " ->";
                current = current->next;
            }
            cout << "Null" << endl;
        }
    }

    ~HashMap(){
        for(int i=0; i<size; ++i){
            HashTableEntry* current = table[i];
            while (current != NULL){
                HashTableEntry* next = current->next;
                delete current;
                current = next;
            }
            table[i] = nullptr;
        }
        delete[] table;
    }
};

int main(){
    HashMap hashTable;
    //Keys= (20,34,45,70,56)
    hashTable.Insert(20);
    hashTable.Insert(34);
    hashTable.Insert(45);
    hashTable.Insert(70);
    hashTable.Insert(56);


    cout << "Table after insersion: " << endl;
    hashTable.PrintTable();

    int value = hashTable.SearchKey(20);
    if(value != -1){
        cout << "Value for searched key is: "<< value << endl;
        cout << "Key not found when serched" << endl;
    }
}