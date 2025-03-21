class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return recursion(0, nums, target, 0);
    }
    //     vector<vector<int>>dp(nums.size()+1, vector<int>(target+1, 0));

    //     for(int i=nums.size();i>=0;i--){
    //         for(int j=target;j>=0;j--){
    //             if(i == nums.size()){
    //                 if(j == target){
    //                     dp[i][j] = 1;
    //                 } else {
    //                     dp[i][j] = 0;
    //                 }
    //                 break;
    //             }
    //             if(j+nums[i]<=target){
    //                 dp[i][j] += dp[i+1][j+nums[i]]; 
    //             }
    //             if(j-nums[i]>=0){
    //                 dp[i][j] += dp[i+1][j-nums[i]];
    //             }
    //         }
    //     }

    //     return dp[0][0];
        
    // }

    int recursion(int i, vector<int>&nums, int target, int curr_sum){
        int ans = 0;
        if(i >= nums.size()){
            if(curr_sum == target){
                return 1;
            }
            return 0;
        }

        ans = recursion(i+1, nums, target, curr_sum + nums[i]) + recursion(i+1, nums, target, curr_sum - nums[i]);
        return ans;
    }
};