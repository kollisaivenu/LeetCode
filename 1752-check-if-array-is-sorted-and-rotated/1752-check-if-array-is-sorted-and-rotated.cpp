class Solution {
public:
    bool check(vector<int>& nums) {
        bool decreasing = decreasing;
        int i=1;
        for(;i<nums.size();i++) {
            if(nums[i]>=nums[i-1]) {
                continue;
            } else {
                break;
            }
        }

        if(i == nums.size()) {
            return true;
        }
        i++;

        for(;i<nums.size();i++) {
            if(nums[i]>=nums[i-1]) {
                continue;
            } else {
                return false;
            }
        }
        if(nums[0] < nums[nums.size()-1]) {
            return false;
        }

        return true;
    }
};