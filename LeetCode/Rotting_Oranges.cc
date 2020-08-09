class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        return helper(0, grid);
    }
    
    int helper(int minutes, vector<vector<int>>& grid) {
        bool change = false;
        bool is_fresh_exist = false;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) 
                if (grid[i][j] < 0) grid[i][j] *= -1;
        }
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    is_fresh_exist = true;
                    if ((i > 0 && grid[i-1][j] == 2) || (j > 0 && grid[i][j-1] == 2) 
                        || (i < grid.size() - 1 && grid[i+1][j] == 2) 
                        || (j < grid[0].size() - 1 && grid[i][j+1] == 2)) {
                        grid[i][j] *= -2;
                        is_fresh_exist = false;
                        change = true;
                        continue;
                    }
                }
            }
        }
        if (!change && is_fresh_exist) return -1;
        if (!change && !is_fresh_exist) return minutes;
        return helper(minutes + 1, grid);
    }
};
