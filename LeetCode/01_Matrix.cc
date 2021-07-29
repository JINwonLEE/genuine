class Solution {
public:
    struct coord {
        int y, x;
    };

    
    bool isValid(int x, int y, int row, int col) {
        if (x < 0 || x >= row || y < 0 || y >= col) return false;
        return true;
    }
    
    int dirs[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int col = mat.size();
        int row = mat[0].size();
        queue<coord> q;
        vector<vector<bool>> visit(col, vector<bool>(row, false));
        for (int i = 0; i < col; i++) {
            for (int j = 0; j < row; j++) {
                if (!mat[i][j]) {
                    visit[i][j] = true;
                    q.push({i, j});
                }   
            }
        }
        
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int y = q.front().y;
                int x = q.front().x;
                q.pop();
                for (int* d : dirs) {
                    int c_y = d[0] + y;
                    int c_x = d[1] + x;
                    if (!isValid(c_x, c_y, row, col)) continue;
                    if (visit[c_y][c_x]) continue;
                    q.push({c_y, c_x});
                    visit[c_y][c_x] = true;
                    mat[c_y][c_x] = mat[y][x] + 1;
                }
            }
        }
        return mat;
    }
};
