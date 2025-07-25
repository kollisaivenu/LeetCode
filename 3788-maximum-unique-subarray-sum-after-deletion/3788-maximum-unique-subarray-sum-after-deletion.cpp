class Solution {
public:
    int maxSum(vector<int>& nums) {
        map<int, bool>freq;
        int largestNegNumber = INT_MIN;
        int isZeroPresent = false;
        for(int i=0;i<nums.size();i++){
            freq[nums[i]] = true;

            if(nums[i] < 0){
                largestNegNumber = max(largestNegNumber, nums[i]);
            }

            if(nums[i] == 0){
                isZeroPresent = true;
            }

        }

        int sum = 0;

        for(int i=0;i<nums.size();i++){
            if(nums[i] > 0 && freq[nums[i]]){
                sum += nums[i];
                freq[nums[i]] = false;
            }
        }

        if(sum == 0 && !isZeroPresent){
            sum += largestNegNumber;
        }

        return sum;
    }
};