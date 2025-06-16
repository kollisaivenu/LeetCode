class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int smallestNum = nums[0], maxDiff = -1;
        
        for(int i=1;i<nums.size();i++){
            if(nums[i] > smallestNum){
                maxDiff = max(maxDiff, nums[i] - smallestNum);
            }

            smallestNum = min(smallestNum, nums[i]);
        }

        return maxDiff;
        
    }
};