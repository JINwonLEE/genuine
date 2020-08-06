class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
        vector<int> result;
        for (auto num : nums) {
            int index = abs(num) - 1;
            if (nums[index] < 0) result.push_back(index + 1);
            else nums[index] *= -1;
        }
        return result;
    }
};
