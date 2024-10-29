//Q1: Given an array of {1,2,3,4,5} implement a binary tree according.
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
    private:
        Node* root;
    public:
        BinaryTree(){
            root = NULL;
        }
        void addNode(int key,string name){
            Node* newNode = new Node(key,name);
            if(root == NULL){
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

        void printTree(Node* node){
            if(node != NULL){
                printTree(node->leftChild);
                cout << node->toString(node->key) << endl;
                printTree(node->rightChild);
            }
        }
        void printTree(){
            printTree(root);
        }
};

int main(){
    BinaryTree tree;
    int n,x;
    cout << "Enter the number of nodes: " <<endl;
    cin >> n;
    for(int i = 0; i < n; i++){
        cout << "Enter the value of node " << i + 1 << ": ";
        x = i+1;
        tree.addNode(x, "Node " + to_string(i+1));
    }

    tree.printTree();
}