class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return recursion(0, nums, target, 0);
    }
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