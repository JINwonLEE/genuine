class Solution {
public:
    
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        int res = 0;
        vector<vector<int>> m(n, vector<int>(n, 1));
        
        for (auto ele : mines) m[ele[0]][ele[1]] = 0;
        
        for (int i = 0; i < n; ++i) {
            int count = 1;
            for (int j = 0;  j < n; ++j) {
                if (m[i][j]) m[i][j] = count++;
                else count = 1;
            }
            
            count = 1;
            for (int j = n-1; j >= 0; --j) {
                if (m[i][j]) m[i][j] = min(m[i][j], count++);
                else count = 1;
            }
        }
        
        for (int i = 0; i < n; ++i) {
            int count = 1;
            for (int j = 0; j < n; ++j) {
                if (m[j][i]) m[j][i] = min(m[j][i], count++);
                else count = 1;
            }
            
            count = 1;
            for (int j = n-1; j >= 0; --j) {
                if (m[j][i]) {
                    m[j][i] = min(m[j][i], count++);
                    res = max(res, m[j][i]);
                } else count = 1;
            }
        }
        
        return res;
    }
};
