// Q5: Given two BST’s (Down Below) You are tasked to merge them together to form a new BST
// the output of this will be 1 2 2 3 3 4 5 6 6 7 (You can visualize this by drawing the array to a tree
// in your notebook).

// BST1:    
        //     5
        //    / \
        //   3   6
        //  / \
        // 2   4

// BST2:
        //     2
        //    / \
        //   1   3
        //        \
        //         7
        //        /
        //       6

#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    int key;
    string name;
    Node* leftChild;
    Node* rightChild;

    Node(int key, string name) {
        this->key = key;
        this->name = name;
        this->leftChild = NULL;
        this->rightChild = NULL;
    }

    string toString(int key) {
        return name + " has the key " + to_string(key) + " \n";
    }
};

class BinaryTree {
private:
    Node* root;

public:
    BinaryTree() {
        root = NULL;
    }

    void addNode(int key, string name) {
        Node* newNode = new Node(key, name);
        if (root == NULL) {
            root = newNode;
        } else {
            Node* current = root;
            Node* parent;
            while (true) {
                parent = current;
                if (key < current->key) {
                    current = current->leftChild;
                    if (current == NULL) {
                        parent->leftChild = newNode;
                        return;
                    }
                } else {
                    current = current->rightChild;
                    if (current == NULL) {
                        parent->rightChild = newNode;
                        return;
                    }
                }
            }
        }
    }

    void printTree(Node* node) {
        if (node != NULL) {
            printTree(node->leftChild);
            cout << node->toString(node->key);
            printTree(node->rightChild);
        }
    }

    void printTree() {
        printTree(root);
    }

    void inOrerTraversal(Node* node, int* arr, int& index) {
        if (node != NULL) {
            inOrerTraversal(node->leftChild, arr, index);
            arr[index++] = node->key;
            inOrerTraversal(node->rightChild, arr, index);
        }
    }

    void inOrerTraversal(int* arr, int& index) {
        index = 0;
        inOrerTraversal(root, arr, index);
    }

    Node* sortedArrayToBST(int* arr, int start, int end) {
        if (start > end) return nullptr;
        int mid = (start + end) / 2;
        Node* node = new Node(arr[mid], "");
        node->leftChild = sortedArrayToBST(arr, start, mid - 1);
        node->rightChild = sortedArrayToBST(arr, mid + 1, end);
        return node;
    }

    void buildFromSortedArray(int* arr, int n) {
        root = sortedArrayToBST(arr, 0, n - 1);
    }
};

int* arrMerge(int* arr1, int* arr2, int size1, int size2) {
    int* arr = new int[size1 + size2];
    int index = 0, i = 0, j = 0;
    while (i < size1 && j < size2) {
        if (arr1[i] < arr2[j]) {
            arr[index++] = arr1[i++];
        } else {
            arr[index++] = arr2[j++];
        }
    }
    while (i < size1) arr[index++] = arr1[i++];
    while (j < size2) arr[index++] = arr2[j++];
    return arr;
}

int main() {
    BinaryTree tree1;
    tree1.addNode(5, "Node 1");
    tree1.addNode(3, "Node 2");
    tree1.addNode(6, "Node 3");
    tree1.addNode(2, "Node 4");
    tree1.addNode(4, "Node 5");
    tree1.printTree();
    cout << endl;

    BinaryTree tree2;
    tree2.addNode(2, "Node 6");
    tree2.addNode(1, "Node 7");
    tree2.addNode(3, "Node 8");
    tree2.addNode(7, "Node 9");
    tree2.addNode(6, "Node 10");
    tree2.printTree();
    cout << endl;

    int size1 = 5;
    int size2 = 5;
    int* arr1 = new int[size1];
    int* arr2 = new int[size2];
    int index1 = 0, index2 = 0;

    tree1.inOrerTraversal(arr1, index1);
    tree2.inOrerTraversal(arr2, index2);

    int* mergedArr = arrMerge(arr1, arr2, index1, index2);

    BinaryTree tree3;
    tree3.buildFromSortedArray(mergedArr, index1 + index2);
    tree3.printTree();

    delete[] arr1;
    delete[] arr2;
    delete[] mergedArr;

    return 0;
}
