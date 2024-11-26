// In this assignment, the "database" will be a simple, memory-based (non-persistent, no filing required)
// structure that allows storing and managing data. There will be tables that store records.
// Each "table" should store records with three fields:
// • ID (integer, unique identifier)
// • Name (string)
// • Age (integer)
// The database tables will be represented using the below different tree structures:
// 1. Binary Search Tree (BST)
// 2. AVL Tree
// 3. B-Tree
// Each tree structure will independently store the same table data, serving as an "index" for organizing and
// managing the records. By implementing the table with the given type of trees, you can examine how each
// structure affects the performance of various database operations.
// For example:
// For a Binary Search Tree (BST) for a particular table, the records in that table (E.g. BST_TABLE) will be
// organized according to the BST rules, with each record represented by a node in the tree.
// Similarly, if you use an AVL Tree for the table (E.g. AVL_TABLE), the records in that table will follow AVL
// Tree properties, ensuring that the tree remains balanced after each insertion or deletion.
// Each tree type should support common database operations.
// • Insert: Adding a new record to the table.
// • Search: Finding a record by ID.
// • Delete: Removing a record by ID.
// Performance Analysis
// Implement timing functionality to measure the performance of each operation (Insert, Search, Delete) for
// each tree structure. For each operation, measure the average time for a dataset of various sizes (e.g.,
// 1,000, 10,000, and 50,000 records). For example, for a fixed size of records, say 10,000 what is the average
// search time of 20 search queries in all the three types of tables?
// Note: (You will need to create a separate function to generate dummy data of the given size).
// Present results in a table or graph and write a short analysis of the time complexity observed versus
// expected for each data structure.

#include <iostream>
#include <string> 
#include <chrono>
#include <random>
#include <ctime>
#include <cstdlib>
using namespace std;

class Record {
public:
    int id;
    string name;
    int age;

    Record(int Id =0 , string Name = " ", int Age = 0) : id(Id), name(Name), age(Age) {}
    int getId() { return id; }
    string getName() { return name; }
    int getAge() { return age; }
    void setId(int Id) { id = Id; }
    void setName(string Name) { name = Name; }
    void setAge(int Age) { age = Age; }
    bool operator<(const Record& r) const { return id < r.id; }

    ~Record() { cout << "Record deleted" << endl; }
};


Record *generateData(int size)
{
    Record *data = new Record[size];
    for (int i = 0; i < size; i++)
    {
        int id = rand() % (size * 10); // Random ID in a large range
        string name = "Name" + to_string(id);
        int age = rand() % 100 + 1; // Random age between 1 and 100
        data[i] = Record(id, name, age);
    }
    return data;
}


class DatabaseOperations {
public:
    virtual void insert(Record* record) = 0;
    virtual void search(int ID) = 0;
    virtual void deleteRecord(int ID) = 0;
    virtual ~DatabaseOperations() {}

    
};

// B-Tree Node Class
class BTreeNode {
public:
    Record* keys;          // Array of keys
    BTreeNode** C;         // Array of child pointers
    int t;                 // Minimum degree
    int n;                 // Current number of keys
    bool leaf;             // True if node is a leaf

    BTreeNode(int _t, bool _leaf);
    ~BTreeNode();
    void traverse();
    BTreeNode* search(int id);
    void insertNonFull(const Record& record);
    void splitChild(int i, BTreeNode* y);
    void remove(int id);
    int findKey(int id);
    void removeFromLeaf(int idx);
    void removeFromNonLeaf(int idx);
    Record getPredecessor(int idx);
    Record getSuccessor(int idx);
    void fill(int idx);
    void borrowFromPrev(int idx);
    void borrowFromNext(int idx);
    void merge(int idx);

    friend class BTree;
};

// B-Tree Node Constructor
BTreeNode::BTreeNode(int t1, bool leaf1) : t(t1), leaf(leaf1), n(0) {
    keys = new Record[2 * t - 1];   // Maximum keys = 2t - 1
    C = new BTreeNode*[2 * t];      // Maximum children = 2t
}

// B-Tree Node Destructor
BTreeNode::~BTreeNode() {
    delete[] keys;
    for (int i = 0; i <= n; ++i) {
        if (C[i]) delete C[i];
    }
    delete[] C;
}

