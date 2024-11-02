#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    int key;
    int frequency;
    Node* leftChild;
    Node* rightChild;

    Node(int key, int frequency = 1) {
        this->key = key;
        this->frequency = frequency;
        this->leftChild = nullptr;
        this->rightChild = nullptr;
    }

    string toString() {
        return "Key: " + to_string(key) + ", Frequency: " + to_string(frequency) + "\n";
    }
};

class BinaryTree {
private:
    Node* root;

public:
    BinaryTree() {
        root = nullptr;
    }

    void addNode(int key, int frequency = 1) {
        root = insert(root, key, frequency);
    }

    Node* insert(Node* node, int key, int frequency) {
        if (node == nullptr) {
            return new Node(key, frequency);
        }
        if (key < node->key) {
            node->leftChild = insert(node->leftChild, key, frequency);
        } else if (key > node->key) {
            node->rightChild = insert(node->rightChild, key, frequency);
        }
        return node;
    }

    void printTree(Node* node) {
        if (node != nullptr) {
            printTree(node->leftChild);
            cout << node->toString();
            printTree(node->rightChild);
        }
    }

    void printTree() {
        printTree(root);
    }

    Node* sortedArrayToBST(int* arr, int start, int end) {
        if (start > end) return nullptr;

        int mid = (start + end) / 2;
        int currentKey = arr[mid];
        int frequency = 1;

        int leftIndex = mid - 1;
        int rightIndex = mid + 1;

        while (leftIndex >= start && arr[leftIndex] == currentKey) {
            frequency++;
            leftIndex--;
        }

        while (rightIndex <= end && arr[rightIndex] == currentKey) {
            frequency++;
            rightIndex++;
        }

        Node* node = new Node(currentKey, frequency);

        node->leftChild = sortedArrayToBST(arr, start, leftIndex);
        node->rightChild = sortedArrayToBST(arr, rightIndex, end);

        return node;
    }

    void buildFromSortedArray(int* arr, int n) {
        root = sortedArrayToBST(arr, 0, n - 1);
    }

    void inOrderTraversal(int* arr, int& index) {
        inOrderTraversalHelper(root, arr, index);
    }

private:
    void inOrderTraversalHelper(Node* node, int* arr, int& index) {
        if (node != nullptr) {
            inOrderTraversalHelper(node->leftChild, arr, index);
            arr[index++] = node->key;
            inOrderTraversalHelper(node->rightChild, arr, index);
        }
    }
};

void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int* arrMerge(int* arr1, int* arr2, int size1, int size2) {
    int* arr = new int[size1 + size2];
    int index = 0, i = 0, j = 0;
    while (i < size1 && j < size2) {
        if (arr1[i] <= arr2[j]) {
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
    tree1.addNode(5);
    tree1.addNode(3);
    tree1.addNode(6);
    tree1.addNode(2);
    tree1.addNode(4);
    cout << "Tree 1:\n";
    tree1.printTree();
    cout << endl;

    BinaryTree tree2;
    tree2.addNode(2);
    tree2.addNode(1);
    tree2.addNode(3);
    tree2.addNode(7);
    tree2.addNode(6);
    cout << "Tree 2:\n";
    tree2.printTree();
    cout << endl;

    int size1 = 5;
    int size2 = 5;
    int* arr1 = new int[size1];
    int* arr2 = new int[size2];
    int index1 = 0, index2 = 0;

    tree1.inOrderTraversal(arr1, index1);
    tree2.inOrderTraversal(arr2, index2);

    int* mergedArr = arrMerge(arr1, arr2, index1, index2);
    cout << "Merged array:\n";
    printArray(mergedArr, index1 + index2);

    BinaryTree mergedTree;
    mergedTree.buildFromSortedArray(mergedArr, index1 + index2);
    cout << "Merged BST with frequencies:\n";
    mergedTree.printTree();

    delete[] arr1;
    delete[] arr2;
    delete[] mergedArr;

    return 0;
}
