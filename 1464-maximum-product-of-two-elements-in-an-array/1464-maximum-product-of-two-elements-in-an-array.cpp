class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int idx = nums.size()-1;
        return (nums[idx]-1)*(nums[idx-1]-1);
        
    }
};