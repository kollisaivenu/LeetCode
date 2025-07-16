class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int max_length_of_lis = 1;
        vector<int> dp(nums.size(), 1);

        for (int i = 1; i<nums.size();i++){
            
            for (int j=0;j<i;j++){
                if (nums[i] > nums[j]){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }

            max_length_of_lis = max(max_length_of_lis, dp[i]);
            
        }
        return max_length_of_lis;
    }
};