class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();

        vector<vector<int>>dp(row, vector<int>(col, 0));
        int ans = 0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(matrix[i][j] == 0){
                    dp[i][j] = 0;
                } else if(matrix[i][j] == 1){
                    if(i>=1 && j >= 1){
                        dp[i][j] = 1 + min(dp[i][j-1], min(dp[i-1][j-1], dp[i-1][j]));
                    } else {
                        dp[i][j] = 1;
                    }
                }
                ans += dp[i][j];
            }
        }
        return ans;
    }
};