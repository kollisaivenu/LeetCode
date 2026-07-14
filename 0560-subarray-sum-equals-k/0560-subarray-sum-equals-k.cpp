class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int prefixSum = 0;
        unordered_map<int, int>freq;
        freq[0] = 1;
        int ans = 0;
        for(int i=0;i<nums.size();i++) {
            prefixSum += nums[i];
            ans += freq[prefixSum - k];
            freq[prefixSum]++;
        }

        return ans;
    }
};