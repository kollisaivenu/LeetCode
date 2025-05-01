class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        vector<int>prefixSum(nums.size(), 0);
        prefixSum[0] = nums[0];
        unordered_map<int, int>freqOfSum;
        freqOfSum[0]++;

        for(int i=1;i<nums.size();i++){
            prefixSum[i] = prefixSum[i-1] + nums[i];
        }

        for(int i=0;i<prefixSum.size();i++){
            count += freqOfSum[prefixSum[i]-k];
            freqOfSum[prefixSum[i]]++;
        }

        return count;
    }
};