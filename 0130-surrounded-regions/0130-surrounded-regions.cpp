class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();

        for(int i=0;i<rows;i++) {
            if(board[i][0] == 'O') {
                dfs(i, 0, board);
            }

            if(board[i][cols-1] == 'O') {
                dfs(i, cols-1, board);
            }   
        }

        for(int i=0;i<cols;i++) {
            if(board[0][i] == 'O') {
                dfs(0, i, board);
            }
            if(board[rows-1][i] == 'O') {
                dfs(rows-1, i, board);
            }
            
        }

        for(int i=0;i<rows;i++) {
            for(int j=0;j<cols;j++) {
                if(board[i][j] == '1') {
                    board[i][j] = 'O';
                } else if(board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }

    void dfs(int i, int j, vector<vector<char>>& board) {
        board[i][j] = '1';
        int rows = board.size();
        int cols = board[0].size();

        if(i-1 >= 0 && board[i-1][j] == 'O') {
            dfs(i-1, j, board);
        }

        if(i+1 < rows && board[i+1][j] == 'O') {
            dfs(i+1, j, board);
        }

        if(j-1 >= 0 && board[i][j-1] == 'O') {
            dfs(i, j-1, board);
        }

        if(j+1 < cols && board[i][j+1] == 'O') {
            dfs(i, j+1, board);
        }
    }
};