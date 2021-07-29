class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int max_num = 0;
        int count = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                count = 0;
            } else {
                count++;
            }
            if (count > max_num) max_num = count;
        }
        return max_num;
    }
};
