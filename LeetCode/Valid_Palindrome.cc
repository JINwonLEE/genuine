class Solution {
public:
    string changeAlpha(string s) {
        string result = "";
        for (int i = 0; i <s.size(); i++) {
            if (s[i] <= 90 && s[i] >= 65) {
                result += s[i] + 32; 
            } else if (s[i] >= 97 && s[i] <= 122) {
                result += s[i];
            } else if (s[i] >= 48 && s[i] <= 57) {
                result += s[i];
            }
        }
        return result;
    }
    
    bool isPalindrome(string s) {
        string str = changeAlpha(s);
        int st = 0;
        int en = str.size() - 1;
        while (st < en) {
            if (str[st] != str[en]) return false;
            st++; en--;
        }
        return true;
    }
};
