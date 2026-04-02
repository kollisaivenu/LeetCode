class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        vector<vector<vector<int>>>dp(coins.size(), vector<vector<int>>(coins[0].size(), vector<int>(3, INT_MIN)));
        int rows = coins.size()-1;
        int cols = coins[0].size()-1;
        for(int i=rows;i>=0;i--) {
            for(int j=cols;j>=0;j--) {
                for(int k=0;k<=2;k++) {
                    if(i == rows && j == cols) {
                        if(k > 0 && coins[i][j] < 0) {
                            dp[i][j][k] = 0;
                        } else {
                            dp[i][j][k] = coins[i][j];
                        }
                        continue;
                    }

                    if(i+1 <= rows) {
                        if(k > 0) {
                            dp[i][j][k] = max(dp[i][j][k], dp[i+1][j][k-1]);
                        }
                        dp[i][j][k] = max(dp[i][j][k], coins[i][j] + dp[i+1][j][k]);
                    }

                    if(j+1 <= cols) {
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

    int recur(int i, int j, int neutralize, vector<vector<int>>&coins) {
        int endX = coins.size()-1;
        int endY = coins[0].size()-1;

        if(i == endX && j == endY) {
            if(neutralize > 0 && coins[i][j] < 0) {
                return 0;
            }
            return coins[i][j];
        }

        int maxAmount = INT_MIN;

        if(i+1 <= endX) {
            if(neutralize > 0) {
                maxAmount = max(maxAmount, recur(i+1, j, neutralize-1, coins));
            }

            maxAmount = max(maxAmount, coins[i][j] + recur(i+1, j, neutralize, coins));
        }

        if(j+1 <= endY) {
            if(neutralize > 0) {
                maxAmount = max(maxAmount, recur(i, j+1, neutralize-1, coins));
            }

            maxAmount = max(maxAmount, coins[i][j] + recur(i, j+1, neutralize, coins));
        }

        return maxAmount;
    }
};