static const auto io_sync_off = []()
{
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();

class CombinationIterator {
public:

    vector<char> chars;
    deque<int> pos;
    bool isDone = false;
    CombinationIterator(string characters, int combinationLength) {
        for (int i = 0; i < characters.size(); i++) {
            chars.emplace_back(characters[i]);
        }
        for (int i = 0; i < combinationLength; i++) {
            pos.emplace_back(i);
            chars[i] = toupper(chars[i]);
        }
    }
    
    string next() {
        string result = "";
        int len = chars.size();
        int pos_len = pos.size();
        for (int i = 0; i < pos_len; i++) {
            int p = pos.front(); pos.pop_front();
            result += tolower(chars[p]);
            pos.emplace_back(p);
        }
        for (int i = 0; i < pos_len; i++) {
            int prev = pos.back(); pos.pop_back();
            if (prev + 1 < len && chars[prev+1] > 'Z') {
                chars[prev] = tolower(chars[prev]);
                int current_size = pos.size();
                for (int i = 0; i < len - prev - 1; i++) {
                    if (i + current_size < pos_len) {
                        chars[prev + 1 + i] = toupper(chars[prev + 1 + i]);
                        pos.emplace_back(prev + 1 + i);
                    } else {
                        chars[prev + 1 + i] = tolower(chars[prev + 1 + i]);
                    }
                }
                break;
            }
        }
        if (pos.size() == 0) isDone = true;
        return result;
    }
    
    bool hasNext() {
        return !isDone;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
