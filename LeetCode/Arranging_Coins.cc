class Solution {
public:
    int arrangeCoins(int n) {
        long long count = 1;
        long long sum = 1;
        while (n >= sum) {
            sum += ++count;
        }
        return count - 1;
    }
};
