typedef long long int lint;
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if (nums.size() < 3) return 0;
        int res = 0;
        unordered_map<lint, unordered_map<lint, lint>> dp;
        unordered_set<int> s(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 1; i < n; ++i) {
            for (int j = i - 1; j >= 0; --j) {
                lint diff = (lint)nums[i] - (lint)nums[j];
                lint tmp = dp[j].count(diff) ? dp[j][diff] : 0;
                res += tmp;
                if (s.count(nums[i] + diff)) dp[i][diff] += tmp + 1;
            }
        }
        return res;
    }
};