// Traverse the subtree rooted with this node
void BTreeNode::traverse() {
    int i;
    for (i = 0; i < n; i++) {
        if (!leaf) C[i]->traverse();
        cout << "ID: " << keys[i].id << ", Name: " << keys[i].name << ", Age: " << keys[i].age << endl;
    }
    if (!leaf) C[i]->traverse();
}

// Search key in subtree rooted with this node
BTreeNode* BTreeNode::search(int id) {
    int i = 0;
    while (i < n && id > keys[i].id) i++;

    if (i < n && keys[i].id == id) return this;

    if (leaf) return nullptr;

    return C[i]->search(id);
}

// Insert key in non-full node
void BTreeNode::insertNonFull(const Record& record) {
    int i = n - 1;
    if (leaf) {
        while (i >= 0 && record < keys[i]) {
            keys[i + 1] = keys[i];
            i--;
        }
        keys[i + 1] = record;
        n++;
    } else {
        while (i >= 0 && record < keys[i]) i--;
        i++;
        if (C[i]->n == 2 * t - 1) {
            splitChild(i, C[i]);
            if (record.id > keys[i].id) i++;
        }
        C[i]->insertNonFull(record);
    }
}

// Split child of node
void BTreeNode::splitChild(int i, BTreeNode* y) {
    BTreeNode* z = new BTreeNode(y->t, y->leaf);
    z->n = t - 1;

    for (int j = 0; j < t - 1; j++) z->keys[j] = y->keys[j + t];
    if (!y->leaf) {
        for (int j = 0; j < t; j++) z->C[j] = y->C[j + t];
    }

    y->n = t - 1;
    for (int j = n; j >= i + 1; j--) C[j + 1] = C[j];
    C[i + 1] = z;
    for (int j = n - 1; j >= i; j--) keys[j + 1] = keys[j];
    keys[i] = y->keys[t - 1];
    n++;
}

// BTree Class
class BTree {
public:
    BTreeNode* root;
    int t;

    BTree(int _t) : root(nullptr), t(_t) {}

    ~BTree() { if (root) delete root; }

    void traverse() {
        if (root) root->traverse();
    }

    BTreeNode* search(int id) {
        return root ? root->search(id) : nullptr;
    }

    void insert(const Record& record);
    void remove(int id);
};

// Insert a new key into the B-Tree
void BTree::insert(const Record& record) {
    if (!root) {
        root = new BTreeNode(t, true);
        root->keys[0] = record;
        root->n = 1;
    } else {
        if (root->n == 2 * t - 1) {
            BTreeNode* s = new BTreeNode(t, false);
            s->C[0] = root;
            s->splitChild(0, root);
            int i = 0;
            if (s->keys[0].id < record.id) i++;
            s->C[i]->insertNonFull(record);
            root = s;
        } else {
            root->insertNonFull(record);
        }
    }
}

// Remove key from the B-Tree
void BTree::remove(int id) {
    if (!root) {
        cout << "Tree is empty\n";
        return;
    }
    root->remove(id);
    if (root->n == 0) {
        BTreeNode* tmp = root;
        root = root->leaf ? nullptr : root->C[0];
        delete tmp;
    }
}


class BSTNode
{
public:
    Record *data;
    BSTNode *left;
    BSTNode *right;
    BSTNode(Record *data) : data(data), left(nullptr), right(nullptr) {}
    ~BSTNode()
    {
        delete data;
    }
};


class BST : public DatabaseOperations
{
public:
void deleteRecord(int ID) override
    {
        deleteNode(ID,root);
    }
    BSTNode *root;
    BST() : root(nullptr) {}
    ~BST()
    {
        delete root;
    }
    void insert(Record *record) override
    {
        insertNode(record->getId(), record->getName(), record->getAge());
    }

