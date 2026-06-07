class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>board(m, vector<int>(n, 0));
        board[0][0] = 1;

        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(i == 0 && j == 0) {
                    continue;
                } else if(i == 0) {
                    board[i][j] = board[i][j-1];
                } else if(j == 0) {
                    board[i][j] = board[i-1][j];
                } else {
                    board[i][j] = board[i-1][j] + board[i][j-1];
                }
            }
        }

        return board[m-1][n-1];
    }
};