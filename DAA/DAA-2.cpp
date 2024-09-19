#include <bits/stdc++.h>
using namespace std;
// Huffman Tree Node Class
class MinHeapNode {
public:
    char data;   // Character
    unsigned freq; // Frequency

    MinHeapNode* left, *right;

    MinHeapNode(char data, unsigned freq) {
        left = right = NULL;
        this->data = data;
        this->freq = freq;
    }
};
// Comparator class for the priority queue
class Compare {
public:
    bool operator()(MinHeapNode* l, MinHeapNode* r) {
        return l->freq > r->freq;
    }
};

// Function to print Huffman Codes from the root of the Huffman Tree
void printCodes(MinHeapNode* root, string str) {
    if (!root) return;

    if (root->data != '$')
        cout << root->data << ": " << str << "\n";

    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}

// Function to print how nodes are grouped at each step
void printGrouping(MinHeapNode* left, MinHeapNode* right, MinHeapNode* top) {
    cout << "Merging nodes: ";

    if (left->data != '$')
        cout << "'" << left->data << "' (" << left->freq << ")";
    else
        cout << "'$' (" << left->freq << ")";

    cout << " + ";

    if (right->data != '$')
        cout << "'" << right->data << "' (" << right->freq << ")";
    else
        cout << "'$' (" << right->freq << ")";

    cout << " => New Node: '$' (" << top->freq << ")" << endl;
}

// Function to build the Huffman Tree and print the codes
void HuffmanCodes(char data[], int freq[], int size) {
    MinHeapNode *left, *right, *top;

    // Create a min heap using the priority queue
    priority_queue<MinHeapNode*, vector<MinHeapNode*>, Compare> minHeap;

    for (int i = 0; i < size; ++i)
        minHeap.push(new MinHeapNode(data[i], freq[i]));

    while (minHeap.size() != 1) {
        left = minHeap.top();
        minHeap.pop();

        right = minHeap.top();
        minHeap.pop();

        top = new MinHeapNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;

        printGrouping(left, right, top);

        minHeap.push(top);
    }

    printCodes(minHeap.top(), "");
}

// Function to take a string input and return sorted character-frequency arrays
void getSortedFrequencyArrays(const string& input, vector<char>& arr, vector<int>& freq) {
    // Step 1: Count the frequency of each character
    unordered_map<char, int> freqMap;
    for (char ch : input) {
        freqMap[ch]++;
    }

    // Step 2: Store the characters and frequencies in a vector of pairs
    vector<pair<char, int>> charFreqPairs;
    for (const auto& entry : freqMap) {
        charFreqPairs.push_back(entry);
    }

    // Step 3: Sort the vector based on the frequency
    sort(charFreqPairs.begin(), charFreqPairs.end(), [](pair<char, int>& a, pair<char, int>& b) {
        return a.second < b.second;
    });

    // Step 4: Extract the sorted characters and frequencies into separate arrays
    for (const auto& entry : charFreqPairs) {
        arr.push_back(entry.first);
        freq.push_back(entry.second);
    }
}

// Driver code
int main() {
    // Input string
    string input;
    cout << "Enter a string: ";
    cin >> input;

    // Vector to store characters and frequencies
    vector<char> arr;
    vector<int> freq;

    // Get sorted characters and their frequencies
    getSortedFrequencyArrays(input, arr, freq);

    // Print sorted characters and frequencies
    cout << "Sorted characters and frequencies:\n";
    for (size_t i = 0; i < arr.size(); ++i) {
        cout << "'" << arr[i] << "': " << freq[i] << "\n";
    }

    // Build Huffman Tree and print codes
    HuffmanCodes(arr.data(), freq.data(), arr.size());

    return 0;
/*
    Enter a string: AAAAAAABBCCCCCCDDDEEEEEEEEE
Sorted characters and frequencies:
'B': 2
'D': 3
'C': 6
'A': 7
'E': 9
Merging nodes: 'B' (2) + 'D' (3) => New Node: '$' (5)
Merging nodes: '$' (5) + 'C' (6) => New Node: '$' (11)
Merging nodes: 'A' (7) + 'E' (9) => New Node: '$' (16)
Merging nodes: '$' (11) + '$' (16) => New Node: '$' (27)
B: 000
D: 001
C: 01
A: 10
E: 11
*/
}
