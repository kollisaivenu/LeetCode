class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        map<int, bool>m;

        for(int i=0;i<nums.size();i++){
            m[nums[i]] = true;
        }

        while(m[original]) {
            original = original*2;
        }

        return original;
    }
};