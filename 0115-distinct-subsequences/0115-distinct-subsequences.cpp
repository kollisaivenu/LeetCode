class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<int>>dp(s.length()+1, vector<int>(t.length()+1, -1));
        int count = recursion(s, t, 0, 0, dp);
        return count;
    }

    int recursion(string &s, string &t, int i, int j, vector<vector<int>>&dp) {
        if(j == t.length()) {
            return 1;
        }

        if(i == s.length()) {
            return 0;
        }
        int ans = 0;
        if(s[i] == t[j]) {
            if(dp[i+1][j+1] == -1) {
                dp[i+1][j+1] = recursion(s, t, i+1, j+1, dp);
            }
            ans += dp[i+1][j+1]; 
        }
        if(dp[i+1][j] == -1) {
            dp[i+1][j] = recursion(s, t, i+1, j, dp);
        }
        ans += dp[i+1][j];
        return ans;
    }


};