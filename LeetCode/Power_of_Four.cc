class Solution {
public:
    bool isPowerOfFour(int num) {
        if (num <= 0) return false;
        int exp = log(num) / log(4);
        if (num == pow(4, exp)) return true;
        return false;
    }
};
