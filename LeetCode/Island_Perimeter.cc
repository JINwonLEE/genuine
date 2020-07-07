class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int sum = 0;
        int wid = grid[0].size();
        int col = grid.size();
        for (int i = 0; i < col; i++) {
            for (int j = 0; j < wid; j++) {
                if (grid[i][j]) {
                    sum += 4;
                    if (i != 0 && grid[i-1][j]) sum -= 1;
                    if (i < col - 1 && grid[i+1][j]) sum -= 1;
                    if (j != 0 && grid[i][j-1]) sum -= 1;
                    if (j < wid - 1 && grid[i][j+1]) sum -= 1;
                }
            }
        }
        return sum;
    }
    
};
