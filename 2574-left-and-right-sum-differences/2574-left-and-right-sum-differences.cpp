class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int sum = 0;
        vector<int>ans(nums.size(), 0);
        for(int i=0;i<nums.size();i++) {
            sum += nums[i];
        }
        int lsum = 0;
        for(int i=0;i<nums.size();i++) {
            int left = lsum;
            int right = sum - lsum - nums[i];
            ans[i] = abs(left - right);
            lsum += nums[i];
        }

        return ans;
        
    }
};