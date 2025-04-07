class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for(int i=0;i<nums.size();i++){
            totalSum += nums[i];
        }
        if(totalSum%2 == 1){
            return false;
        }
        vector<vector<bool>>dp(nums.size()+1, vector<bool>(totalSum+1, false));
        dp[nums.size()][totalSum/2] = true;
        
        for(int i=nums.size()-1;i>=0;i--){
            for(int j=totalSum;j>=0;j--){
                if(j+nums[i]<=totalSum){
                    dp[i][j] = dp[i][j] || dp[i+1][j+nums[i]];
                }
                dp[i][j] = dp[i][j] || dp[i+1][j]; 
            }
        }
        return dp[0][0];

    }
};