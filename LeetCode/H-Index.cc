class Solution {
public:
    int hIndex(vector<int>& citations) {
        std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
        sort(citations.begin(), citations.end(), greater<int>());
        for (int i = 0; i < citations.size(); i++) {
            if (i >= citations[i]) return i;
        }
        return citations.size();
    }
};
