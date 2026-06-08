class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size()+2, vector<int>(2, INT_MIN));
        return recurse(0, true, prices, dp);
        
    }

    int recurse(int i, bool buy, vector<int>&prices, vector<vector<int>>&dp) {
        if(i >= prices.size()) {
            return 0;
        }
        int ans = INT_MIN;
        if(buy) {
            if (dp[i+1][0] == INT_MIN) {
                dp[i+1][0] =  recurse(i+1, false, prices, dp);
            }

            ans = max(ans, -prices[i] + dp[i+1][0]);

            if (dp[i+1][1] == INT_MIN) {
                dp[i+1][1] = recurse(i+1, buy, prices, dp);
            }

            ans = max(ans, dp[i+1][1]);
        } else {
            if(dp[i+2][1] == INT_MIN) {
                dp[i+2][1] =  recurse(i+2, true, prices, dp);
            }
            ans = max(ans, prices[i] + dp[i+2][1]);

            if(dp[i+1][0] == INT_MIN) {
                dp[i+1][0] = recurse(i+1, buy, prices, dp);
            }
            ans = max(ans, dp[i+1][0]);
        }
        if(buy) {
            dp[i][1] = ans;
        } else {
            dp[i][0] = ans;
        }
        return ans;
    }

};