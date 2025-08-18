class Solution {
public:
    int numberOfWays(int n, int x) {
        vector<int>validNums;
        int i = 1;
        int validNum = binaryExponentation(1, x);

        while(validNum <= n){
            validNums.push_back(validNum);
            validNum = binaryExponentation(++i, x);
        }

        vector<vector<long long>>dp(validNums.size()+1, vector<long long>(n+1, 0));

        for(int i=validNums.size();i>=0;i--){
            for(int j=n;j>=0;j--){
                if(j == n){
                    dp[i][j] = 1;
                    continue;
                }

                if(i >= validNums.size()){
                    dp[i][j] = 0;
                    continue;
                }

                if(j+validNums[i] <= n) {
                    dp[i][j] = dp[i+1][j] + dp[i+1][j+validNums[i]];
                }
            }
        }
        return dp[0][0]%1000000007;
    }

    int binaryExponentation(int a, int b){
        int res = 1;

        while(b > 0){
            if(b%2 == 1){
                res = res*a;
            }
            a = a*a;
            b = b/2;
        }

        return res;
    }
};