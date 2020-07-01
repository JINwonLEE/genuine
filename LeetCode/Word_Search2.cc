class Solution {
public:
    int row;
    int col;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> result;
        row = board.size();
        col = board[0].size();
        
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < row; j++) {
                for (int k = 0; k < col; k++) {
                    if (board[j][k] == words[i][0]) {
                        dfs(board, j, k, words[i], 0, result);                        
                    }   
                }
            }
        }
        
        return result;
    }
    
        
    void dfs(vector<vector<char>>& board, int x, int y, 
             const string& word, int pos, vector<string>& result) {
        if (x < 0 || y < 0 || x >= row || y >= col) {
            return;
        }
        
        if (board[x][y] == word[pos]) {
            if (word.size() == pos + 1
                && find(result.begin(), result.end(), word) == result.end()) {
                result.push_back(word);
                return;
            }
            
            char temp = board[x][y];
            board[x][y] = '-';
            
            dfs(board, x+1, y, word, pos + 1, result);
            dfs(board, x-1, y, word, pos + 1, result);
            dfs(board, x, y+1, word, pos + 1, result);
            dfs(board, x, y-1, word, pos + 1, result);
            
            board[x][y] = temp;
        }
    }
    
};
