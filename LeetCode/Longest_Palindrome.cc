class Solution {
public:
    int longestPalindrome(string s) {
        ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
        int arr[52];
        for (int i = 0; i < 52; i++) arr[i] = 0;   
        for (int i = 0; i < s.size(); i++) arr[getIndex(s[i])]++;
        int result = 0;
        for (auto ele : arr) result += ele / 2;
        return result * 2 == s.size() ? result * 2 : result * 2 + 1; 
    }
    
    int getIndex(char a) {
        if (a >= 'a') 
            return a - 'a';
        else 
            return a - 'A' + 26;
    }
};
