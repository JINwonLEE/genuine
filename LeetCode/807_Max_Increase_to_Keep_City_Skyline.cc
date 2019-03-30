class Solution {
   public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int length_ = grid.size();
        vector<int> top_bottom;
        vector<int> right_left;
        top_bottom.reserve(length_);
        right_left.reserve(length_);
        for (int i = 0; i < length_; i++) {
            top_bottom[i] = -1;
            right_left[i] = -1;
        }

        for (int i = 0; i < length_; i++) {
            if (top_bottom[i] == -1) {
                int max = grid[0][i];
                for (int j = 0; j < length_; j++) {
                    if (max < grid[j][i]) {
                        max = grid[j][i];
                    }
                }
                top_bottom[i] = max;
            }
            if (right_left[i] == -1) {
                int max = grid[i][0];
                for (int j = 0; j < length_; j++) {
                    if (max < grid[i][j]) {
                        max = grid[i][j];
                    }
                }
                right_left[i] = max;
            }
        }
        int result = 0;
        for (int i = 0; i < length_; i++) {
            for (int j = 0; j < length_; j++) {
                if (std::min(top_bottom[j], right_left[i]) > grid[i][j]) {
                    result +=
                        std::min(top_bottom[j], right_left[i]) - grid[i][j];
                }
            }
        }
        return result;
    }
};
