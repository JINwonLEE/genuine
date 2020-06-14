#include <string>

class Solution {
public:
    bool isPalindrome(int x) {
        string str = std::to_string(x);
        int length = str.size();
        
        int st = 0;
        int en = length - 1;
        
        while (st < en) {
            if (str[st] != str[en]) {
                return false;
            } else {
                st++;
                en--;
            }
        }
        
        return true;
    }
};
