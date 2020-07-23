class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> result(2, 0);
        int tmp = 0;
        
        for (auto num : nums) tmp ^= num;
        tmp = -tmp & tmp;
        
        for (auto num : nums) {
            if (tmp & num) result[0] ^= num;
            else result[1] ^= num;
        }
        
        return result;
    }
};
