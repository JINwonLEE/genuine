#include <string>
#include <vector>

using namespace std;

struct TrieNode {
    TrieNode* children[10];
    bool isEnd;
};

TrieNode* getNode() {
    TrieNode* newNode = new TrieNode();
    newNode->isEnd = false;
    for (int i = 0; i < 10; i++) newNode->children[i] = nullptr;
    return newNode;
}

void addString(TrieNode* root, string key) {
    TrieNode* cur = root;
    for (int i = 0; i < key.size(); i++) {
        int index = key[i] - '0';
        if (!cur->children[index])
            cur->children[index] = getNode();
        cur = cur->children[index];
    }
    cur->isEnd = true;
}

bool isInclude(TrieNode* root, string key) {
    TrieNode* cur = root;
    for (int i = 0; i < key.size() - 1; i++) {
        int index = key[i] - '0';
        if (cur->children[index]->isEnd) {
            return true;
        }
        cur = cur->children[index];
    }
    return false;
}

bool solution(vector<string> phone_book) {
    bool answer = true;
    TrieNode* root = getNode();
    for (auto phone : phone_book) addString(root, phone);
    for (auto phone : phone_book) {
        if (isInclude(root, phone)) {
           answer = false;
            break;
        } 
    }
    return answer;
}
