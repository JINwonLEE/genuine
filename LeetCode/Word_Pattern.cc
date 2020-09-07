class Solution {
public:
    bool wordPattern(string pattern, string str) {
        if (pattern.size() == 0 && str.size() != 0) return false;
        if (str.size() == 0 && pattern.size() != 0) return false;
        map<char, string> p_to_str;
        map<string, char> str_to_p;
        for (int i = 0; i < pattern.size(); i++) {
            p_to_str[pattern[i]] = ""; 
        }
        
        int index = 0;
        stringstream check1(str);
        string intermed;
        while (getline(check1, intermed, ' ')) {
            if (p_to_str[pattern[index]] !=  "" && p_to_str[pattern[index]] != intermed ) {
                return false;
            }
            
            if (p_to_str[pattern[index]] == "") {
                p_to_str[pattern[index]] = intermed;
            }
            
            if (str_to_p.find(intermed) == str_to_p.end()) {
                str_to_p[intermed] = pattern[index];
            }
            
            if (str_to_p[intermed] != pattern[index]) {
                return false;
            }
            index++;
        }
        
        for (auto ele : p_to_str) {
            if (ele.second == "") return false;
        }
        
        
        return true;
    }
};
