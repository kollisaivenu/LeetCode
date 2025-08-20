class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        vector<long long>dp(nums.size(), 0);

        for(int i=0;i<nums.size();i++){
            if(nums[i] == 0){
                if(i == 0){
                    dp[i] = 1;
                } else {
                    dp[i] = 1 + dp[i-1];
                }
            } else {
                dp[i] = 0;
            }
        }
        
        long long sum = 0;
        for(int i=0;i<nums.size();i++){
            sum += dp[i];
        }

        return sum;
    }
};