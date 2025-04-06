class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>>dp(nums.size()+1, vector<int>(nums.size()+1, INT_MIN));

        for(int i=0;i<nums.size()+1;i++){
            dp[nums.size()][i] = 0;
        }

        for(int i=nums.size()-1;i>=0;i--){
            for(int j=nums.size()-1;j>=0;j--){
                if(j == 0){
                    dp[i][j] = max(dp[i][j], 1 + dp[i+1][i+1]);
                } else {
                    if(nums[i]%nums[j-1] == 0){
                        dp[i][j] = max(dp[i][j], 1 + dp[i+1][i+1]);
                    }
                }
                dp[i][j] = max(dp[i][j], dp[i+1][j]);
            }
        }
        vector<int>ans;
        int i=0,j=0;
        while(i<nums.size()){
            if(j == 0 && dp[i+1][i+1]+1 == dp[i][j]){
                ans.push_back(nums[i]);
                j=i+1;
                i++;
            } else if(j != 0 && nums[i]%nums[j-1] == 0 && dp[i+1][i+1]+1 == dp[i][j]){
                ans.push_back(nums[i]);
                j=i+1;
                i++;
            } else {
                i++;
            }
        }
        
        return ans;
    }
};