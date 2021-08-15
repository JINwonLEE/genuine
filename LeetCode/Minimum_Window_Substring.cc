class Solution {
public:
    string minWindow(string s, string t) {
        int t_len = t.length();
        int s_len = s.length();
        map<char, int> t_set;
        for (auto c : t) {
            t_set[c] += 1;
        }
        
        int start = 0;
        int end = 0;
        int min_index = 0;
        bool isValid = false;
        for (int max_index = 0; max_index < s_len; max_index++) {
            t_len -= t_set[s[max_index]] > 0;
            t_set[s[max_index]]--;
            
            if (!t_len) {
                while (min_index < max_index && t_set[s[min_index]] < 0) {
                    t_set[s[min_index]] += 1;
                    min_index++;
                }
                
                if (!end || max_index - min_index <= end - start) {
                    isValid = true;
                    start = min_index;
                    end = max_index;
                    t_set[s[min_index]] += 1;
                    min_index++;
                    t_len += 1;
                } 
            }
        }
        if (!isValid) return "";
        return s.substr(start, end - start + 1);
        
    }
};
