// Q3: Search for the value defined by the user in the tree.
// If the value does not exist insert it then
// identify its location based on the level of the tree 
// and if it’s the root at level, left child or right
// child.

#include <iostream>
#include <string>
#include <cstring>
using namespace std;    

class  Node{
    public:
        int key;
        string name;
        Node* leftChild;
        Node* rightChild;
        Node(int key, string name){
            this->key = key;
            this->name = name;
            this->leftChild = NULL;
            this->rightChild = NULL;
        }
        string toString(int key){
            return "Key: " + to_string(key) + "\n";
        }
};

class BinaryTree{
    Node* root;
    public:
    BinaryTree(){
            root = NULL;
        }
        void addNode(int key,string name){
            Node* newNode = new Node(key,name);
            if (root == NULL){
                root = newNode;
            }
            else{
                Node* current = root;
                Node* parent;
                while(true){
                    parent = current;
                    if(key < current->key){
                        current = current->leftChild;
                        if(current == NULL){
                            parent->leftChild = newNode;
                            return;
                        }
                    } else {
                        current = current->rightChild;
                        if(current == NULL){
                            parent->rightChild = newNode;
                            return;
                        }
                    }
                }
            }
        }
        void search(int key){
            Node* current = root;
            while(current->key != key){
                if(key < current->key){
                    current = current->leftChild;
                } else {
                    current = current->rightChild;
                }
                if(current == NULL){
                    cout << "Value not found" << endl;
                    addNode(key, "Default name");
                    return;
                }
            }
            cout << "Value found" << endl;
        }            
};
int main(){

    BinaryTree tree;
    tree.addNode(50, "Ahmad");
    tree.addNode(25, "Fatima");
    tree.addNode(75, "Omar");
    tree.addNode(10, "Hassan");
    tree.addNode(30, "Ibrahim");
    tree.addNode(60, "Zainab");

    // searching for a value that already exists
    tree.search(50);
    // searching for a value that does not exist
    tree.search(20);
    // searching for a value that does not existed firstt
    tree.search(20);
    return 0;
    
}