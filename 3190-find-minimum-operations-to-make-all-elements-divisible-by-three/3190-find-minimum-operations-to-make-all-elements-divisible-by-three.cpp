class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ops = 0;
        for(int i=0;i<nums.size();i++){
            int remainder = nums[i]%3;
            ops += min(remainder, 3-remainder);
        }

        return ops;
    }
};