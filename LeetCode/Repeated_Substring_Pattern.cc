class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        ios::sync_with_stdio(false);cin.tie(nullptr);
        
        int len = s.size();
        if (len == 1) return false;
        if (isValid(s, 1)) return true;
        for (int i = 2; i * i <= len; i++) {
            if (len % i == 0) {
                if ( isValid(s, i) || isValid(s, len / i))  return true;
            }
        }
        
        return false;
    }
    
    bool isValid(string s, int length) {
        string substring = s.substr(0, length);
        int occurence = 0;
        std::string::size_type pos = 0;
        while ((pos = s.find(substring, pos)) != string::npos) {
            occurence++;
            pos += length;
        }
        return occurence == s.size() / length;
    }
};
