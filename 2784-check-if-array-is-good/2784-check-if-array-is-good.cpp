class Solution {
public:
    bool isGood(vector<int>& nums) {
        unordered_map<int, int>freq;

        for(int i=0;i<nums.size();i++) {
            freq[nums[i]]++;
        }

        for(int i=1;i<=nums.size()-1;i++) {
            if(i != nums.size()-1 && freq[i] != 1) {
                return false;
            } else if(i == nums.size()-1 && freq[i] != 2) {
                return false;
            }
        }

        if(nums.size() == 1) {
            return false;
        }

        return true;
    }
};