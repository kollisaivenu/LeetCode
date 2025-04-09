class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int minNumber = INT_MAX;
        vector<int>freq(101, 0);
        for(int i=0;i<nums.size();i++){
            minNumber = min(minNumber, nums[i]);
            freq[nums[i]]++;
        }

        if(minNumber<k){
            return -1;
        }
        int ops = 0;
        for(int i=100;i>=0;i--){
            if(i>k && freq[i]>0){
                ops++;
            }
        }
        return ops;
    }
};