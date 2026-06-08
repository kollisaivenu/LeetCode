class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return recurse(0, nums, 0, target);
    }

    int recurse(int i, vector<int>&nums, int curr_sum, int target) {
        if(i == nums.size()) {
            if(curr_sum == target) {
                return 1;
            } else {
                return 0;
            }
        }

        int ans = 0;
        ans += recurse(i+1, nums, curr_sum + nums[i], target);
        ans += recurse(i+1, nums, curr_sum - nums[i], target);

        return ans;


    }
};