class Solution {
public:
    vector<int> numsSameConsecDiff(int N, int K) {
        vector<int> result;
        if (N == 1) result.push_back(0);
        for (int i = 1; i < 10; i++) {
            int index = N - 1;
            getNum(index, K, i, 0, result);
        }
        return result;
    }
    
    void getNum(int index, int K, int num, int sum, vector<int>& result) {
        if (num > 9 || num < 0 || index < 0) return;
        if (index == 0) {
            result.push_back(sum + num);
            return;
        }
        getNum(index - 1, K, num + K, sum + pow(10, index) * num, result);
        if (K != 0) getNum(index - 1, K, num - K, sum + pow(10, index) * num, result);
    }
};
