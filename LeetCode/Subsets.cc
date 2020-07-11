class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        
        for (int i = 0; i < pow(2, nums.size()); i++) {
            vector<int> subset;
            for (int j = 0; j < nums.size(); j++) {
                if ((1 << j) & i) {
                    subset.push_back(nums[j]);
                }
            }
            result.push_back(subset);
        }
        return result;
    }
};
