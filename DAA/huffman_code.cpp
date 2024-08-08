#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;
struct HuffmanNode {
    char data;
    int frequency;
    HuffmanNode* left;
    HuffmanNode* right;

    HuffmanNode(char data, int frequency) : data(data), frequency(frequency), left(nullptr), right(nullptr) {}
};
struct CompareNodes {
    bool operator()(const HuffmanNode* a, const HuffmanNode* b) {
        return a->frequency > b->frequency;
    }
};
HuffmanNode* buildHuffmanTree(const unordered_map<char, int>& frequencyMap) {
    priority_queue<HuffmanNode*, vector<HuffmanNode*>, CompareNodes> minHeap;
    for (const auto& pair : frequencyMap) {
        HuffmanNode* node = new HuffmanNode(pair.first, pair.second);
        minHeap.push(node);
    }
    while (minHeap.size() > 1) {
        HuffmanNode* left = minHeap.top();
        minHeap.pop();
        HuffmanNode* right = minHeap.top();
        minHeap.pop();
        HuffmanNode* internalNode = new HuffmanNode('$', left->frequency + right->frequency);
        internalNode->left = left;
        internalNode->right = right;
        minHeap.push(internalNode);
    }
    return minHeap.top();
}
void printHuffmanCodes(HuffmanNode* root, string code, unordered_map<char, string>& huffmanCodes) {
    if (root == nullptr) {
        return;
    }
    if (root->data != '$') {
        huffmanCodes[root->data] = code;
    }
    printHuffmanCodes(root->left, code + "0", huffmanCodes);
    printHuffmanCodes(root->right, code + "1", huffmanCodes);
}
int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;
    unordered_map<char, int> frequencyMap;
    for (char c : input) {
        frequencyMap[c]++;
    }
    HuffmanNode* root = buildHuffmanTree(frequencyMap);
    unordered_map<char, string> huffmanCodes;
    string code;
    printHuffmanCodes(root, code, huffmanCodes);
    cout << "Huffman Codes:" << endl;
    for (const auto& pair : huffmanCodes) {
        cout << pair.first << ": " << pair.second << endl;
    }
    return 0;
}
