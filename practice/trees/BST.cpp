#include<iostream>
#include<string>
#include<cstring>
using namespace std;

class Node{

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
            return name + " has the key " + to_string(key) + " \n";
        }
};

class BinaryTree{
    private:
    Node* root;
    public: 
        BinaryTree(){
            root = NULL;
        }
        void addNode(int key, string name){
            Node* newNode = new Node(key,name);
            if(root == NULL ){
                root = newNode;
            }
            else{
                Node* current = root;
                Node *parent;
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

        void printTree(Node* node){
            if(node!=NULL){
                printTree(node->leftChild);
                cout << node << node->toString(node->key);
                printTree(node->rightChild);
            }
        }
        void printTree(){
            printTree(root);
        }
};

int main(){
    BinaryTree tree;
    tree.addNode(42, "Node 1");
    tree.addNode(28, "Node 2");
    tree.addNode(52, "Node 3");
    tree.addNode(02, "Node 4");
    tree.addNode(54, "Node 5");

    tree.printTree();




}