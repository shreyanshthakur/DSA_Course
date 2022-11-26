class Solution {
public:
    
    bool dfs (vector<vector<char>>& board, string &word, int i, int j, int k) {
        if (k == word.length()) 
            return true;
        
        if (i < 0 || i >= board.size() || j < 0 || j >= board[i].size() || board[i][j] != word[k]) return false;
        
        board[i][j] = '*';
        bool flag = dfs (board, word, i+1, j, k+1) || dfs(board, word, i, j+1, k+1) ||
            dfs(board, word, i-1, j, k+1) || dfs(board, word, i, j-1, k+1);
        board[i][j] = word[k];
        return flag;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++){
                if (board[i][j] == word[0] && dfs(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};