    void insertNode(int key, string name, int age)
    {
        BSTNode *newNode = new BSTNode(new Record(key, name, age));
        if (root == nullptr)
        {
            root = newNode;
        }
        else
        {
            BSTNode *current = root;
            BSTNode *parent;
            while (true)
            {
                parent = current;
                if (key < current->data->getId())
                {
                    current = current->left;
                    if (current == nullptr)
                    {
                        parent->left = newNode;
                        return;
                    }
                }
                else
                {
                    current = current->right;
                    if (current == nullptr)
                    {
                        parent->right = newNode;
                        return;
                    }
                }
            }
        }
    }
    void search(int ID) override
    {
        searchNode(ID);
    }
    void searchNode(int key)
    {
        BSTNode *current = root;
        while (current != NULL)
        {
            if (current->data->getId() == key)
            {
                cout << "Record found: " << current->data->getId() << ", " << current->data->getName() << ", " << current->data->getAge() << endl;
                return;
            }
            else if (key < current->data->getId())
            {
                current = current->left;
            }
            else
            {
                current = current->right;
            }
        }
        cout << "Record not found" << endl;
    }

    BSTNode *findMin(BSTNode *node)
    {
        while (node->left != NULL)
        {
            node = node->left;
        }
        return node;
    }

    
    void deleteNode(int key, BSTNode* root)
    {
        BSTNode *current = root;
        BSTNode *parent = nullptr;

        while (current != nullptr)
        {
            if (current->data->getId() == key)
            {
                // Case 1: Node has no children (leaf node)
                if (current->left == nullptr && current->right == nullptr)
                {
                    if (parent == nullptr)
                    {
                        root = nullptr;
                    }
                    else if (parent->left == current)
                    {
                        parent->left = nullptr;
                    }
                    else
                    {
                        parent->right = nullptr;
                    }
                    delete current;
                }
                // Case 2: Node has only right child
                else if (current->left == nullptr)
                {
                    if (parent == nullptr)
                    {
                        root = current->right;
                    }
                    else if (parent->left == current)
                    {
                        parent->left = current->right;
                    }
                    else
                    {
                        parent->right = current->right;
                    }
                    delete current;
                }
                // Case 3: Node has only left child
                else if (current->right == nullptr)
                {
                    if (parent == nullptr)
                    {
                        root = current->left;
                    }
                    else if (parent->left == current)
                    {
                        parent->left = current->left;
                    }
                    else
                    {
                        parent->right = current->left;
                    }
                    delete current;
                }
                // Case 4: Node has two children
                else
                {
                    // Find the in-order successor and its parent
                    BSTNode *successor = current->right;
                    BSTNode *successorParent = current;

                    while (successor->left != nullptr)
                    {
                        successorParent = successor;
                        successor = successor->left;
                    }

                    // Replace current node's data with successor's data
                    current->data = successor->data;

                    // Remove the successor
                    if (successorParent->left == successor)
                    {
                        successorParent->left = successor->right;
                    }
                    else
                    {
                        successorParent->right = successor->right;
                    }
                    delete successor;
                }
                return;
            }
            else if (key < current->data->getId())
            {
                parent = current;
                current = current->left;
            }
            else
            {
                parent = current;
                current = current->right;
            }
        }
        cout << "Record not found" << endl;
    }
 
};

class AVLNode
{
public:
    Record *data;
    AVLNode *left;
    AVLNode *right;
    int height;
    AVLNode(Record *data) : data(data), left(nullptr), right(nullptr), height(1) {}
    ~AVLNode()
    {
        delete data;
    }
};
class AVL : public DatabaseOperations
{
public:
    AVLNode *root;
    AVL() : root(nullptr) {}
    void deleteRecord(int ID) override
    {
        root = deleteNode(root, ID);
    }
    ~AVL()
    {
        delete root;
    }
    int getHeight(AVLNode *node)
    {
        if (node == NULL)
        {
            return 0;
        }
        return node->height;
    }
    int getBalanceFactor(AVLNode *node)
    {
        if (node == NULL)
        {
            return 0;
        }
        return getHeight(node->left) - getHeight(node->right);
    }
    bool isBalanced(AVLNode *node)
    {
        if (node == NULL)
        {
            return true;
        }

        int balanceFactor = getBalanceFactor(node);

        return abs(balanceFactor) <= 1 && isBalanced(node->left) && isBalanced(node->right);
    }

