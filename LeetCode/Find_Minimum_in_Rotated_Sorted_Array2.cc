class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        while (low < high) {
            int middle = low + (high - low) / 2;
            if (nums[low] > nums[middle]) {
                high = middle;
            } else if (nums[high] < nums[middle]) {
                low = middle + 1;
            } else {
                high--;
            }
        }
        return nums[low];
    }
};
