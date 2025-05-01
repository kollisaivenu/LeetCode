class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0, prefixSum = 0;
        unordered_map<int, int>freqOfSum;
        freqOfSum[0]++;

        for(int i=0;i<nums.size();i++){
            prefixSum += nums[i];
            count += freqOfSum[prefixSum-k];
            freqOfSum[prefixSum]++;
        }

        return count;
    }
};