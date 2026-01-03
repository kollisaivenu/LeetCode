class Solution {
public:
    int numOfWays(int n) {
        vector<vector<vector<vector<long long>>>>dp(n+1, vector<vector<vector<long long>>>(4, vector<vector<long long>>(4, vector<long long>(4, -1))));
        long long ans = recur(0, 0, 0, 0, n, dp);
        return ans%1000000007;   
    }

    long long recur(int idx, int c1, int c2, int c3, int n, vector<vector<vector<vector<long long>>>>&dp) {
        if(idx == n) {
            return 1;
        }
        long long ans = 0;
        if(idx == 0) {
            for(int i=1;i<=3;i++){
                for(int j=1;j<=3;j++){
                    for(int k=1;k<=3;k++){
                        if(i !=j && j != k){
                            if (dp[idx+1][i][j][k] == -1) {
                                dp[idx+1][i][j][k] = recur(idx+1, i, j, k, n, dp)%1000000007;
                            }
                            ans = (ans%1000000007 + dp[idx+1][i][j][k])%1000000007;
                        }
                    }
                }
            }
        } else {
            for(int i=1;i<=3;i++){
                for(int j=1;j<=3;j++){
                    for(int k=1;k<=3;k++){
                        if(i != c1 && i != j && j != c2 && j != k && k != c3){
                            if (dp[idx+1][i][j][k] == -1) {
                                dp[idx+1][i][j][k] = recur(idx+1, i, j, k, n, dp)%1000000007;
                            }
                            ans = (ans%1000000007 + dp[idx+1][i][j][k])%1000000007;
                        }
                    }
                }
            }
        }

        return ans;
    }

    
};