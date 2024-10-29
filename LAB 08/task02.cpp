// Q2: Using the same tree that you made insert the 
// values 6,7,8 accordingly. Now check if the tree
// made is a complete binary tree or if it’s a full 
// binary tree if not delete the nodes accordingly, to
// make it a complete and full binary tree. (I know 
// the tree will be complete but implement a logic
// to check if it is complete).
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

        int countNodes(Node* node) {
            if (node == NULL) {
                return 0;
            }
            return 1 + countNodes(node->leftChild) + countNodes(node->rightChild);
        }

        bool checkComplete(Node* node, int index, int totalNodes) {
            if (node == NULL) {
                return true;
            }
            if (index >= totalNodes) {
                return false;
            }
            return checkComplete(node->leftChild, 2 * index + 1, totalNodes) &&
                   checkComplete(node->rightChild, 2 * index + 2, totalNodes);
        }
        bool checkFull(Node* node) {
            if (node == NULL) {
                return true;
            }
            if (node->leftChild == NULL && node->rightChild == NULL) {
                return true;
            }
            if (node->leftChild != NULL && node->rightChild != NULL) {
                return checkFull(node->leftChild) && checkFull(node->rightChild);
            }
            return false;
        }
        void deleteNode(int key) {
            root = deleteNode(root, key);
        }
        Node* deleteNode(Node* node, int key) {
            if (node == NULL) {
                return NULL;
            }
            if (key < node->key) {
                node->leftChild = deleteNode(node->leftChild, key);
            } else if (key > node->key) {
                node->rightChild = deleteNode(node->rightChild, key);
            } else {
                if (node->leftChild == NULL) {
                    Node* temp = node->rightChild;
                    delete node;
                    return temp;
                } else if (node->rightChild == NULL) {
                    Node* temp = node->leftChild;
                    delete node;
                    return temp;
                }
                Node* temp = findMin(node->rightChild);
                node->key = temp->key;
                node->rightChild = deleteNode(node->rightChild, temp->key);
            }
            return node;
        }
        Node* findMin(Node* node){
            while(node->leftChild != NULL){
                node = node->leftChild;
            }
            return node;
        }   
        bool checkComplete(){
            int totalNodes = 0;
            countNodes(root);
            return checkComplete(root, 0, totalNodes);
        }
        bool checkFull(){
            return checkFull(root);
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
        void deleteIfNotCompleteOrFull() {
        if (!checkComplete() || !checkFull()) {
            Node* current = root;
            while (current != NULL) {
                if (current->leftChild != NULL && current->rightChild != NULL) {
                    current = current->leftChild;
                } else if (current->leftChild != NULL) {
                    current = current->leftChild;
                } else if (current->rightChild != NULL) {
                    current = current->rightChild;
                } else {
                    Node* parent = findParent(root, current);
                    if (parent->leftChild == current) {
                        parent->leftChild = NULL;
                    } else {
                        parent->rightChild = NULL;
                    }
                    delete current;
                    current = parent;
                }
            }
        }
    }
    Node* findParent(Node* node, Node* target) {
        if (node == NULL || node == target) {
            return NULL;
        }
        if (node->leftChild == target || node->rightChild == target) {
            return node;
        }
        Node* leftResult = findParent(node->leftChild, target);
        if (leftResult != NULL) {
            return leftResult;
        }
        return findParent(node->rightChild, target);
    }

        
};

int main(){
    BinaryTree tree;
    int x, n=8;
    for(int i = 0; i < n; i++){
        x = i+1;
        tree.addNode(x, "Node " + to_string(i+1));
    }

    tree.printTree();
    
     cout << "\nChecking for Complete and Full Conditions:" << endl;
     if (!tree.checkComplete()) {
         cout << "Tree is not complete. Deleting nodes to enforce completeness and fullness." << endl;
         tree.deleteIfNotCompleteOrFull();
    tree.printTree();
    return 0;
     } else if (!tree.checkFull()) {
         cout << "Tree is complete but not full. Deleting nodes to make it full." << endl;
         tree.deleteIfNotCompleteOrFull();
    tree.printTree();
    return 0;
     } else {
         cout << "Tree is both complete and full." << endl;
         return 0;
     }

}