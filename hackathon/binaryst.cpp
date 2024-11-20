#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    string name;
    Node* left;
    Node* right;

    Node(int data, string name){
        this->data = data;
        this->name = name;
        this->left = NULL;
        this->right = NULL;
    }
};


class BST{
    private:
    Node* root;
    Node* addnode(Node* root, int data, string name){
        if(root == NULL){
            return new Node(data, name);
        } else if(data < root->data){
            root->left = addnode(root->left, data, name);
        } else {
            root->right = addnode(root->right, data, name);
        }
        return root;
    }
    Node* deleteNode(Node* root, int data){
        if(root == NULL){
            return NULL;
        } else if(data < root->data){
            root->left = deleteNode(root->left, data);
        } else if(data > root->data){
            root->right = deleteNode(root->right, data);
        } else {
            if(root->left == NULL){
                Node* temp = root->right;
                delete root;
                return temp;
            } else if(root->right == NULL){
                Node* temp = root->left;
                delete root;
                return temp;
            }
            Node* temp = inOrderSucc(root->right);
            root->data = temp->data;
            root->name = temp->name;
            root->right = deleteNode(root->right, temp->data);
        }
        return root;
    }
    Node* inOrderSucc(Node* root){
        return findMin(root);
    }

    Node* findMin(Node* root){
        if(root == NULL){
            return NULL;
        }
        while(root->left != NULL){
            root = root->left;
        }
        return root;
    }

    Node* findMax(Node* root){
        if(root == NULL){
            return NULL;
        }
        while(root->right != NULL){
            root = root->right;
        }
        return root;
    
    }

    Node* find(Node* root, int data){
        if(root == NULL){
            return NULL;
        } else if(data < root->data){
            return find(root->left, data);
        } else if(data > root->data){
            return find(root->right, data);
        } else {
            return root;
        }
    }

    Node* ceil(Node* root, int data){
        if(root == NULL){
            return NULL;
        }
        if(root->data == data){
            return root;
        }
        if(root->data < data){
            return ceil(root->right, data);
        }
        Node* temp = ceil(root->left, data);
        return(temp != NULL) ? temp : root;
    }

    Node* floor(Node* root, int data){
        if(root == NULL){
            return NULL;
        }
        if(root->data == data){
            return root;
        }
        if(root->data > data){
            return floor(root->left, data);
        }
        Node* temp = floor(root->right, data);
        return(temp != NULL) ? temp : root;
    }

    public:
    BST(){
        root = NULL;
    }

    void inOrder(){
        inOrder(root);
    }
    void inOrder(Node* root){
        if(root == NULL){
            return;
        }
        inOrder(root->left);
        cout << root->data << " at " << root->name << endl;
        inOrder(root->right);
    }
    void ceil(int data){
        Node* ceilNode = ceil(root, data);
        if(ceilNode){
            cout << "The ceil of " << data << " is: " << ceilNode->data << " at node " << ceilNode->name << endl;
        }
    }
    void floor(int data){
        Node* floorNode = floor(root, data);
        if(floorNode){
            cout << "The floor of " << data << " is: " << floorNode->data << " at node " << floorNode->name << endl;
        }
    }

    void addNode(int data, string name){
        root = addnode(root, data, name);
    }
    void deleteNode(int data){
        root = deleteNode(root, data);
    }
    void findMax(){
        Node* maxNode = findMax(root);
        if(maxNode){
            cout << "The maximum number is: " << maxNode->data << " at node " << maxNode->name << endl;
        }
    }
    void findMin(){
        Node* minNode = findMin(root);
        if(minNode){
            cout << "The minimum number is: " << minNode->data << " at node " << minNode->name << endl;
        }
    }

};