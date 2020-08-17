class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        std::ios::sync_with_stdio(false);std::cin.tie(nullptr);
        vector<int> result(num_people, 0);
        int index = 0;
        while (index < candies) {
            result[(index) % num_people] += index + 1;
            candies -= index++ + 1;
        }
        if (candies != 0) result[index % num_people] += candies;
        return result;
    }
};
