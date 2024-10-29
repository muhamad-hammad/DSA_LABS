// Q4: Given a Tree of nodes (Down below):
        //         10
        //        / \
        //      5    11
        //     / \
        //    4   7
        //         \
        //          8   
// You are tasked to take a value X from the user and ask
// whether to ceil or floor the value. If ceil
// is selected find the closest value to X in our case 7 at 
// level three right child because if we ceil 6
// we get 7 (Yes, I am familiar with the logic of how ceil 
// and floor works with floating points but
// this scenario is different so in the case of ceil add 1 to
// X and in the case of floor subtract 1 from
// x then find the value). Also find multiple occurrences if
// it as well.

#include <iostream>
#include <string>
#include <cstring>
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
                    }
                    else{
                        current = current->rightChild;
                        if(current == NULL){
                            parent->rightChild = newNode;
                            return;
                        }
                        }
                        }
                }

        }
        
void ceil(Node* node, int key) {
    if (node == NULL) return;
    
    Node* current = node;
    Node* ceilNode = NULL;
    
    while (current != NULL) {
        if (current->key == key + 1) {
            ceilNode = current;
            break;
        }
        
        if (current->key > key) {
            ceilNode = current;
            current = current->leftChild; // Move left to find a closer ceil if exists
        } else {
            current = current->rightChild; // Move right if current node is less than or equal to key
        }
    }
    
    if (ceilNode != NULL) {
        cout << "Ceil: " << ceilNode->key << endl;
    } else {
        cout << "No ceil found." << endl;
    }
}

void floor(Node* node, int key) {
    if (node == NULL) return;
    
    Node* current = node;
    Node* floorNode = NULL;
    
    while (current != NULL) {
        if (current->key == key - 1) {
            floorNode = current;
            break;
        }
        
        if (current->key < key) {
            floorNode = current;
            current = current->rightChild; // Move right to find a closer floor if exists
        } else {
            current = current->leftChild; // Move left if current node is greater than or equal to key
        }
    }
    
    if (floorNode != NULL) {
        cout << "Floor: " << floorNode->key << endl;
    } else {
        cout << "No floor found." << endl;
    }
}

        void search(){
                cout << "Enter the value to search: ";
                int key;
                cin >> key;
                Node* current = root;   
                while(current->key != key){
                    if(key < current->key){
                        current = current->leftChild;
                    }
                    else if(key > current->key){
                        current = current->rightChild;
                    } else{
                        break;
                    }
                }
                string choice;
                while (choice != "ceil" && choice != "floor"){
                cout << "put correct choice that you want to find the ceil or floor of the value? (ceil/floor): ";
                cin >> choice;
                if(choice == "ceil"){
                    ceil(root, key);
                    break;
                }
                else if(choice == "floor"){
                    floor(root, key);
                    break;
                }
                }
        }


};

int main(){
        BinaryTree tree;
        tree.addNode(10,"A");
        tree.addNode(15,"B");
        tree.addNode(20,"C");
        tree.addNode(25,"D");
        tree.addNode(30,"E");
        tree.addNode(35,"F");
        tree.addNode(40,"G");
        tree.addNode(45,"H");
        tree.addNode(50,"I");
        tree.addNode(55,"J");
        
        tree.search();
}