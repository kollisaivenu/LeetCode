class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>>dp(text1.size()+1, vector<int>(text2.size()+1, -1));
        return recurrence(text1, text2, 0, 0, dp);
    }

    int recurrence(string &text1, string &text2, int i, int j, vector<vector<int>>&dp) {
        if(i >= text1.size() || j >= text2.size()) {
            return 0;
        }
        int ans = 0;
        if(text1[i] == text2[j]) {
            if (dp[i][j] == -1) {
                dp[i][j] = 1 + recurrence(text1, text2, i+1, j+1, dp);
            }
            ans = max(ans, dp[i][j]);
        }
        if(dp[i+1][j] == -1) {
            dp[i+1][j] = recurrence(text1, text2, i+1, j, dp);
        }

        ans = max(ans, dp[i+1][j]);

        if(dp[i][j+1] == -1) {
            dp[i][j+1] = recurrence(text1, text2, i, j+1, dp);
        }
        ans = max(ans, dp[i][j+1]);

        return ans;
    }
};