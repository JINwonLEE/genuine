class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        set<vector<int>> tmp_result;
        sort(nums.begin(), nums.end());
        int len = nums.size();
        for (int i = 0; i < len - 1; i++) {
            if (i > 0 && nums[i-1] == nums[i]) continue;
            int k = i + 1;
            int j = len - 1;
            while (k < j) {
                if (nums[i] + nums[k] + nums[j] == 0) {
                    tmp_result.insert(vector<int>{nums[i], nums[j], nums[k]});
                    k++;j--;
                } else  if (nums[i] + nums[k] > -1 * nums[j]) {
                    j--;
                } else if (nums[i] + nums[k] < -1 * nums[j]) {
                    k++;
                }
            }
        }
        
        for (auto it = tmp_result.begin(); it != tmp_result.end(); it++) {
            result.push_back(*it);
        }
        
        return result;
    }
};
