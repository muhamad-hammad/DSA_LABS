// 4. Search for any value in the tree if it is present print, it with its index
// (key) value otherwise inserts it into the tree and balances it with the
// appropriate rotations.

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

    void search(int data) {
        Node* foundNode = search(root, data);
        if (foundNode) {
            cout << "The value " << foundNode->data << " is present at node " << foundNode->name << endl;
        } else {
            cout << "The value " << data << " is not present in the tree." << endl;
            addNode(data, "new");
            cout << "The value " << data << " has been inserted into the tree." << endl;
            isBalanced();
        }
    }

private:
    
Node* search(Node* root, int data) {
        if (root == NULL) return NULL;
        if (data < root->data) return search(root->leftChild, data);
        else if (data > root->data) return search(root->rightChild, data);
        else return root;
    }

    int height(Node* node) {
        if (node == NULL) {
            return 0;
        }
        return max(height(node->leftChild), height(node->rightChild)) + 1;
    }

    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current->leftChild != NULL) {
            current = current->leftChild;
        }
        return current;
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
            return node;
        }

        int balanceFactor = getBalanceFactor(node);

        
        if (balanceFactor > 1 && data < node->leftChild->data) {
            return rightRotate(node);
        }

        if (balanceFactor < -1 && data > node->rightChild->data) {
            return leftRotate(node);
        }

        if (balanceFactor > 1 && data > node->leftChild->data) {
            node->leftChild = leftRotate(node->leftChild);
            return rightRotate(node);
        }

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
    tree.addNode(1, "Node 1");
    tree.addNode(2, "Node 2");
    tree.addNode(3, "Node 3");
    tree.addNode(4, "Node 4");
    tree.addNode(5, "Node 5");
    tree.addNode(6, "Node 6");
    tree.addNode(7, "Node 7");

    tree.search(8);
    tree.search(8);

    return 0;
}
