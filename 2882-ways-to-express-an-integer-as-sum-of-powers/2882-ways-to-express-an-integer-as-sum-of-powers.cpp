class Solution {
public:
    int numberOfWays(int n, int x) {
        vector<int>validNums;
        for(int i=1;pow(i, x)<=n;i++){
            validNums.push_back(binaryExponention(i, x));
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

    int binaryExponention(int a, int b){
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

    int recur(vector<int>&validNums, int index, int sum, int targetSum){
        if(targetSum == sum){
            return 1;
        }

        if(index >= validNums.size()){
            return 0;
        }

        return recur(validNums, index+1, sum, targetSum) + recur(validNums, index+1, sum+validNums[index], targetSum);
    }
};