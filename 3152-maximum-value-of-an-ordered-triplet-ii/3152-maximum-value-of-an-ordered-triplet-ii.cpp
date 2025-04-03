class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long maxI = nums[0], maxValue = 0, maxK = nums[nums.size()-1];
        vector<long long>prefix(nums.size(), 0);
        prefix[0] = 0;

        for(int i=1;i<nums.size();i++){
            prefix[i] = max(0LL, maxI-nums[i]);
            maxI = max(maxI, (long long)nums[i]);
        }

        for(int i=nums.size()-2;i>=0;i--){
            maxValue = max(prefix[i]*maxK, maxValue);
            maxK = max(maxK, (long long)nums[i]);
        }

        return maxValue;
    }
};