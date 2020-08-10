class Solution {
public:
    int titleToNumber(string s) {
        int index = 0;
        int len = s.size();
        int sum = 0;
        while (index < len) {
           int tmp = s[index] - 'A' + 1;
            sum += tmp * pow(26, len - index - 1);
            index++;
        }
        return sum;
    }
};
