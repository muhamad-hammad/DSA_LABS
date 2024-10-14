// You&#39;re tasked with designing a Document class for a document editor program. The class should
// handle text content, ensuring that copying a document creates a deep copy of the content to maintain
// data integrity. Follow the Rule of Three to manage resource allocation and deallocation correctly.
// Here are the key requirements:
// (a) Create a constructor that takes initial text content and allocates memory for it.
// (b) Implement a destructor to deallocate memory used for the text content.
// (c) Create a copy constructor that performs a deep copy of the text content, preventing unintended
// sharing.
// (d) Create a copy assignment operator that ensures a deep copy of the text content, maintaining
// separation between objects.
// (e) Provide a sample program that showcases your Document class. Create an original document,
// generate copies using both the copy constructor and copy assignment operator, modify the
// original&#39;s content, and show that the copies remain unaffected.
#include <iostream>
#include <string>

using namespace std;

class Document {
private:
    string* text; 
public:
    // Constructor
    Document(const string& content) {
        text = new string(content); 
    }

    // Copy constructor
    Document(const Document& other) {
        text = new string(*(other.text));
    }

    // Copy assignment operator
    Document& operator=(const Document& other) {
        if (this != &other) {
            delete text;  // Deallocate existing memory
            text = new string(*(other.text));
        }
        return *this;
    }

    // Destructor
    ~Document() {
        delete text;  // Deallocate memory
        cout << "Memory deallocated" << endl;
    }

    // Display function
    void display() const {
        cout << "Text: " << *text << endl;
    }
};

int main() {
    // Original document
    Document original("Hello, World!");

    // Copy using the copy constructor
    Document copy1(original);

    // Copy using copy assignment operator
    Document copy2("Temporary");
    copy2 = original;

    // Display all documents
    cout << "Original: ";
    original.display();
    cout << "Copy 1: ";
    copy1.display();
    cout << "Copy 2: ";
    copy2.display();

    // Modify the original document
    original = Document("Modified content");

    // Display all documents again to show that copies remain unaffected
    cout << "\nAfter modification:\n";
    cout << "Original: ";
    original.display();
    cout << "Copy 1: ";
    copy1.display();
    cout << "Copy 2: ";
    copy2.display();

    return 0;
}
