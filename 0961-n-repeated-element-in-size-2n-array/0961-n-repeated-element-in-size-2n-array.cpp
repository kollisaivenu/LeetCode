class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = 1;
        for(;i<nums.size();i++) {
            if(nums[i] == nums[i-1]) {
                break;
            }
        }

        return nums[i];
    }
};