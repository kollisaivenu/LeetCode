class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        vector<vector<vector<int>>>dp(coins.size(), vector<vector<int>>(coins[0].size(), vector<int>(3, INT_MIN)));
        int rows = coins.size();
        int cols = coins[0].size();
        for(int i=rows-1;i>=0;i--) {
            for(int j=cols-1;j>=0;j--) {
                for(int k=0;k<=2;k++) {
                    if(i == rows-1 && j == cols-1) {
                        if(k > 0 && coins[i][j] < 0) {
                            dp[i][j][k] = 0;
                        } else {
                            dp[i][j][k] = coins[i][j];
                        }
                        continue;
                    }

                    if(i+1 <= rows-1) {
                        if(k > 0) {
                            dp[i][j][k] = max(dp[i][j][k], dp[i+1][j][k-1]);
                        }
                        dp[i][j][k] = max(dp[i][j][k], coins[i][j] + dp[i+1][j][k]);
                    }

                    if(j+1 <= cols-1) {
                        if(k > 0) {
                            dp[i][j][k] = max(dp[i][j][k], dp[i][j+1][k-1]);
                        }
                        dp[i][j][k] = max(dp[i][j][k], coins[i][j] + dp[i][j+1][k]);
                    }
                }
            }
        }
        return dp[0][0][2];
    }
};