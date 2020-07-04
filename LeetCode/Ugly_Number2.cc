class Solution {
public:
    int nthUglyNumber(int n) {
        int dp[1690];
        int mul_2 = 0;
        int mul_3 = 0;
        int mul_5 = 0;
        dp[0] = 1;
        for (int i = 1; i < n; i++) {
            dp[i] = min(min(dp[mul_2] * 2, dp[mul_3] * 3), dp[mul_5] * 5);
            if (dp[i] == dp[mul_2] * 2) {
                mul_2++;
            }
            if (dp[i] == dp[mul_3] * 3) {
                mul_3++;
            }
            if (dp[i] == dp[mul_5] * 5) {
                mul_5++;
            }
        }
        
        return dp[n-1];
    }
};
