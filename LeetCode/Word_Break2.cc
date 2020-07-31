class Solution {
public:
    unordered_map<string, vector<string>> map;
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        return makeSentences(s, wordDict);
    }
    
    vector<string> makeSentences(string s, vector<string>& wordDict) {
        vector<string> result;
        if (s.compare("") == 0) {
            result.push_back("");
            return result;
        }
        
        if (map.count(s)) return map[s];
        int len = s.size();
        for (int i = 0; i < len; i++) {
            string substr = s.substr(i);
            if (find(wordDict.begin(), wordDict.end(), substr) != wordDict.end()) {
                vector<string> tmp_list = makeSentences(s.substr(0, i), wordDict);
                
                for (auto tmp : tmp_list) {
                    result.push_back(tmp.size() == 0 ? substr : tmp + " " + substr);
                }
            }
        }
        map[s] = result;
        return result;
    }
};
