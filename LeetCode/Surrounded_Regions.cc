class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.size() == 0) {
            return;
        }
        
        for (int i = 0; i < board.size(); i++) {
            check(board, i, 0);
            check(board, i, board[0].size() - 1);
        }
        
        for (int i = 1; i < board[0].size() - 1; i++) {
            check(board, 0, i);
            check(board, board.size() - 1, i);
        }
        
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == 'C') {
                    board[i][j] = 'O';
                } else {
                    board[i][j] = 'X';
                }
            }
        }
        
    }
    
    void check(vector<vector<char>>& board, int i, int j) {
        if (i < 0 || j < 0 || i > board.size() - 1 || 
            j > board[0].size() - 1 || board[i][j] != 'O') {
            return;
        }
        board[i][j] = 'C';
        check(board, i, j - 1);
        check(board, i - 1, j);
        check(board, i + 1, j);
        check(board, i, j + 1);
    }
};
