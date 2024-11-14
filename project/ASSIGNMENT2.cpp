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
using namespace std;

// Abstract base class for database operations
class DatabaseOperations {
public:
    virtual void insert(Record* record) = 0;
    virtual void search(int ID) = 0;
    virtual void deleteRecord(int ID) = 0;
    virtual ~DatabaseOperations() {}
};

class Record
{
private:
    int id;
    string name;
    int age;

public:
    Record(int Id, string Name, int Age) : id(Id), name(Name), age(Age) {};
    int getId()
    {
        return id;
    }
    string getName()
    {
        return name;
    }
    int getAge()
    {
        return age;
    }
    void setId(int Id){
        id = Id;
    }
    void setName(string Name){
        name = Name;
    }
    void setAge(int Age){
        age = Age;
    }
    ~Record()
    {
        cout << "Record deleted" << endl;
    }
};

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
private:
public:
    BSTNode *root;
    BST() : root(nullptr) {}
    ~BST()
    {
        delete root;
    }
    void insert(Record* record) override {
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
    void search(int ID) override{
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
    
        void deleteRecord(int ID) override {
            deleteNode(ID);
        }
        void deleteNode(int key){
          BSTNode *current = root;
          BSTNode *parent = NULL;

          while (current != NULL && current->data->getId() != key)
          {
              parent = current;
              if (key < current->data->getId())
                  current = current->left;
              else
                  current = current->right;
          }

          if (current == NULL)
          {
              cout << "Record not found" << endl;
              return;
          }

          if (parent == NULL)
          {
              if (root->left == NULL && root->right == NULL)
              {
                  delete root;
                  root = NULL;
              }
              else if (root->left == NULL)
              {
                  BSTNode* temp = root;
                  root = root->right;
                  delete temp;
              }
              else if (root->right == NULL)
              {
                  BSTNode* temp = root;
                  root = root->left;
                  delete temp;
              }
              else
              {
                  BSTNode *minRight = findMin(root->right);
                  root->data->setId(minRight->data->getId());
                  root->data->setName(minRight->data->getName());
                  root->data->setAge(minRight->data->getAge());
                  deleteNode(minRight->data->getId());
              }
              return;
          }

          if (current->left == NULL && current->right == NULL)
          {
              if (parent->left == current)
                  parent->left = NULL;
              else
                  parent->right = NULL;
              delete current;
          }
          else if (current->left == NULL)
          {
              if (parent->left == current)
                  parent->left = current->right;
              else
                  parent->right = current->right;
              delete current;
          }
          else if (current->right == NULL)
          {
              if (parent->left == current)
                  parent->left = current->left;
              else
                  parent->right = current->left;
              delete current;
          }
          else
          {
              BSTNode *minRight = findMin(current->right);
              current->data->setId(minRight->data->getId());
              current->data->setName(minRight->data->getName());
              current->data->setAge(minRight->data->getAge());
              deleteNode(minRight->data->getId());
          }
      }
};

class AVLNode{
    public:
        Record* data;
        AVLNode* left;
        AVLNode* right;
        int height;
        AVLNode(Record* data) : data(data), left(nullptr), right(nullptr), height(1) {}
        ~AVLNode()
        {
            delete data;
        }
        
};
class AVL : public DatabaseOperations
{
    public:
    AVLNode* root;
    AVL() : root(nullptr) {}
    ~AVL(){
        delete root;
    }
        int getHeight(AVLNode* node)
        {
            if (node == NULL)
            {
                return 0;
            }
            return node->height;
        }
        int getBalanceFactor(AVLNode* node){
            if (node == NULL)
            {
                return 0;
            }
            return getHeight(node->left) - getHeight(node->right);
        }
        bool isBalanced(AVLNode* node) {
        if (node == NULL) {
            return true;
        }

        int balanceFactor = getBalanceFactor(node);

        return abs(balanceFactor) <= 1 && isBalanced(node->left) && isBalanced(node->right);
        }

        AVLNode* rightRotate(AVLNode* y) {
        AVLNode* x = y->left;
        AVLNode* t2 = x->right;

        x->right = y;
        y->left = t2;

        
        y->height = 1 + max(getHeight(y->left), getHeight(y->right));
        x->height = 1 + max(getHeight(x->left), getHeight(x->right));

        return x;
    }

    AVLNode* leftRotate(AVLNode* y) {
        AVLNode* x = y->right;
        AVLNode* t2 = x->left;

        x->left = y;
        y->right = t2;

        
        y->height = 1 + max(getHeight(y->left), getHeight(y->right));
        x->height = 1 + max(getHeight(x->left), getHeight(x->right));

        return x;
    }
    void insert(Record* record) override{
        root = insert(root, record);
    }

    AVLNode* insert(AVLNode* node, Record* data) {
        if (node == NULL) {
            return new AVLNode(data);
        }
        if (data->getId() < node->data->getId()) {
            node->left = insert(node->left, data);
        } else if (data->getId() > node->data->getId()) {
            node->right = insert(node->right, data);
        } else {
            return node;
        }
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
        int balanceFactor = getBalanceFactor(node);
        if (balanceFactor > 1 && data->getId() < node->left->data->getId()) {
            return rightRotate(node);
        }
        if (balanceFactor < -1 && data->getId() > node->right->data->getId()) {
            return leftRotate(node);
        }
        if (balanceFactor > 1 && data->getId() > node->left->data->getId()) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        if (balanceFactor < -1 && data->getId() < node->right->data->getId()) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
        return node;
    }
    void deleteRecord(int ID) override{
        root = deleteNode(root, ID);
    }
    AVLNode* deleteNode(AVLNode* root, int key) {
        if (root == NULL) {
            return NULL;
        }
        if (key < root->data->getId()) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->data->getId()) {
            root->right = deleteNode(root->right, key);
        } else {
            if (root->left == NULL) {
                AVLNode* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == NULL) {
                AVLNode* temp = root->left;
                delete root;
                return temp;
            }
            AVLNode* temp = findMin(root->right);
            root->data->setId(temp->data->getId());
            root->right = deleteNode(root->right, temp->data->getId());
        }

        
        if (root == NULL) {
            return root;
        }

        root->height = 1 + max(getHeight(root->left), getHeight(root->right));
        int balanceFactor = getBalanceFactor(root);

        if (balanceFactor > 1 && getBalanceFactor(root->left) >= 0) {
            return rightRotate(root);
        }
        if (balanceFactor > 1 && getBalanceFactor(root->left) < 0) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
        if (balanceFactor < -1 && getBalanceFactor(root->right) <= 0) {
            return leftRotate(root);
        }
        if (balanceFactor < -1 && getBalanceFactor(root->right) > 0) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }

    AVLNode* findMin(AVLNode* node) {
        while (node->left != NULL) {
            node = node->left;
        }
        return node;
    }


    void search(int ID) override {
        searchNode(root, ID);
    }
    void searchNode(AVLNode* root, int key) {
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


class BTNode{
    public:
        Record* data;
        BTNode* left;
        BTNode* right;
        BTNode(Record* data) : data(data), left(nullptr), right(nullptr) {}
        ~BTNode()
        {
            delete data;
        }
        Record* getData(){
            return data;
        }
        BTNode* getLeft(){
            return left;
        }
        BTNode* getRight(){
            return right;
        }
        void setData(Record* data){
            this->data = data;
        }
        void setLeft(BTNode* left){
            this->left = left;
        }
        void setRight(BTNode* right){
            this->right = right;
        }
};

class BTree : public DatabaseOperations
{
    public:
        BTNode* root;
        BTree() : root(nullptr) {}
        ~BTree()
        {
            delete root;
        }
        void insert(Record* data) override{
            BTNode* newNode = new BTNode(data);
            if (root == nullptr)
            {
                root = newNode;
            }
            else
            {
                BTNode* current = root;
                while (true)
                {
                    if (data->getId() < current->data->getId())
                    {
                        if (current->left == nullptr)
                        {
                            current->left = newNode;
                            break;
                        }
                        current = current->left;
                    }
                    else
                    {
                        if (current->right == nullptr)
                        {
                            current->right = newNode;
                            break;
                        }
                        current = current->right;
                    }
                }
            }
        }
        
        void search(int key) override{
            BTNode* current = root;
            while (current != nullptr)
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
        void deleteRecord(int ID){
            deleteNode(ID);
        }
        
        void deleteNode(int key){
            BTNode* current = root;
            BTNode* parent = nullptr;
            while (current != nullptr)
            {
                if (current->data->getId() == key)
                {
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
                    else if (current->right == nullptr){
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
                    else
                    {
                        BTNode* successor = current->right;
                        while (successor->left != nullptr)
                        {
                            successor = successor->left;
                        }
                        current->data = successor->data;
                        deleteNode(successor->data->getId());
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

        void display(){
            display(root);
        }

    private:
        void display(BTNode* node){
            if (node != nullptr)
            {
                display(node->left);
                cout << "Record: " << node->data->getId() << ", " << node->data->getName() << ", " << node->data->getAge() << endl;
                display(node->right);
            }
        }
};
