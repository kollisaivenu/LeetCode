class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        map<pair<int, int>, int>dp;
        return recurse(0, nums, 0, target, dp);
    }

    int recurse(int i, vector<int>&nums, int curr_sum, int target, map<pair<int, int>, int>&dp) {
        if(i == nums.size()) {
            if(curr_sum == target) {
                return 1;
            } else {
                return 0;
            }
        }
        if(dp.contains({i, curr_sum})) {
            return dp[{i, curr_sum}];
        }
        int ans = 0;
        ans += recurse(i+1, nums, curr_sum + nums[i], target, dp);
        ans += recurse(i+1, nums, curr_sum - nums[i], target, dp);
        dp[{i, curr_sum}] = ans;
        return ans;
    }
};