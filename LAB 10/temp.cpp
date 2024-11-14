// 4. Encode the String MHAMMAd via Huffman and display the encoded string
// 5. Decode the Encoded string back to the original string
#include<iostream>
#include<string>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node *left, *right;
    Node(char character, int frequency) : ch(character), freq(frequency), left(nullptr), right(nullptr) {}
};

void minHeapify(Node* arr[], int N, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < N && arr[left]->freq < arr[smallest]->freq)
        smallest = left;
    if (right < N && arr[right]->freq < arr[smallest]->freq)
        smallest = right;

    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        minHeapify(arr, N, smallest);
    }
}

void buildHeap(Node* arr[], int N) {
    for (int i = N / 2 - 1; i >= 0; i--)
        minHeapify(arr, N, i);
}

Node* extractMin(Node* arr[], int &N) {
    Node* minNode = arr[0];
    arr[0] = arr[N - 1];
    N--;
    minHeapify(arr, N, 0);
    return minNode;
}

void insertHeap(Node* arr[], Node* newNode, int &N) {
    N++;
    int i = N - 1;
    while (i && newNode->freq < arr[(i - 1) / 2]->freq) {
        arr[i] = arr[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    arr[i] = newNode;
}

Node* buildHuffmanTree(char uniqueChars[], int freq[], int N) {
    Node* heap[100];
    for (int i = 0; i < N; i++)
        heap[i] = new Node(uniqueChars[i], freq[i]);

    buildHeap(heap, N);

    while (N > 1) {
        Node* left = extractMin(heap, N);
        Node* right = extractMin(heap, N);
        Node* newNode = new Node('\0', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;
        insertHeap(heap, newNode, N);
    }
    return heap[0];
}

// Helper function to store Huffman codes in array
void storeCodes(Node* root, string code, char uniqueChars[], string codes[], int N) {
    if (!root) return;
    if (root->ch != '\0') {
        for (int i = 0; i < N; i++) {
            if (root->ch == uniqueChars[i]) {
                codes[i] = code;
                break;
            }
        }
    }
    storeCodes(root->left, code + "0", uniqueChars, codes, N);
    storeCodes(root->right, code + "1", uniqueChars, codes, N);
}

// Encode the input text using the Huffman codes
string encodeString(string text, char uniqueChars[], string codes[], int N) {
    string encoded = "";
    for (char ch : text) {
        for (int i = 0; i < N; i++) {
            if (ch == uniqueChars[i]) {
                encoded += codes[i];
                break;
            }
        }
    }
    return encoded;
}

// Decode the encoded string using the Huffman Tree
string decodeString(Node* root, string encoded) {
    string decoded = "";
    Node* current = root;
    for (char bit : encoded) {
        if (bit == '0')
            current = current->left;
        else
            current = current->right;
        
        // If leaf node is reached
        if (!current->left && !current->right) {
            decoded += current->ch;
            current = root;  // Go back to the root for the next character
        }
    }
    return decoded;
}

int main() {
    string text = "MHAMMAD";
    char uniqueChars[4] = {'M', 'H', 'A', 'D'};
    int freq[4] = {0};

    // Count frequencies of characters manually
    for (char ch : text) {
        for (int i = 0; i < 4; i++) {
            if (ch == uniqueChars[i]) {
                freq[i]++;
                break;
            }
        }
    }

    // Build Huffman Tree
    int N = 4;
    Node* root = buildHuffmanTree(uniqueChars, freq, N);

    // Store Huffman codes
    string codes[4];
    storeCodes(root, "", uniqueChars, codes, N);

    // Display Huffman codes
    cout << "Huffman Codes:" << endl;
    for (int i = 0; i < N; i++) {
        cout << uniqueChars[i] << ": " << codes[i] << endl;
    }

    // Encode the string
    string encoded = encodeString(text, uniqueChars, codes, N);
    cout << "\nEncoded String: " << encoded << endl;

    // Decode the string
    string decoded = decodeString(root, encoded);
    cout << "\nDecoded String: " << decoded << endl;

    return 0;
}
