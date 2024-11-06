#include <iostream>
#include <string>
using namespace std;

int max(int a, int b) {
    return (a > b) ? a : b;
}

class Node {
public:
    int data;
    string name;
    Node* leftChild;
    Node* rightChild;

    Node(int data, string name) {
        this->data = data;
        this->name = name;
        this->leftChild = NULL;
        this->rightChild = NULL;
    }
};

class AVL {
    Node* root;

public:
    AVL() {
        root = NULL;
    }

    void addNode(int data, string name) {
        root = addNode(root, data, name);
    }

    void isBalanced() {
        if (isBalanced(root)) {
            cout << "The AVL tree is balanced." << endl;
        } else {
            cout << "The AVL tree is not balanced." << endl;
        }
    }

private:
    int height(Node* node) {
        if (node == NULL) {
            return 0;
        }
        return max(height(node->leftChild), height(node->rightChild)) + 1;
    }

    int getBalanceFactor(Node* node) {
        if (node == NULL) {
            return 0;
        }
        return height(node->leftChild) - height(node->rightChild);
    }

    Node* rightRotate(Node* y) {
        Node* x = y->leftChild;
        Node* t2 = x->rightChild;

        x->rightChild = y;
        y->leftChild = t2;

        return x;
    }

    Node* leftRotate(Node* y) {
        Node* x = y->rightChild;
        Node* t2 = x->leftChild;

        x->leftChild = y;
        y->rightChild = t2;

        return x;
    }

    Node* addNode(Node* node, int data, string name) {
        if (node == NULL) {
            return new Node(data, name);
        }

        if (data < node->data) {
            node->leftChild = addNode(node->leftChild, data, name);
        } else if (data > node->data) {
            node->rightChild = addNode(node->rightChild, data, name);
        } else {
            return node; // Duplicate data not allowed in AVL tree
        }

        int balanceFactor = getBalanceFactor(node);

        // Left Left Case (Right Rotation)
        if (balanceFactor > 1 && data < node->leftChild->data) {
            return rightRotate(node);
        }

        // Right Right Case (Left Rotation)
        if (balanceFactor < -1 && data > node->rightChild->data) {
            return leftRotate(node);
        }

        // Left Right Case (Left Rotate on left child, then Right Rotate)
        if (balanceFactor > 1 && data > node->leftChild->data) {
            node->leftChild = leftRotate(node->leftChild);
            return rightRotate(node);
        }

        // Right Left Case (Right Rotate on right child, then Left Rotate)
        if (balanceFactor < -1 && data < node->rightChild->data) {
            node->rightChild = rightRotate(node->rightChild);
            return leftRotate(node);
        }

        return node;
    }

    bool isBalanced(Node* node) {
        if (node == NULL) {
            return true;
        }

        int balanceFactor = getBalanceFactor(node);

        return abs(balanceFactor) <= 1 && isBalanced(node->leftChild) && isBalanced(node->rightChild);
    }
};

int main() {
    AVL tree;
    tree.addNode(10, "Node 1");
    tree.addNode(20, "Node 2");
    tree.addNode(30, "Node 3");
    tree.addNode(25, "Node 4");
    tree.addNode(28, "Node 5");

    tree.isBalanced();
    return 0;
}
