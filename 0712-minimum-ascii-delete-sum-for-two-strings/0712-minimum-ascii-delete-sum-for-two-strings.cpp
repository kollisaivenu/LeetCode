class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        vector<vector<int>>dp(s1.length()+1, vector<int>(s2.length()+1, -1));
        return recur(s1, s2, 0, 0, dp);
        
    }

    int recur(string &s1, string &s2, int i, int j, vector<vector<int>>&dp){
        if(i == s1.length()) {
            int to_delete = 0;
            for(int k=j;k<s2.length();k++) {
                to_delete += (int)s2[k];
            }
            return to_delete;
        }

        if(j == s2.length()) {
            int to_delete = 0;
            for(int k=i;k<s1.length();k++) {
                to_delete += (int)s1[k];
            }
            return to_delete;
        }

        int ans = INT_MAX;

        if(s1[i] == s2[j]) {
            if(dp[i+1][j+1] == -1) {
                dp[i+1][j+1] = recur(s1, s2, i+1, j+1, dp);
            }
            ans = min(ans, dp[i+1][j+1]);
        }
        
        if(dp[i+1][j] == -1) {
            dp[i+1][j] = recur(s1, s2, i+1, j, dp);
        }
        ans = min(ans, (int)s1[i] + dp[i+1][j]);

        if(dp[i][j+1] == -1) {
            dp[i][j+1] = recur(s1, s2, i, j+1, dp);
        }
        ans = min(ans, (int)s2[j] + dp[i][j+1]);

        return ans;
    }
};