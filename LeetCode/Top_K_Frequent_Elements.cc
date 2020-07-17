typedef pair<int, int> pair_;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<int> result;
        vector<pair_> sorted_element;
        int index = 0;
        while (index < nums.size()) {
            int num = nums[index++];
            int count = 1;
            while (index < nums.size() && num == nums[index]) {
                index++;
                count++;
            }
            sorted_element.push_back(pair<int, int>(num, count));
        }

        sort(sorted_element.begin(), sorted_element.end(), [] (const pair_& a, const pair_& b) {
            return a.second > b.second; 
        });
        
        int count = 0;
        while (k--) result.push_back(sorted_element[count++].first);
        
        return result;
    }
};
