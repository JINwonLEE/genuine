class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {        
        vector<vector<bool>> visit(board.size(), vector<bool>(board[0].size(), false));
        for (int i = 0;  i < board.size(); i++) {
            for (int j = 0 ; j < board[i].size(); j++) {
                if (findWord(board, i, j, word, 0, visit)) 
                    return true;
            }
        }
        return false;
    }
    
    bool findWord(const vector<vector<char>>& board, int i, int j,
                  const string& word, int pos, vector<vector<bool>>& visit) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() 
            || visit[i][j] || board[i][j] != word[pos]) return false;
        
        visit[i][j] = true;
        if (pos == word.size() - 1) {
            return true;
        }
        
        bool result = false;
        result |= findWord(board, i+1, j, word, pos + 1, visit);
        if (result) return result;
        result |= findWord(board, i-1, j, word, pos + 1, visit);
        if (result) return result;
        result |= findWord(board, i, j+1, word, pos + 1, visit);
        if (result) return result;
        result |= findWord(board, i, j-1, word, pos + 1, visit);
        visit[i][j] = false;
        
        return result;
    }
};
