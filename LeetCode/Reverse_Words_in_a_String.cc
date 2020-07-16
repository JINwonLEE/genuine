class Solution {
public:
    string reverseWords(string s) {
        vector<string> tokens;
        string result = "";
        stringstream stream(s);
        string tmp;
        while (getline(stream, tmp, ' ')) {
            if (tmp != "") tokens.push_back(tmp);
        }
        
        for (int i = tokens.size() - 1; i >= 0; i--) {
            result += tokens[i];
            if (i != 0) {
                result += " ";
            }
        }
        
        return result;
    }
};
