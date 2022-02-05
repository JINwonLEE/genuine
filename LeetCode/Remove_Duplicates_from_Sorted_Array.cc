class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (!nums.size()) return 0;
        int tmp = nums[0];
        int index = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (tmp != nums[i]) {
                nums[index++] = nums[i];
                tmp = nums[i];
            }
        }
        return index;
    }
};
