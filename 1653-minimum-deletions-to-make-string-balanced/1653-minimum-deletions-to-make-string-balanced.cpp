class Solution {
public:
    int minimumDeletions(string s) {
        vector<vector<int>>dp(s.length()+1, vector<int>(2, INT_MAX));
        dp[s.length()][0] = 0;
        dp[s.length()][1] = 0;

        for(int i=s.length()-1;i>=0;i--){
            for(int j=0;j<2;j++){
                if(s[i] == 'a' && j == 0){
                    dp[i][j] = min(dp[i][j], dp[i+1][j]);
                } else if(s[i] == 'a' && j == 1){
                    dp[i][j] = min(dp[i][j], 1+dp[i+1][j]);
                } else if(s[i] == 'b' && j == 0){
                    dp[i][j] = min(dp[i][j], 1+dp[i+1][j]);
                    dp[i][j] = min(dp[i][j], dp[i+1][1]);
                }else if(s[i] == 'b' && j == true){
                    dp[i][j] = min(dp[i][j], dp[i+1][j]);
                }
            }
        }
        return dp[0][0];
    }
    int recur(string s, int i, bool seenB){
        if(i>=s.length()){
            return 0;
        }
        int ans = INT_MAX;
        if(s[i] == 'a' && seenB == false){
            ans = min(ans, recur(s, i+1, seenB));
        } else if(s[i] == 'a' && seenB == true){
            ans = min(ans, 1+recur(s, i+1, seenB));
        } else if(s[i] == 'b' && seenB == false){
            ans = min(ans, 1+recur(s, i+1, seenB));
            ans = min(ans, recur(s, i+1, true));
        }else if(s[i] == 'b' && seenB == true){
            ans = min(ans, recur(s, i+1, seenB));
        }
        return ans;
    }
};