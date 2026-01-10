class Solution {
public:
    long long maximumScore(vector<int>& nums) {
        vector<int>suffixMin(nums.size(), 0);
        suffixMin[nums.size()-1] = nums[nums.size()-1];
        for(int i=nums.size()-2;i>=0;i--) {
            suffixMin[i] = min(suffixMin[i+1], nums[i]);
        }

        long long sum = 0;
        long long ans = LLONG_MIN;
        for(int i=0;i<nums.size()-1;i++){
            sum += nums[i];
            if(sum - suffixMin[i+1] > ans) {
                ans = sum - suffixMin[i+1];
            }
            
        }

        return ans;
    }
};