    AVLNode *rightRotate(AVLNode *y)
    {
        AVLNode *x = y->left;
        AVLNode *t2 = x->right;

        x->right = y;
        y->left = t2;

        y->height = 1 + max(getHeight(y->left), getHeight(y->right));
        x->height = 1 + max(getHeight(x->left), getHeight(x->right));

        return x;
    }

    AVLNode *leftRotate(AVLNode *y)
    {
        AVLNode *x = y->right;
        AVLNode *t2 = x->left;

        x->left = y;
        y->right = t2;

        y->height = 1 + max(getHeight(y->left), getHeight(y->right));
        x->height = 1 + max(getHeight(x->left), getHeight(x->right));

        return x;
    }
    void insert(Record *record) override
    {
        root = insert(root, record);
    }

    AVLNode *insert(AVLNode *node, Record *data)
    {
        if (node == NULL)
        {
            return new AVLNode(data);
        }
        if (data->getId() < node->data->getId())
        {
            node->left = insert(node->left, data);
        }
        else if (data->getId() > node->data->getId())
        {
            node->right = insert(node->right, data);
        }
        else
        {
            return node;
        }
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
        int balanceFactor = getBalanceFactor(node);
        if (balanceFactor > 1 && data->getId() < node->left->data->getId())
        {
            return rightRotate(node);
        }
        if (balanceFactor < -1 && data->getId() > node->right->data->getId())
        {
            return leftRotate(node);
        }
        if (balanceFactor > 1 && data->getId() > node->left->data->getId())
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        if (balanceFactor < -1 && data->getId() < node->right->data->getId())
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
        return node;
    }
    AVLNode *deleteNode(AVLNode *root, int key)
    {
        if (root == NULL)
        {
            return NULL;
        }
        if (key < root->data->getId())
        {
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->data->getId())
        {
            root->right = deleteNode(root->right, key);
        }
        else
        {
            if (root->left == NULL)
            {
                AVLNode *temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == NULL)
            {
                AVLNode *temp = root->left;
                delete root;
                return temp;
            }
            AVLNode *temp = findMin(root->right);
            root->data->setId(temp->data->getId());
            root->right = deleteNode(root->right, temp->data->getId());
        }

        if (root == NULL)
        {
            return root;
        }

        root->height = 1 + max(getHeight(root->left), getHeight(root->right));
        int balanceFactor = getBalanceFactor(root);

        if (balanceFactor > 1 && getBalanceFactor(root->left) >= 0)
        {
            return rightRotate(root);
        }
        if (balanceFactor > 1 && getBalanceFactor(root->left) < 0)
        {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
        if (balanceFactor < -1 && getBalanceFactor(root->right) <= 0)
        {
            return leftRotate(root);
        }
        if (balanceFactor < -1 && getBalanceFactor(root->right) > 0)
        {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }

    AVLNode *findMin(AVLNode *node)
    {
        while (node->left != NULL)
        {
            node = node->left;
        }
        return node;
    }

    void search(int ID) override
    {
        searchNode(root, ID);
    }
    void searchNode(AVLNode *root, int key)
    {
        AVLNode *current = root;
        while (current != NULL)
        {
            if (current->data->getId() == key)
            {
                cout << "Record found: " << current->data->getId() << ", " << current->data->getName() << ", " << current->data->getAge() << endl;
                return;
            }
            else if (key < current->data->getId())
            {
                current = current->left;
            }
            else
            {
                current = current->right;
            }
        }
        cout << "Record not found" << endl;
    }
};

void measurePerformanceBST(BST &bst, Record *data, int dataSize, int testSize) {
    if (testSize > dataSize) {
        cout << "Test size exceeds data size. Adjusting test size to " << dataSize << ".\n";
        testSize = dataSize;
    }

    auto startInsert = chrono::high_resolution_clock::now();
    for (int i = 0; i < testSize; ++i) {
        bst.insert(&data[i]);
    }
    auto endInsert = chrono::high_resolution_clock::now();
    double insertTime = chrono::duration_cast<chrono::microseconds>(endInsert - startInsert).count() / double(testSize);

    auto startSearch = chrono::high_resolution_clock::now();
    for (int i = 0; i < testSize; ++i) {
        bst.search(data[i].getId());
    }
    auto endSearch = chrono::high_resolution_clock::now();
    double searchTime = chrono::duration_cast<chrono::microseconds>(endSearch - startSearch).count() / double(testSize);

    auto startDelete = chrono::high_resolution_clock::now();
    for (int i = 0; i < testSize; ++i) {
        bst.deleteRecord(data[i].getId());
    }
    auto endDelete = chrono::high_resolution_clock::now();
    double deleteTime = chrono::duration_cast<chrono::microseconds>(endDelete - startDelete).count() / double(testSize);

    cout << "BST Performance (Average time in microseconds for test size " << testSize << "):\n"
         << "Insert: " << insertTime << "\n"
         << "Search: " << searchTime << "\n"
         << "Delete: " << deleteTime << "\n";
}

void measurePerformanceBTree(BTree &btree, Record *data, int dataSize, int testSize) {
    if (testSize > dataSize) {
        cout << "Test size exceeds data size. Adjusting test size to " << dataSize << ".\n";
        testSize = dataSize;
    }

    auto startInsert = chrono::high_resolution_clock::now();
    for (int i = 0; i < testSize; ++i) {
        btree.insert(data[i]);
    }
    auto endInsert = chrono::high_resolution_clock::now();
    double insertTime = chrono::duration_cast<chrono::microseconds>(endInsert - startInsert).count() / double(testSize);

    auto startSearch = chrono::high_resolution_clock::now();
    for (int i = 0; i < testSize; ++i) {
        btree.search(data[i].getId());
    }
    auto endSearch = chrono::high_resolution_clock::now();
    double searchTime = chrono::duration_cast<chrono::microseconds>(endSearch - startSearch).count() / double(testSize);

    auto startDelete = chrono::high_resolution_clock::now();
    for (int i = 0; i < testSize; ++i) {
        btree.remove(data[i].getId());
    }
    auto endDelete = chrono::high_resolution_clock::now();
    double deleteTime = chrono::duration_cast<chrono::microseconds>(endDelete - startDelete).count() / double(testSize);

    cout << "B-Tree Performance (Average time in microseconds for test size " << testSize << "):\n"
         << "Insert: " << insertTime << "\n"
         << "Search: " << searchTime << "\n"
         << "Delete: " << deleteTime << "\n";
}void measurePerformanceAVL(AVL &avl, Record *data, int dataSize, int testSize) {
    if (testSize > dataSize) {
        cout << "Test size exceeds data size. Adjusting test size to " << dataSize << ".\n";
        testSize = dataSize;
    }

    auto startInsert = chrono::high_resolution_clock::now();
    for (int i = 0; i < testSize; ++i) {
        avl.insert(&data[i]);
    }
    auto endInsert = chrono::high_resolution_clock::now();
    double insertTime = chrono::duration_cast<chrono::microseconds>(endInsert - startInsert).count() / double(testSize);

    auto startSearch = chrono::high_resolution_clock::now();
    for (int i = 0; i < testSize; ++i) {
        avl.search(data[i].getId());
    }
    auto endSearch = chrono::high_resolution_clock::now();
    double searchTime = chrono::duration_cast<chrono::microseconds>(endSearch - startSearch).count() / double(testSize);

    auto startDelete = chrono::high_resolution_clock::now();
    for (int i = 0; i < testSize; ++i) {
        avl.deleteRecord(data[i].getId());
    }
    auto endDelete = chrono::high_resolution_clock::now();
    double deleteTime = chrono::duration_cast<chrono::microseconds>(endDelete - startDelete).count() / double(testSize);

    cout << "AVL Performance (Average time in microseconds for test size " << testSize << "):\n"
         << "Insert: " << insertTime << "\n"
         << "Search: " << searchTime << "\n"
         << "Delete: " << deleteTime << "\n";
}

int main() {
    int dataSize = 1000;
    int testSize = 500;

    // Generate records
    Record *data = generateData(dataSize);

    // Initialize tree objects
    BST bst;
    AVL avl;
    BTree btree(3); // Example: B-Tree of order 3

    // Measure performance for each tree
    measurePerformanceBST(bst, data, dataSize, testSize);
    measurePerformanceAVL(avl, data, dataSize, testSize);
    measurePerformanceBTree(btree, data, dataSize, testSize);

    delete[] data; // Clean up
    return 0;
}
