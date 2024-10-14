#include<iostream>
using namespace std;

class Node{
    public:

    int data;
    Node* left;
    Node* right;

    Node(int d) : data(d) , left(NULL) , right(NULL){}
};

class binaryTree
{
public:
    Node* root;
    binaryTree() : root(NULL){}
    Node* insert(Node* root, int data) {
        if (root == NULL) {
            return new Node(data);
        }
        if (data < root->data) {
            root->left = insert(root->left, data);
        } else if (data > root->data) {
            root->right = insert(root->right, data);
        }
        return root;
    }

    void preOrder(Node* root) {
        if (root == NULL) {
            return;
        }
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }

    void inOrder(Node* root) {
        if (root == NULL) {
            return;
        }
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
    void postOrder(Node* root) {
        if (root == NULL) {
            return;
        }
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }



    void display(Node* root) {
        if (root == NULL) {
            return;
        }
        display(root->left);
        cout << root->data << " ";
        display(root->right);
    }
};

int main(){
    binaryTree tree;
    tree.root = tree.insert(tree.root, 1);
    tree.root = tree.insert(tree.root, 3);
    tree.root = tree.insert(tree.root, 2);
    tree.root = tree.insert(tree.root, 4);
    tree.root = tree.insert(tree.root, 7);
    tree.root = tree.insert(tree.root, 6);
    tree.root = tree.insert(tree.root, 8);
    tree.display(tree.root);
    cout << endl;
    tree.preOrder(tree.root);
    cout << endl;
    tree.inOrder(tree.root);
    cout << endl;
    tree.postOrder(tree.root);
    cout << endl;

    return 0;
}