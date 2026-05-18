class Solution {
public:
    bool checkValidString(string s) {
        vector<vector<int>>dp(s.length()+1, vector<int>(s.length()+1, -1));
        return check(0, s, 0, dp);   
    }

    bool check(int index, string &s, int count, vector<vector<int>>&dp) {
        if(index == s.length()) {
            if(count == 0) {
                return 1;
            } else {
                return 0;
            }
        }

        if(s[index] == '(') {
            if(dp[index+1][count+1] == -1) {
               dp[index+1][count+1] = check(index+1, s, count+1, dp);
            }
            return dp[index+1][count+1];
        } else if(s[index] == ')' && count > 0) {
            if(dp[index+1][count-1] == -1) {
               dp[index+1][count-1] = check(index+1, s, count-1, dp);
            }
            return dp[index+1][count-1];
        } else if(s[index] == '*') {
            bool ans = false;
            if(count > 0) {
                if(dp[index+1][count-1] == -1) {
                    dp[index+1][count-1] = check(index+1, s, count-1, dp);
                }
                ans = ans || dp[index+1][count-1];
            }
            if(dp[index+1][count] == -1) {
                dp[index+1][count] = check(index+1, s, count, dp);
            }
            if(dp[index+1][count+1] == -1) {
                dp[index+1][count+1] = check(index+1, s, count+1, dp);
            }
            ans = ans || dp[index+1][count] || dp[index+1][count+1];
            return ans;
        }

        return false;
    }
};