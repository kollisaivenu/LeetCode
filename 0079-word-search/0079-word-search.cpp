class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();
        int index = 0;
        bool ans = false;
        for(int i=0;i<rows;i++) {
            for(int j=0;j<cols;j++) {
                if(board[i][j] == word[index]) {
                    vector<vector<bool>>vis(rows, vector<bool>(cols, false));
                    vis[i][j] = true;
                    ans = ans | wordExists(index+1, i, j, board, word, vis);
                }
            }
        }
        
        return ans;
    }

    bool wordExists(int index, int x, int y, vector<vector<char>>& board, string &word, vector<vector<bool>>&vis) {
        if(index == word.length()) {
            return true;
        }

        int rows = board.size();
        int cols = board[0].size();
        bool ans = false;
        if(x-1 >= 0 && board[x-1][y] == word[index] && vis[x-1][y] == false) {
            vis[x-1][y] = true;
            ans = ans | wordExists(index+1, x-1, y, board, word, vis);
            vis[x-1][y] = false;
        }

        if(x+1 < rows && board[x+1][y] == word[index] && vis[x+1][y] == false) {
            vis[x+1][y] = true;
            ans = ans | wordExists(index+1, x+1, y, board, word, vis);
            vis[x+1][y] = false;
        }

        if(y-1 >= 0 && board[x][y-1] == word[index] && vis[x][y-1] == false) {
            vis[x][y-1] = true;
            ans = ans | wordExists(index+1, x, y-1, board, word, vis);
            vis[x][y-1] = false;
        }

        if(y+1 < cols && board[x][y+1] == word[index] && vis[x][y+1] == false) {
            vis[x][y+1] = true;
            ans = ans | wordExists(index+1, x, y+1, board, word, vis);
            vis[x][y+1] = false;
        }

        return ans;
    }
};