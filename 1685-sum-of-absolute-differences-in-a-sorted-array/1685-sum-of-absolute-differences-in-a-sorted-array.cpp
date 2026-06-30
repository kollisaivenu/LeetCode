class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int left = 0;
        int right = 0;
        for(int i=0;i<nums.size();i++) {
            right += nums[i];
        }
        
        vector<int>ans(nums.size(), 0);
        for(int i=0;i<nums.size();i++) {
            right -= nums[i];
            ans[i] = (((i-0)*nums[i] - left) + (right - (nums.size()-1-i)*nums[i]));
            left += nums[i];
        }

        return ans;
    }
};