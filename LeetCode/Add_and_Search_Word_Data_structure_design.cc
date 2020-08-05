static const auto io_sync_off = []()
{
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();

class WordDictionary {
public:
    unordered_map<int, vector<string>> size_dict;
    /** Initialize your data structure here. */
    WordDictionary() {
        
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        //dict.insert(word);
        size_dict[word.size()].push_back(word);
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        int len = word.size();
        for (auto ele : size_dict[len]) {
            bool check = true;
            for (int i = 0;  i < len; i++) {
                if (word[i] != ele[i] && word[i] != '.') {
                    check = false;
                    break;
                }
            }
            if (check) return true;
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
