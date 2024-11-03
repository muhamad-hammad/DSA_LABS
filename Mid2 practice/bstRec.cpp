#include <iostream>
using namespace std;

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

class BST {
    Node* root;

public:
    BST() {
        root = NULL;
    }

    void addNode(int data, string name) {
        root = addNode(root, data, name);
    }

    void inOrder() {
        inOrder(root);
    }

    void findMin() {
        Node* minNode = findMin(root);
        if (minNode) {
            cout << "The minimum number is: " << minNode->data << " at node " << minNode->name << endl;
        }
    }

    void findMax() {
        Node* maxNode = findMax(root);
        if (maxNode) {
            cout << "The maximum number is: " << maxNode->data << " at node " << maxNode->name << endl;
        }
    }

    void find(int data) {
        Node* foundNode = find(root, data);
        if (foundNode) {
            cout << "The number is: " << foundNode->data << " at node " << foundNode->name << endl;
        } else {
            cout << "The number " << data << " is not in the BST." << endl;
        }
    }

    void floor(int data) {
        Node* floorNode = floor(root, data);
        if (floorNode) {
            cout << "The floor of the number " << data << " is: " << floorNode->data << " at node " << floorNode->name << endl;
        } else {
            cout << "No floor found for " << data << " in the BST." << endl;
        }
    }

    void ceil(int data) {
        Node* ceilNode = ceil(root, data);
        if (ceilNode) {
            cout << "The ceil of the number " << data << " is: " << ceilNode->data << " at node " << ceilNode->name << endl;
        } else {
            cout << "No ceil found for " << data << " in the BST." << endl;
        }
    }

    // Public delete function
    void deleteNode(int data) {
        root = deleteBST(root, data);
    }

private:
    Node* inOrderSucc(Node* root) {
        return findMin(root);
    }

    Node* deleteBST(Node* root, int data) {
        if (root == NULL) return NULL;

        if (data < root->data) {
            root->leftChild = deleteBST(root->leftChild, data);
        } else if (data > root->data) {
            root->rightChild = deleteBST(root->rightChild, data);
        } else {
            if (root->leftChild == NULL) {
                Node* temp = root->rightChild;
                delete root;
                return temp;
            } else if (root->rightChild == NULL) {
                Node* temp = root->leftChild;
                delete root;
                return temp;
            }
            Node* temp = inOrderSucc(root->rightChild);
            root->data = temp->data;
            root->name = temp->name;
            root->rightChild = deleteBST(root->rightChild, temp->data);
        }
        return root;
    }

    Node* addNode(Node* root, int data, string name) {
        if (root == NULL) {
            return new Node(data, name);
        }
        if (data < root->data) {
            root->leftChild = addNode(root->leftChild, data, name);
        } else if (data > root->data) {
            root->rightChild = addNode(root->rightChild, data, name);
        }
        return root;
    }

    void inOrder(Node* root) {
        if (root == NULL) return;
        inOrder(root->leftChild);
        cout << root->data << " at " << root->name << endl;
        inOrder(root->rightChild);
    }

    Node* findMin(Node* root) {
        if (root == NULL) return NULL;
        while (root->leftChild != NULL) root = root->leftChild;
        return root;
    }

    Node* findMax(Node* root) {
        if (root == NULL) return NULL;
        while (root->rightChild != NULL) root = root->rightChild;
        return root;
    }

    Node* find(Node* root, int data) {
        if (root == NULL) return NULL;
        if (data < root->data) return find(root->leftChild, data);
        else if (data > root->data) return find(root->rightChild, data);
        else return root;
    }

    Node* floor(Node* root, int data) {
        if (root == NULL) return NULL;
        if (root->data == data) return root;
        if (root->data > data) return floor(root->leftChild, data);
        Node* floorNode = floor(root->rightChild, data);
        return (floorNode != NULL) ? floorNode : root;
    }

    Node* ceil(Node* root, int data) {
        if (root == NULL) return NULL;
        if (root->data == data) return root;
        if (root->data < data) return ceil(root->rightChild, data);
        Node* ceilNode = ceil(root->leftChild, data);
        return (ceilNode != NULL) ? ceilNode : root;
    }
};

int main() {
    BST tree;
    tree.addNode(5, "Node 1");
    tree.addNode(3, "Node 2");
    tree.addNode(7, "Node 3");
    tree.addNode(2, "Node 4");
    tree.addNode(4, "Node 5");

    cout << "In-order Traversal of the BST:\n";
    tree.inOrder();

    tree.findMax();
    tree.findMin();
    tree.find(4);

    tree.floor(6);
    tree.ceil(6);

    cout << "\nDeleting node with data 3...\n";
    tree.deleteNode(3);
    cout << "In-order Traversal of the BST after deletion:\n";
    tree.inOrder();

    return 0;
}
